#ifndef REVERIE_ENTITIES_GAMEPLAY_PLAYER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_PLAYER_HPP_

#include "src/omicron/entity/Entity.hpp"

// TODO: DOC:
class Player : public omi::Entity {
public:

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

    // the main transformation of the player
    omi::Transform* m_transform;
    // the transformation of the camera associated with the player
    omi::Transform* m_camT;
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
