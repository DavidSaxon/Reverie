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
    m_arrowDown   ( false ),
    m_acceptDown  ( false ),
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
            m_currentMenu = TYPE_MAIN;
        }
        else
        {
            back();
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

void PauseMenu::updateMenuLogic()
{
    // check for move selection key presses
    if ( omi::input::isKeyPressed( omi::input::key::DOWN ) && !m_arrowDown )
    {
        m_arrowDown = true;
        ++m_currentIndex;
    }
    else if ( omi::input::isKeyPressed( omi::input::key::UP ) && !m_arrowDown )
    {
        m_arrowDown = true;
        --m_currentIndex;
    }
    else if ( !omi::input::isKeyPressed( omi::input::key::UP )   &&
              !omi::input::isKeyPressed( omi::input::key::DOWN ) &&
               m_arrowDown                                          )
    {
        m_arrowDown = false;
    }

    // clamp the index
    if ( m_currentIndex < 0 )
    {
        m_currentIndex = m_currentItems.size() - 1;
    }
    else if ( m_currentIndex >= static_cast<int>( m_currentItems.size() ) )
    {
        m_currentIndex = 0;
    }

    // check for accept key
    if ( omi::input::isKeyPressed( omi::input::key::RETURN ) && !m_acceptDown )
    {
        m_acceptDown = true;
        accept();
    }
    else if ( !omi::input::isKeyPressed( omi::input::key::RETURN ) &&
               m_acceptDown                                           )
    {
        m_acceptDown = false;
    }

    // update colour
    setItemColours();
    setWidgetColours();
}

void PauseMenu::back()
{
    switch ( m_currentMenu )
    {
        case TYPE_MAIN:
        {
            global::pause = false;
            break;
        }
        case TYPE_EXIT:
        {
            m_currentMenu = TYPE_MAIN;
            break;
        }
        case TYPE_SETTINGS:
        {
            m_currentMenu = TYPE_MAIN;
            break;
        }
        case TYPE_GRAPHICS_SETTINGS:
        {
            m_currentMenu = TYPE_SETTINGS;
            break;
        }
        case TYPE_AUDIO_SETTINGS:
        {
            m_currentMenu = TYPE_SETTINGS;
            break;
        }
        case TYPE_INPUT_SETTINGS:
        {
            m_currentMenu = TYPE_SETTINGS;
            break;
        }
    }
}

void PauseMenu::setItemColours()
{
    // reset to unselected first
    for ( std::vector<omi::Text*>::iterator it = m_currentItems.begin();
          it != m_currentItems.end();
          ++it )
    {
        ( *it )->getMaterial().colour = global::MENU_ITEM_NON_SELECTED_COLOUR;
    }

    // colour the selected item
    m_currentItems[ m_currentIndex ]->getMaterial().colour =
            global::MENU_ITEM_SELECTED_COLOUR;
}

void PauseMenu::setWidgetColours()
{
    // reset to non-active first
    for ( std::vector<SettingWidget*>::iterator it = m_currentWidgets.begin();
          it != m_currentWidgets.end();
          ++it )
    {
        ( *it )->setActive( false );
    }

    // activate the selected widget
    if ( m_currentIndex < static_cast<int>( m_currentWidgets.size() ) )
    {
        m_currentWidgets[ m_currentIndex ]->setActive( true );
    }
}

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
                m_currentWidgets.clear();
                setTextListVisibility( m_mainText, true );
                break;
            }
            case TYPE_EXIT:
            {
                m_exitCheckText->visible = true;
                m_currentItems = m_exitText;
                m_currentWidgets.clear();
                setTextListVisibility( m_exitText, true );
                break;
            }
            case TYPE_SETTINGS:
            {
                m_currentItems = m_settingsText;
                m_currentWidgets.clear();
                setTextListVisibility( m_settingsText, true );
                break;
            }
            case TYPE_GRAPHICS_SETTINGS:
            {
                m_currentItems = m_graphicsText;
                m_currentWidgets = m_graphicsWidgets;
                setTextListVisibility( m_graphicsText, true );
                setWidgetVisibility( m_graphicsWidgets, true );
                break;
            }
        }
    }
}

