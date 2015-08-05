#ifndef REVERIE_ENTITIES_GAMEPLAY_CURSEROOM_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_CURSEROOM_HPP_

#include "src/omicron/entity/Entity.hpp"

#include "src/data/Globals.hpp"

class Player;

class CurseRoom : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    CurseRoom(
        const glm::vec3& pos,
        global::environment::Direction direction,
        Player* player );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void init();

    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the position of the curse room
    glm::vec3 m_position;
    // the direction of the curse room
    global::environment::Direction m_direction;

    // pointer to the player
    Player* m_player;

    // the curse giver model
    omi::KeyFrameMesh* m_curseGiverBody;
    omi::Mesh* m_curseGiverPants;

    // player collision trigger
    omi::CollisionDetector* m_trigger;
    bool m_triggered;

    // the position for the player to auto-move to
    glm::vec3 m_autoMovePos;
    glm::vec2 m_autoLookAngle;

    // curse text
    omi::Text* m_curse1Title;
    omi::Text* m_curse1Description;
    omi::Text* m_curse2Title;
    omi::Text* m_curse2Description;
    omi::Text* m_curse3Title;
    omi::Text* m_curse3Description;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void initComponents();
};

#endif
