#include "PauseMenu.hpp"

#include "src/data/Globals.hpp"
#include "src/omicron/Omicron.hpp"
#include "src/omicron/input/Input.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PauseMenu::PauseMenu()
    :
    m_active      ( false ),
    m_mainMenuItem( MAIN_RESUME ),
    m_escDown     ( false ),
    m_arrowDown   ( false ),
    m_overlay     ( NULL ),
    m_resumeText  ( NULL ),
    m_settingsText( NULL ),
    m_exitText    ( NULL )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PauseMenu::init()
{
    // overlay background
    m_overlay = omi::ResourceManager::getSprite(
            "pause_menu_overlay",
            "",
            NULL
    );
    m_overlay->gui = true;
    m_overlay->visible = false;
    m_components.add( m_overlay );

    // resume text
    omi::Transform* textT1 = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.25f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( textT1 );
    m_resumeText =
            omi::ResourceManager::getText( "pause_main_item_text", "", textT1 );
    m_resumeText->gui = true;
    m_resumeText->setString( "Resume" );
    m_resumeText->setHorCentred( true );
    m_resumeText->setVertCentred( true );
    m_resumeText->visible = false;
    m_components.add( m_resumeText );

    // settings text
    omi::Transform* textT2 = new omi::Transform(
            "",
            glm::vec3(),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( textT2 );
    m_settingsText =
            omi::ResourceManager::getText( "pause_main_item_text", "", textT2 );
    m_settingsText->gui = true;
    m_settingsText->setString( "Settings" );
    m_settingsText->setHorCentred( true );
    m_settingsText->setVertCentred( true );
    m_settingsText->visible = false;
    m_components.add( m_settingsText );

    // exit text
    omi::Transform* textT3 = new omi::Transform(
            "",
            glm::vec3( 0.0f, -0.25f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( textT3 );
    m_exitText =
            omi::ResourceManager::getText( "pause_main_item_text", "", textT3 );
    m_exitText->gui = true;
    m_exitText->setString( "Exit" );
    m_exitText->setHorCentred( true );
    m_exitText->setVertCentred( true );
    m_exitText->visible = false;
    m_components.add( m_exitText );
}

void PauseMenu::update()
{
    // check for escape key press
    if ( omi::input::isKeyPressed( omi::input::key::ESCAPE ) && !m_escDown )
    {
        // set states
        m_escDown = true;
        m_active = !m_active;
        global::pause = m_active;

        // update the UI
        show( m_active );
    }
    // check for escape key release
    else if ( !omi::input::isKeyPressed( omi::input::key::ESCAPE ) &&
               m_escDown                                               )
    {
        m_escDown = false;
    }

    // only do menu logic if we're paused
    if ( m_active )
    {
        updateMenu();
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PauseMenu::show( bool state )
{
    m_overlay->     visible = state;
    m_resumeText->  visible = state;
    m_settingsText->visible = state;
    m_exitText->    visible = state;
}

void PauseMenu::updateMenu()
{
    // move selection
    int mainMenuItemInt = static_cast<int>( m_mainMenuItem );
    if ( omi::input::isKeyPressed( omi::input::key::DOWN ) && !m_arrowDown )
    {
        m_arrowDown = true;
        ++mainMenuItemInt;
    }
    else if ( omi::input::isKeyPressed( omi::input::key::UP ) && !m_arrowDown )
    {
        m_arrowDown = true;
        --mainMenuItemInt;
    }
    else if ( !omi::input::isKeyPressed( omi::input::key::UP )   &&
              !omi::input::isKeyPressed( omi::input::key::DOWN ) &&
               m_arrowDown                                          )
    {
        m_arrowDown = false;
    }

    // work out the new selection
    int itemCount = static_cast<int>( MAIN_COUNT );
    if ( mainMenuItemInt < 0 )
    {
        mainMenuItemInt = itemCount - 1;
    }
    else if ( mainMenuItemInt >= itemCount )
    {
        mainMenuItemInt = 0;
    }
    m_mainMenuItem = static_cast<MainMenuItem>( mainMenuItemInt );

    // update selection colour
    m_resumeText->getMaterial().colour =
            global::MENU_ITEM_NON_SELECTED_COLOUR;
    m_settingsText->getMaterial().colour =
            global::MENU_ITEM_NON_SELECTED_COLOUR;
    m_exitText->getMaterial().colour =
            global::MENU_ITEM_NON_SELECTED_COLOUR;

    if ( m_mainMenuItem == MAIN_RESUME )
    {
        m_resumeText->getMaterial().colour =
                global::MENU_ITEM_SELECTED_COLOUR;
    }
    else if ( m_mainMenuItem == MAIN_SETTINGS )
    {
        m_settingsText->getMaterial().colour =
                global::MENU_ITEM_SELECTED_COLOUR;
    }
    else
    {
        m_exitText->getMaterial().colour =
                global::MENU_ITEM_SELECTED_COLOUR;
    }

    // perform action
    if ( omi::input::isKeyPressed( omi::input::key::RETURN ) )
    {
        if ( m_mainMenuItem == MAIN_RESUME )
        {
            // TODO: make a function for this
            m_active = !m_active;
            global::pause = m_active;
            // update the UI
            show( m_active );
        }
        else if ( m_mainMenuItem == MAIN_SETTINGS )
        {
            // TODO:
        }
        else
        {
            // TODO: are you sure?
            omi::omi_running = false;
        }
    }
}
