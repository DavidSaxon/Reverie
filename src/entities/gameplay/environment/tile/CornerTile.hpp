#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_CORNER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_CORNER_HPP_

#include "src/entities/gameplay/environment/tile/Tile.hpp"

class CornerTile : public Tile
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    CornerTile(
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
