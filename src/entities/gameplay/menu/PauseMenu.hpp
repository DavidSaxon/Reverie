#ifndef REVERIE_ENTITIES_GAMEPLAY_MENU_PAUSE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_MENU_PAUSE_HPP_

#include <vector>

#include "src/omicron/entity/Entity.hpp"

/*****************************************\
| Handles the in-game pause overlay menu. |
\*****************************************/
class PauseMenu : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                ENUMERATORS
    //--------------------------------------------------------------------------

    // the different menu
    enum MenuType
    {
        TYPE_MAIN = 0,
        TYPE_CHECK_EXIT,
        TYPE_SETTINGS,
        TYPE_GRAPHICS_SETTINGS,
        TYPE_AUDIO_SETTINGS,
        TYPE_INPUT_SETTINGS
    };

    // the items on the main menu
    enum MainMenuItem
    {
        MAIN_RESUME = 0,
        MAIN_SETTINGS,
        MAIN_EXIT
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

    // the current menu
    MenuType m_currentMenu;

    // is true if the scape key is currently down
    bool m_escDown;

    // the sprite for the menu overlay
    omi::Sprite* m_overlay;
    // the list of renderable text for the main menu
    std::vector<omi::Text*> m_mainText;

    // the index of the currently selected menu item
    int m_currentIndex;
    // the list of items currently on the menu
    std::vector<omi::Text*> m_currentItems;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Updates the menu to reflect a state change */
    void updateMenuState();

    /** Updates logic for when the menu is open */
    void updateMenuLogic();

    /** Sets the colour of the current menu items */
    void setItemColours();

    //--------------------------------VISIBILITY--------------------------------

    /** Sets the visibility of the given text list */
    void setTextListVisibility(
            std::vector<omi::Text*>& textList, bool visible );

    /** Hides all aspects of the menu */
    void hideAll();

    //------------------------------INITIALISATION------------------------------

    /** Initialises the components of the pause menu */
    void initComponents();

    /** Initialises the main menu components */
    void initMainMenuComponents();
};

#endif
