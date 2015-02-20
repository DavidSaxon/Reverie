#ifndef REVERIE_ENTITIES_GAMEPLAY_MENU_PAUSE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_MENU_PAUSE_HPP_

#include "src/omicron/entity/Entity.hpp"

/*****************************************\
| Handles the in-game pause overlay menu. |
\*****************************************/
class PauseMenu : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                ENUMERATORS
    //--------------------------------------------------------------------------

    enum MainMenuItem
    {
        MAIN_RESUME = 0,
        MAIN_SETTINGS,
        MAIN_EXIT,
        MAIN_COUNT
    };

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

    // the currently selected main menu item
    MainMenuItem m_mainMenuItem;

    // is true if the escape key is down
    bool m_escDown;
    // is true if an arrow key is down
    bool m_arrowDown;

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

    /** Updates menu logics */
    void updateMenu();
};

#endif
