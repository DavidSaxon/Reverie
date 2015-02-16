#include "Window.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Window::Window() :
    m_cursorVisble(true)
{
    // set up flags
    unsigned flags = sf::Style::Default;
    if ( displaySettings.getFullscreen() )
    {
        // flags = sf::Style::None;
        flags = sf::Style::Fullscreen;
    }

    // set up for openGL
    sf::ContextSettings settings;
    settings.depthBits          = 24;
    settings.stencilBits        = 8;
    settings.antialiasingLevel  = 4;
    settings.majorVersion       = 1;
    settings.minorVersion       = 1;

    // non-full screen mode
    if ( !displaySettings.getFullscreen() )
    {
        // create the window using sfml
        m_window = std::unique_ptr<sf::Window>( new sf::Window(
            sf::VideoMode(
                static_cast<unsigned>( displaySettings.getSize().x ),
                static_cast<unsigned>( displaySettings.getSize().y ) ),
            displaySettings.getTitle(), flags, settings)
        );
        // set the position of the window
        m_window->setPosition( sf::Vector2i(
            static_cast<int>( displaySettings.getPos().x ),
            static_cast<int>( displaySettings.getPos().y ) ) );
    }
    // full screen mode
    else
    {
        // create the window using sfml
        m_window = std::unique_ptr<sf::Window>( new sf::Window(
            sf::VideoMode::getDesktopMode(),
            displaySettings.getTitle(), flags, settings)
        );
        // update the display settings with the new resolution and position
        displaySettings.setSize( glm::vec2(
            m_window->getSize().x, m_window->getSize().y ) );
        displaySettings.setPos( glm::vec2( 0 ) );
    }

    // set v sync
    m_window->setVerticalSyncEnabled( displaySettings.getVsync() );
    // set cursor visibility
    m_window->setMouseCursorVisible( m_cursorVisble );
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Window::update()
{
    m_window->setVisible(true);

    // check if there has been a change in settings
    if ( displaySettings.check() )
    {
        if ( !displaySettings.getFullscreen() ) {

            m_window->setSize( sf::Vector2u(
                static_cast<unsigned>( displaySettings.getSize().x ),
                static_cast<unsigned>( displaySettings.getSize().y ) )
            );
            m_window->setPosition( sf::Vector2i(
                static_cast<int>( displaySettings.getPos().x ),
                static_cast<int>( displaySettings.getPos().y ) )
            );
            m_window->setTitle( displaySettings.getTitle() );
        }

        // TODO: full screen... tricky problem
    }
    // set cursor visibility
    if ( omi_hasFocus )
    {
        m_window->setMouseCursorVisible( m_cursorVisble );
    }
    else
    {
        m_window->setMouseCursorVisible( true );
    }

    // check events
    sf::Event event;
    // is true if we get a mouse wheel event
    bool mouseWheel = false;
    while ( m_window->pollEvent( event ) )
    {
        // TODO: this should be override able
        // close button is pressed
        if ( event.type == sf::Event::Closed )
        {
            exit( 0 );
        }
        // mouse scrolling
        if ( event.type == sf::Event::MouseWheelMoved )
        {
            mouseWheel = true;
            input::setMouseScroll( event.mouseWheel.delta );
        }
        // focus lost
        if ( event.type == sf::Event::LostFocus )
        {
            omi_hasFocus = false;
        }
        if ( event.type == sf::Event::GainedFocus )
        {
            omi_hasFocus = true;
        }
    }
    // there has been no mouse scrolling
    if ( !mouseWheel )
    {
        input::setMouseScroll( 0 );
    }

    // redisplay the window
    m_window->display();
}

void Window::setCursorVisble( bool visible )
{
    m_cursorVisble = visible;
}

} // namespace omi
