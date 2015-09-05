#ifndef REVERIE_ENTITIES_GAMEPALY_LAYOUT_LEVELGRID_HPP_
#   define REVERIE_ENTITIES_GAMEPALY_LAYOUT_LEVELGRID_HPP_

#include <map>

#include "lib/Utilitron/TypeUtil.hpp"

#include "src/entities/gameplay/environment/tile/Tile.hpp"

/***********************************************************\
| Contains the tiles that currently exist within the level. |
\***********************************************************/
class LevelGrid
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    LevelGrid();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Gets and returns the tile at the given floating point 3d position.
    Returns NULL if there is not tile located there */
    Tile* getTile( const glm::vec3& position );

    /** Adds the given tile to the level grid */
    void addTile( Tile* tile );

    /** Removes the given tile to the level grid */
    void removeTile( Tile* tile );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    std::map< util::int64, Tile* > m_lookUpTable;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Evaluates and returns the look up table address for the given
    position */
    util::int64 evaulateAddress( const glm::vec3& position );
};

#endif
