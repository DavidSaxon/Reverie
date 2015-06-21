#include "CornerTile.hpp"

#include "src/functions/EnvironmentVendor.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

CornerTile::CornerTile(
        global::environment::Stage stage,
        const glm::vec3& position,
        global::environment::Direction direction,
        unsigned long decor )
    :
    Tile( stage, position, direction, decor )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CornerTile::init()
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

void CornerTile::update()
{
    Tile::update();
}
