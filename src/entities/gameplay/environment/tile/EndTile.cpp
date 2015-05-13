#include "EndTile.hpp"

#include "src/functions/EnvironmentVendor.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

EndTile::EndTile(
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

void EndTile::init()
{
    // super call
    Tile::init();

    // floor
    m_components.add( vendor::vendCeilingTile( m_stage, m_baseT ) );
    // north wall
    m_components.add( vendor::vendWallTile(
            m_stage,
            m_baseT,
            global::environment::NORTH
    ) );
    m_components.add( vendor::vendSkirting(
            m_stage,
            m_baseT,
            global::environment::NORTH
    ) );
    m_components.add( vendor::vendWallCollider(
            this,
            m_baseT,
            m_direction,
            global::environment::NORTH
    ) );
    // east wall
    m_components.add( vendor::vendWallTile(
            m_stage,
            m_baseT,
            global::environment::EAST
    ) );
    m_components.add( vendor::vendSkirting(
            m_stage,
            m_baseT,
            global::environment::EAST
    ) );
    m_components.add( vendor::vendWallCollider(
            this,
            m_baseT,
            m_direction,
            global::environment::EAST
    ) );
    // west wall
    m_components.add( vendor::vendWallTile(
            m_stage,
            m_baseT,
            global::environment::WEST
    ) );
    m_components.add( vendor::vendSkirting(
            m_stage,
            m_baseT,
            global::environment::WEST
    ) );
    m_components.add( vendor::vendWallCollider(
            this,
            m_baseT,
            m_direction,
            global::environment::WEST
    ) );
}

void EndTile::update()
{
    Tile::update();
}
