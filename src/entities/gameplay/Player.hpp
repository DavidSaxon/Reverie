#ifndef REVERIE_ENTITIES_GAMEPLAY_PLAYER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_PLAYER_HPP_

#include "src/omicron/entity/Entity.hpp"

namespace player
{

// enumerators for move priorities
enum ZMove
{
    Z_NONE = 0,
    Z_FORWARD,
    Z_BACKWARD
};
enum XMove
{
    Y_NONE = 0,
    Y_LEFT,
    Y_RIGHT
};

} // namespace player

class Player : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Player();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    /** Return's the player's transform */
    omi::Transform* getTransform();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the main transformation of the player
    omi::Transform* m_transform;
    // the transformation of the camera associated with the player
    omi::Transform* m_camT;

    // the player's collision checker
    omi::CollisionChecker* m_collisionChecker;

    // move priorities
    player::ZMove m_zPriority;
    player::XMove m_yPriority;

    // walk animation variables
    float m_stepAnimation;

    // TODO: REMOVE ME
    // the right arm of the player which shows active curses
    omi::Mesh* m_rightArm;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Performs player looking (camera rotation with the mouse) */
    void look();

    /** Performs player movement (camera translation with keys) */
    void move();
};

#endif