//-------------------------------ACCEPT FUNCTIONS-------------------------------

void PauseMenu::accept()
{
    switch ( m_currentMenu )
    {
        case TYPE_MAIN:
        {
            acceptMainMenu();
            break;
        }
        case TYPE_EXIT:
        {
            acceptExitMenu();
            break;
        }
        case TYPE_SETTINGS:
        {
            acceptSettingsMenu();
            break;
        }
        case TYPE_GRAPHICS_SETTINGS:
        {
            acceptGraphicsMenu();
            break;
        }
    }
}

void PauseMenu::acceptMainMenu()
{
    switch ( static_cast<MainMenuItem>( m_currentIndex ) )
    {
        case MAIN_RESUME:
        {
            global::pause = false;
            updateMenuState();
            break;
        }
        case MAIN_SETTINGS:
        {
            // go to the settings menu
            m_currentMenu = TYPE_SETTINGS;
            updateMenuState();
            break;
        }
        case MAIN_EXIT:
        {
            // go to the exit menu
            m_currentMenu = TYPE_EXIT;
            updateMenuState();
            break;
        }
    }
}

void PauseMenu::acceptExitMenu()
{
    switch ( static_cast<ExitMenuItem>( m_currentIndex ) )
    {
        case EXIT_NO:
        {
            // return to the main menu
            m_currentMenu = TYPE_MAIN;
            updateMenuState();
            break;
        }
        case EXIT_YES:
        {
            // exit the game
            omi::omi_running = false;
            break;
        }
    }
}

void PauseMenu::acceptSettingsMenu()
{
    switch ( static_cast<SettingsMenuItem>( m_currentIndex ) )
    {
        case SETTINGS_INPUT:
        {
            // go to the input settings menu
            m_currentMenu = TYPE_INPUT_SETTINGS;
            updateMenuState();
            break;
        }
        case SETTINGS_AUDIO:
        {
            // go to the audio setings menu
            m_currentMenu = TYPE_AUDIO_SETTINGS;
            updateMenuState();
            break;
        }
        case SETTINGS_GRAPHICS:
        {
            // got to the graphics settings menu
            m_currentMenu = TYPE_GRAPHICS_SETTINGS;
            updateMenuState();
            break;
        }
        case SETTINGS_BACK:
        {
            // return to the main menu
            m_currentMenu = TYPE_MAIN;
            updateMenuState();
            break;
        }
    }
}

void PauseMenu::acceptGraphicsMenu()
{
    switch ( static_cast<GraphicsMenuItem>( m_currentIndex ) )
    {
        case GRAPHICS_RESET_DEFAULTS:
        {
            // TODO:
            break;
        }
        case GRAPHICS_BACK:
        {
            // return to the main menu
            m_currentMenu = TYPE_SETTINGS;
            updateMenuState();
            break;
        }
    }
}

//----------------------------------VISIBILITY----------------------------------

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

void PauseMenu::setWidgetVisibility(
        std::vector<SettingWidget*> widgetList, bool visible )
{
    for ( std::vector<SettingWidget*>::iterator it = widgetList.begin();
          it != widgetList.end();
          ++it )
    {
        ( *it )->setVisible( visible );
    }
}

void PauseMenu::hideAll()
{
    m_overlay->visible = false;
    setTextListVisibility( m_mainText, false );
    m_exitCheckText->visible = false;
    setTextListVisibility( m_exitText, false );
    setTextListVisibility( m_settingsText, false );
    setTextListVisibility( m_graphicsText, false );
    setWidgetVisibility( m_graphicsWidgets, false );
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
    initExitMenuComponents();
    initSettingsMenuComponents();
    initGraphicsMenuComponents();
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

void PauseMenu::initExitMenuComponents()
{
    // are you sure text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.25f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    m_exitCheckText =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    m_exitCheckText->gui = true;
    m_exitCheckText->setString( "Are you sure?" );
    m_exitCheckText->setHorCentred( true );
    m_exitCheckText->setVertCentred( true );
    m_exitCheckText->visible = false;
    m_components.add( m_exitCheckText );

    }

    // yes text
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
    text->setString( "No" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_exitText.push_back( text );

    }
    // no text
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
    text->setString( "Yes" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_exitText.push_back( text );

    }
}

