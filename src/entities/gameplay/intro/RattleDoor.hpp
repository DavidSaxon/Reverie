#ifndef REVERIE_ENTITIES_GAMEPLAY_INTRO_RATTLEDOOR_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_INTRO_RATTLEDOOR_HPP_

#include "src/omicron/entity/Entity.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Player;

class RattleDoor : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    RattleDoor( const glm::vec3 basePos, Player* player );

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

    // the position of the door
    omi::Transform* m_pos;
    glm::vec3 m_basePos;

    // the door panel manipulator
    omi::Transform* m_panelManipulator;

    // the handle manipulator
    omi::Transform* m_preHandleManipulator;
    omi::Transform* m_handleManipulator;

    // a pointer to the player entity
    Player* m_player;

    // is true once the door has been triggered
    bool m_triggered;
    // the handle animation
    float m_handleAnimation;
};

#endif
