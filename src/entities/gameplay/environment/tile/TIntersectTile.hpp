#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_TINTERSECT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_TINTERSECT_HPP_

#include "src/entities/gameplay/environment/tile/Tile.hpp"

class TIntersectTile : public Tile
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    TIntersectTile(
            global::environment::Stage stage,
            const glm::vec3& position,
            global::environment::Direction direction,
            unsigned long decor = global::environment::DECOR_NONE );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
