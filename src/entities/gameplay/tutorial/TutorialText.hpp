#ifndef REVERIE_ENTITIES_GAMEPLAY_TUTORIAL_TEXT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_TUTORIAL_TEXT_HPP_

#include "src/omicron/entity/Entity.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Player;

class TutorialText : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    TutorialText(
            const glm::vec3 basePos,
            float baseRot,
            const std::string& str,
            Player* player,
            bool isTitle = false );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the position of the text
    omi::Transform* m_pos;
    // the text component
    omi::Text* m_text;
    // the title text component
    omi::Text* m_titleText;

    // the base transformation
    glm::vec3 m_basePos;
    float m_baseRot;

    // the string to use as text
    std::string m_str;

    // a pointer to the player entity
    Player* m_player;

    // if the title should be displayed
    bool m_isTitle;
};

#endif
