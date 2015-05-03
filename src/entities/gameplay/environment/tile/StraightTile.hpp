#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_STRAIGHT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_STRAIGHT_HPP_

#include "src/entities/gameplay/environment/tile/Tile.hpp"

class StraightTile : public Tile
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    StraightTile(
            global::environment::Stage stage,
            const glm::vec3& position,
            global::environment::Direction direction );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
