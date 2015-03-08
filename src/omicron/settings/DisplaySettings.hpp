#ifndef OMICRON_SETTINGS_DISPLAYSETTINGS_H_
#   define OMICRON_SETTINGS_DISPLAYSETTINGS_H_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <string>

#include "lib/glm/glm.hpp"
#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

/******************************************************************************\
| An object that contains all settings relating to the display window that are |
| controlled by Omicron.                                                       |
\******************************************************************************/
class DisplaySettings {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN( DisplaySettings );

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates new window settings initialised with the default values */
    DisplaySettings();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Checks if a change has been made to the settings */
    bool check();

    //---------------------------------GETTERS----------------------------------

    /** @return the title of the window */
    const std::string& getTitle() const;

    /** @return the size of the window */
    const glm::vec2& getSize() const;

    /** @return the position of the window */
    const glm::vec2 getPos() const;

    /** @return the centre of the window */
    const glm::vec2& getCentre() const;

    /** @return if the window is in fullscreen */
    bool getFullscreen() const;

    /** @return if vsync is enabled */
    bool getVsync() const;

    /** @return the size of the screen */
    const glm::vec2& getScreenSize();

    //---------------------------------SETTERS----------------------------------

    /** @param title the new title of the window */
    void setTitle( const std::string& title );

    /** @param size the new size of the window */
    void setSize( const glm::vec2& size );

    /** @param pos the new position of the window */
    void setPos( const glm::vec2& pos );

    /** @param fullscreen the new fullscreen mode of the window */
    void setFullscreen( bool fullscreen );

    /** @param vsync whether vsnyc should be enabled or not */
    void setVsync( bool vsnyc );

    /** @param sets the size of the screen */
    void setScreenSet( glm::vec2& screenSize );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // if a setting has changed
    bool m_change;

    // the title of the window
    std::string m_title;
    // the size of the window
    glm::vec2 m_size;
    // the position of the window
    glm::vec2 m_pos;
    // the centre of the window
    glm::vec2 m_centre;
    // is true if the window is in fullscreen
    bool m_fullscreen;
    // is true to enable vertical sync
    bool m_vsync;
    // the size of the screen
    glm::vec2 m_screenSize;
};


} // namespace omi

#endif
