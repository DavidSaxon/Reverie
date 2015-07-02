#ifndef REVERIE_ENTITIES_GAMEPLAY_INTRO_KNOCKDOOR_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_INTRO_KNOCKDOOR_HPP_

#include "src/entities/gameplay/ProcedualEntity.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Player;

class KnockDoor : public ProcedualEntity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    KnockDoor( const glm::vec3 basePos, Player* player );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    // the position of the door
    omi::Transform* m_pos;
    glm::vec3 m_basePos;

    // a pointer to the player entity
    Player* m_player;

    // is true once the door has been triggered
    bool m_triggered;
};

#endif
