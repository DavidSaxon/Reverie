#ifndef REVERIE_ENTITIES_GAMEPLAY_INTRO_PHOBETORENCOUNTER1_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_INTRO_PHOBETORENCOUNTER1_HPP_

#include "src/entities/gameplay/ProcedualEntity.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Player;

class PhobetorEncounter1 : public ProcedualEntity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    PhobetorEncounter1( const glm::vec3& basePos, Player* player );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    // the position of the encounter
    omi::Transform* m_pos;
    glm::vec3 m_basePos;

    // a pointer to the player entity
    Player* m_player;

    // the light source component
    omi::PointLight* m_lightSource;
    // the light pane mesh
    omi::Mesh* m_paneMesh;
    // the phobetor mesh
    omi::Mesh* m_phobetorMesh;

    // collision detectors
    omi::CollisionDetector* m_startDetector;
    omi::CollisionDetector* m_endDetector;

    // flags
    bool m_startFlag;
    bool m_endFlag;

    // turn on animation counter
    float m_turnOnAnimation;
};

#endif
