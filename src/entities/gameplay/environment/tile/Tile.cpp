#include "Tile.hpp"

#include "src/functions/EnvironmentVendor.hpp"
#include "src/functions/Direction.hpp"

#include "src/entities/gameplay/environment/decor/Decor.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Tile::Tile(
        global::environment::Stage stage,
        const glm::vec3& position,
        global::environment::Direction direction,
        unsigned long decor )
    :
    m_stage    ( stage ),
    m_position ( position ),
    m_direction( direction ),
    m_decor    ( decor )
{
    // create the base transform
    m_baseT = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, dir::toAngle( m_direction ), 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Tile::init()
{
    // add the base transform
    m_components.add( m_baseT );

    // calculate random floor angle
    int r = static_cast< unsigned >( rand() ) % 2;

    // vend and add the floor and ceiling since it's there on every tile
    omi::Transform* floorT = new omi::Transform(
            "",
            m_baseT,
            glm::vec3(),
            glm::vec3( 0.0F, 180.0F * r, 0.0F ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( floorT );
    omi::Mesh* mesh = vendor::vendFloorTile( m_stage, floorT );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    r = static_cast< unsigned >( rand() ) % 4;
    omi::Transform* cielT = new omi::Transform(
            "",
            m_baseT,
            glm::vec3(),
            glm::vec3( 0.0F, 180.0F * r, 0.0F ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( cielT );
    mesh = vendor::vendCeilingTile( m_stage, cielT );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );

    // vend the decor
    vendor::vendDecor( m_stage, m_baseT, m_decor, m_decorEntities );
    // add decor
    for ( std::vector<Decor*>::iterator it = m_decorEntities.begin();
          it != m_decorEntities.end();
          ++it )
    {
        addEntity( *it );
    }
}

void Tile::update()
{
}

void Tile::setVisibility( bool state )
{
    // super call
    ProcedualEntity::setVisibility( state );
    // set decor visibility
    for ( std::vector<Decor*>::iterator it = m_decorEntities.begin();
          it != m_decorEntities.end();
          ++it )
    {
        ( *it )->setVisibility( state );
    }
}

omi::Transform* Tile::getBaseTransform()
{
    return m_baseT;
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Tile::remove()
{
    // mark decor for removal
    for ( std::vector<Decor*>::iterator it = m_decorEntities.begin();
          it != m_decorEntities.end();
          ++it )
    {
        ( *it )->remove();
    }

    // super call
    Entity::remove();
}
