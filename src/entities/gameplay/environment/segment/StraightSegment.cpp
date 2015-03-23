#include "StraightSegment.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StraightSegment::StraightSegment( const glm::vec3& position ) :
        Segment( position )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StraightSegment::init()
{
    // floor
    omi::Transform* t_0 = new omi::Transform(
            "",
            m_position,
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_0 );
    omi::Mesh* floorMesh =
                omi::ResourceManager::getMesh( "facility_floor", "", t_0 );
    floorMesh->getMaterial().specular = new omi::Specular(
            64.0f,
            glm::vec3( 0.5f, 0.5f, 0.5f ),
            omi::ResourceManager::getTexture( "facility_floor_spec" )
    );
    m_components.add( floorMesh );


    // left wall
    omi::Transform* t_1 = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, 90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_1 );
    omi::Mesh* leftWallMesh =
                omi::ResourceManager::getMesh( "facility_wall", "", t_1 );
    leftWallMesh->getMaterial().specular = new omi::Specular(
            64.0f,
            glm::vec3( 0.5f, 0.5f, 0.5f ),
            omi::ResourceManager::getTexture( "facility_wall_spec" )
    );
    m_components.add( leftWallMesh );

    // right wall
    omi::Transform* t_2 = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, -90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_2 );
    omi::Mesh* rightWallMesh =
                omi::ResourceManager::getMesh( "facility_wall", "", t_2 );
    rightWallMesh->getMaterial().specular = new omi::Specular(
            64.0f,
            glm::vec3( 0.5f, 0.5f, 0.5f ),
            omi::ResourceManager::getTexture( "facility_wall_spec" )
    );
    m_components.add( rightWallMesh );
}

void StraightSegment::update()
{

}
