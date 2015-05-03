#include "Tile.hpp"

#include "src/functions/EnvironmentVendor.hpp"
#include "src/functions/Direction.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Tile::Tile(
        global::environment::Stage stage,
        const glm::vec3& position,
        global::environment::Direction direction )
    :
    m_stage    ( stage ),
    m_position ( position ),
    m_direction( direction )
{
    // initialise the adjacent map
    m_adjacent[ global::environment::NORTH ] = NULL;
    m_adjacent[ global::environment::EAST  ] = NULL;
    m_adjacent[ global::environment::SOUTH ] = NULL;
    m_adjacent[ global::environment::WEST  ] = NULL;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Tile::init()
{

    // TODO: appeared position
    // create the base transform
    m_baseT = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, dir::toAngle( m_direction ), 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_baseT );

    // vend and add the floor since it's there on every tile
    m_components.add( vendor::vendFloorTile( m_stage, m_baseT ) );
}

void Tile::update()
{
}
