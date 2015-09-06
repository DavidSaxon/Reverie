#include "LevelGrid.hpp"

#include "src/data/Globals.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LevelGrid::LevelGrid()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

Tile* LevelGrid::getTile( const glm::vec3& position )
{
    unsigned address = evaulateAddress( position );

    // check if the address is in the map
    if ( m_lookUpTable.find( address ) != m_lookUpTable.end() )
    {
        return m_lookUpTable[ address ];
    }

    return NULL;
}

void LevelGrid::addTile( Tile* tile )
{
    unsigned address =
            evaulateAddress( tile->getBaseTransform()->translation );
    m_lookUpTable[ address ] = tile;
}

void LevelGrid::removeTile( Tile* tile )
{
    unsigned address =
            evaulateAddress( tile->getBaseTransform()->translation );

    // check if the address is in the map
    if ( m_lookUpTable.find( address ) != m_lookUpTable.end() )
    {
        m_lookUpTable[ address ] = NULL;
    }

}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

unsigned LevelGrid::evaulateAddress( const glm::vec3& position )
{
    // get unsigned indices
    unsigned x = static_cast< unsigned >( position.x / global::TILE_SIZE );
    unsigned y = static_cast< unsigned >( position.y / global::TILE_SIZE );


    // pack into an unsigned int
    x = ( x | ( x << 8 ) ) & 0x00FF00FF;
    x = ( x | ( x << 4 ) ) & 0x0F0F0F0F;
    x = ( x | ( x << 2 ) ) & 0x33333333;
    x = ( x | ( x << 1 ) ) & 0x55555555;

    y = ( y | ( y << 8 ) ) & 0x00FF00FF;
    y = ( y | ( y << 4 ) ) & 0x0F0F0F0F;
    y = ( y | ( y << 2 ) ) & 0x33333333;
    y = ( y | ( y << 1 ) ) & 0x55555555;

    return x | ( y << 1 );
}
