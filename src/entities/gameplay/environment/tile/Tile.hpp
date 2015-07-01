#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_TILE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_TILE_TILE_HPP_

#include <map>

#include "src/data/Globals.hpp"
#include "src/entities/gameplay/ProcedualEntity.hpp"

class Decor;

/****************************************************************************\
| A tile represents a cube segment of the environment. Tiles are sub-classed |
| into their separate types.                                                 |
\****************************************************************************/
class Tile : public ProcedualEntity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Tile(
            global::environment::Stage stage,
            const glm::vec3& position,
            global::environment::Direction direction,
            unsigned long decor );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    /** Sets the visibility of this tile */
    void setVisibility( bool state );

    /** Returns the base transform of the tile */
    omi::Transform* getBaseTransform();

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    global::environment::Stage m_stage;
    glm::vec3 m_position;
    global::environment::Direction m_direction;
    unsigned long m_decor;

    // a mapping from direction to adjacent tiles
    std::map<global::environment::Direction, Tile*> m_adjacent;

    // the base transform of the tile
    omi::Transform* m_baseT;

    // the decor entities of the tile
    std::vector<Decor*> m_decorEntities;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void remove();
};

#endif
