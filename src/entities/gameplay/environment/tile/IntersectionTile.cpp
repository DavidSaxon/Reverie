#include "IntersectionTile.hpp"

#include "src/functions/EnvironmentVendor.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntersectionTile::IntersectionTile(
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

void IntersectionTile::init()
{
    // super call
    Tile::init();

    // corner skirting
    omi::Mesh* mesh = vendor::vendSkirtingCorner(
            m_stage,
            m_baseT,
            global::environment::NORTH
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    mesh = vendor::vendSkirtingCorner(
            m_stage,
            m_baseT,
            global::environment::EAST
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    mesh = vendor::vendSkirtingCorner(
            m_stage,
            m_baseT,
            global::environment::SOUTH
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    mesh = vendor::vendSkirtingCorner(
            m_stage,
            m_baseT,
            global::environment::WEST
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );
}

void IntersectionTile::update()
{
    Tile::update();
}
