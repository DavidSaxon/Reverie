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

    // lights
    omi::PointLight* m_lowLight;
    omi::PointLight* m_highLight;
    omi::PointLight* m_blastLight;

    // the back wall mesh
    omi::Mesh* m_wallBackMesh;
    omi::Mesh* m_wallFrontMesh;

    // the transition pane mesh
    omi::Mesh* m_transitionPane;

    // the curse giver model
    omi::KeyFrameMesh* m_curseGiverBody;
    omi::Mesh* m_curseGiverPants;

    // curse room found?
    bool m_found;

    // player collision trigger
    omi::CollisionDetector* m_trigger;
    bool m_triggered;

    // the position for the player to auto-move to
    glm::vec3 m_autoMovePos;
    glm::vec2 m_autoLookAngle;

    // in show curses mode?
    bool m_showCurses;
    // show curses timer
    float m_curseTimer1;
    float m_curseTimer2;

    // end timer
    float m_endTimer;

    // curse text
    omi::Text* m_curse1Title;
    omi::Text* m_curse1Description;
    omi::Text* m_curse2Title;
    omi::Text* m_curse2Description;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void showCurses();

    void initComponents();
};

#endif
