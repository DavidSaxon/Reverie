#include "StraightTile.hpp"

#include "src/functions/EnvironmentVendor.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StraightTile::StraightTile(
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

void StraightTile::init()
{
    // super call
    Tile::init();

    // east wall
    omi::Mesh* mesh = vendor::vendWallTile(
            m_stage,
            m_baseT,
            global::environment::EAST
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    mesh = vendor::vendSkirting(
            m_stage,
            m_baseT,
            global::environment::EAST
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    m_components.add( vendor::vendWallCollider(
            this,
            m_baseT,
            m_direction,
            global::environment::EAST
    ) );


    // west wall
    mesh = vendor::vendWallTile(
            m_stage,
            m_baseT,
            global::environment::WEST
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    mesh = vendor::vendSkirting(
            m_stage,
            m_baseT,
            global::environment::WEST
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    m_components.add( vendor::vendWallCollider(
            this,
            m_baseT,
            m_direction,
            global::environment::WEST
    ) );
}

void StraightTile::update()
{
    Tile::update();
}