void PauseMenu::initSettingsMenuComponents()
{
    // input text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.375f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    text->gui = true;
    text->setString( "Input" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_settingsText.push_back( text );

    }
    // audio text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.125f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    text->gui = true;
    text->setString( "Audio" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_settingsText.push_back( text );

    }
    // graphics text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, -0.125f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    text->gui = true;
    text->setString( "Graphics" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_settingsText.push_back( text );

    }
    // back text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( 0.0f, -0.375f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_main_item_text", "", t );
    text->gui = true;
    text->setString( "Back" );
    text->setHorCentred( true );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_settingsText.push_back( text );

    }
}

void PauseMenu::initGraphicsMenuComponents()
{
    // resolution
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( -1.0f, 0.3125f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_secondary_item_text", "", t );
    text->gui = true;
    text->setString( "Resolution" );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_graphicsText.push_back( text );

    // TODO:
    // add widget
    std::vector<std::string> values;
    values.push_back( "480x270" );
    values.push_back( "960x540" );
    values.push_back( "1440x810" );
    values.push_back( "1920x1080" );
    SettingWidget* widget = new EnumWidget(
            glm::vec3( 0.5f, 0.3125f, 0.0f ),
            values,
            3
    );
    m_graphicsWidgets.push_back( widget );
    addEntity( widget );

    }

    // fullscreen text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( -1.0f, 0.1875f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_secondary_item_text", "", t );
    text->gui = true;
    text->setString( "Fullscreen" );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_graphicsText.push_back( text );

    // TODO:
    // add widget
    std::vector<std::string> values;
    values.push_back( "No" );
    values.push_back( "Yes" );
    SettingWidget* widget = new EnumWidget(
            glm::vec3( 0.5f, 0.1875, 0.0f ),
            values,
            1
    );
    m_graphicsWidgets.push_back( widget );
    addEntity( widget );

    }

    // gamma text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( -1.0f, 0.0625f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_secondary_item_text", "", t );
    text->gui = true;
    text->setString( "Gamma" );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_graphicsText.push_back( text );

    // TODO:
    // add widget
    std::vector<std::string> values;
    values.push_back( "0" );
    values.push_back( "1" );
    SettingWidget* widget = new EnumWidget(
            glm::vec3( 0.5f, 0.0625f, 0.0f ),
            values,
            1
    );
    m_graphicsWidgets.push_back( widget );
    addEntity( widget );

    }

    // shadows text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( -1.0f, -0.0625f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_secondary_item_text", "", t );
    text->gui = true;
    text->setString( "Shadows" );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_graphicsText.push_back( text );

    // TODO:
    // add widget
    std::vector<std::string> values;
    values.push_back( "Off" );
    values.push_back( "Low" );
    values.push_back( "Medium" );
    values.push_back( "High" );
    values.push_back( "Ultra" );
    SettingWidget* widget = new EnumWidget(
            glm::vec3( 0.5f, -0.0625f, 0.0f ),
            values,
            3
    );
    m_graphicsWidgets.push_back( widget );
    addEntity( widget );

    }

    // reset defaults text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( -1.0f, -0.1875f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_secondary_item_text", "", t );
    text->gui = true;
    text->setString( "Reset Defaults" );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_graphicsText.push_back( text );

    }

    // back text
    {

    omi::Transform* t = new omi::Transform(
            "",
            glm::vec3( -1.0f, -0.3125f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    omi::Text* text =
            omi::ResourceManager::getText( "pause_secondary_item_text", "", t );
    text->gui = true;
    text->setString( "Back" );
    text->setVertCentred( true );
    text->visible = false;
    m_components.add( text );

    m_graphicsText.push_back( text );

    }
}
