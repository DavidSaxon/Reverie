#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_TILE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_TILE_HPP_

#include <map>

#include "src/data/Globals.hpp"
#include "src/omicron/entity/Entity.hpp"

/****************************************************************************\
| A tile represents a cube segment of the environment. Tiles are sub-classed |
| into their separate types.                                                 |
\****************************************************************************/
class Tile : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Tile(
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

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    global::environment::Stage m_stage;
    glm::vec3 m_position;
    global::environment::Direction m_direction;

    // a mapping from direction to adjacent tiles
    std::map<global::environment::Direction, Tile*> m_adjacent;

    // the base transform of the tile
    omi::Transform* m_baseT;
};

#endif
