#include "PauseMenu.hpp"

#include "src/data/Globals.hpp"
#include "src/omicron/Omicron.hpp"
#include "src/omicron/input/Input.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PauseMenu::PauseMenu()
    :
    m_currentMenu ( TYPE_MAIN ),
    m_escDown     ( false ),
    m_overlay     ( NULL ),
    m_currentIndex( 0 )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PauseMenu::init()
{
    initComponents();
}

void PauseMenu::update()
{
    // check for escape key press
    if ( omi::input::isKeyPressed( omi::input::key::ESCAPE ) && !m_escDown )
    {
        m_escDown = true;

        // if currently in-game, pause and bring up the menu
        if ( !global::pause )
        {
            global::pause = true;
        }
        else
        {
            // TODO:back menu
            global::pause = false;
        }

        // update the state of the menu
        updateMenuState();
    }
    // check for escape key release
    else if ( !omi::input::isKeyPressed( omi::input::key::ESCAPE ) &&
               m_escDown                                               )
    {
        m_escDown = false;
    }

    // update menu logic
    if ( global::pause )
    {
        updateMenuLogic();
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PauseMenu::updateMenuState()
{
    // hide everything to start with
    hideAll();

    if ( global::pause )
    {
        // show overlay
        m_overlay->visible = true;

        // reset selected item index
        m_currentIndex = 0;

        // set and show the current items
        switch( m_currentMenu )
        {
            case TYPE_MAIN:
            {
                m_currentItems = m_mainText;
                setTextListVisibility( m_mainText, true );
                break;
            }
        }
    }
}

void PauseMenu::updateMenuLogic()
{
    // update colour
}

void PauseMenu::setItemColours()
{
    // reset to unselected first
    for ( std::vector<omi::Text*>::iterator it = m_currentItems.begin();
          it != m_currentItems.end(); ++it )
    {
        ( *it )->getMaterial().colour = global::MENU_ITEM_NON_SELECTED_COLOUR;
    }

    // colour the selected item
    m_currentItems[ m_currentIndex ]->getMaterial().colour =
            global::MENU_ITEM_SELECTED_COLOUR;
}

//----------------------------------VISIBILITY----------------------------------

void PauseMenu::hideAll()
{
    m_overlay->visible = false;
    setTextListVisibility( m_mainText, false );
}


void PauseMenu::setTextListVisibility(
        std::vector<omi::Text*>& textList, bool visible )
{
    for ( std::vector<omi::Text*>::iterator it = textList.begin();
          it != textList.end();
          ++it )
    {
        ( *it )->visible = visible;
    }
}


//--------------------------------INITIALISATION--------------------------------

void PauseMenu::initComponents()
{
    m_overlay = omi::ResourceManager::getSprite(
            "pause_menu_overlay",
            "",
            NULL
    );
    m_overlay->gui = true;
    m_overlay->visible = false;
    m_components.add( m_overlay );

    initMainMenuComponents();
}

void PauseMenu::initMainMenuComponents()
{
    // resume text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.25f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    text->gui = true;
    text->setString( "Resume" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_mainText.push_back( text );

    }

    // settings text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    text->gui = true;
    text->setString( "Settings" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_mainText.push_back( text );

    }

    // exit text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, -0.25f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    text->gui = true;
    text->setString( "Exit" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_mainText.push_back( text );

    }
}
