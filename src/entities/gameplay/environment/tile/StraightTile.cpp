#include "StraightTile.hpp"

#include "src/functions/EnvironmentVendor.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StraightTile::StraightTile(
        global::environment::Stage stage,
        const glm::vec3& position,
        global::environment::Direction direction )
    :
    Tile( stage, position, direction )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StraightTile::init()
{
    // super call
    Tile::init();

    // floor
    m_components.add( vendor::vendCeilingTile( m_stage, m_baseT ) );
    // walls
    m_components.add( vendor::vendWallTile(
            m_stage,
            m_baseT,
            global::environment::EAST
    ) );
    m_components.add( vendor::vendWallTile(
            m_stage,
            m_baseT,
            global::environment::WEST
    ) );
}

void StraightTile::update()
{
    Tile::update();
}
