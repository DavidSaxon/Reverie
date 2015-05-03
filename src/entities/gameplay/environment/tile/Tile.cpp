#include "Tile.hpp"

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
    // TODO: direction
    // TODO: appeared position
    // create the base transform
    m_baseT = new omi::Transform(
            "",
            m_position,
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_baseT );

    // vend and create the floor since it's there on every tile
    // TODO:
}

void Tile::update()
{
}
