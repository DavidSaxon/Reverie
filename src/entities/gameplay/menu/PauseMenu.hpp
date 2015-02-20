#ifndef REVERIE_ENTITIES_GAMEPLAY_MENU_PAUSE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_MENU_PAUSE_HPP_

#include "src/omicron/entity/Entity.hpp"

/*****************************************\
| Handles the in-game pause overlay menu. |
\*****************************************/
class PauseMenu : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    PauseMenu();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // is true if the pause menu is currently active
    bool m_active;

    // is true if the escape key is down
    bool m_escDown;

    // the transparent overlay for the menu
    omi::Sprite* m_overlay;

    // the text of the options on the menu
    omi::Text* m_resumeText;
    omi::Text* m_settingsText;
    omi::Text* m_exitText;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Shows or hides the pause menu */
    void show( bool state );
};

#endif
