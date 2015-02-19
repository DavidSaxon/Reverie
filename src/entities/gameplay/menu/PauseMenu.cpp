#include "PauseMenu.hpp"

#include "src/omicron/input/Input.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PauseMenu::PauseMenu()
    :
    m_active      ( false ),
    m_escDown     ( false ),
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
    // TODO: background

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
        m_escDown = true;
        m_active = !m_active;
        show( m_active );
    }
    // check for escape key release
    else if ( m_escDown                                            &&
              !omi::input::isKeyPressed( omi::input::key::ESCAPE )    )
    {
        m_escDown = false;
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PauseMenu::show( bool state )
{
    m_resumeText->  visible = state;
    m_settingsText->visible = state;
    m_exitText->    visible = state;
}
