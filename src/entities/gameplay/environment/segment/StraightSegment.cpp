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
            32.0f,
            glm::vec3( 0.75f, 0.75f, 0.75f ),
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

    // left skirting
    omi::Mesh* leftSkirtingMesh =
                omi::ResourceManager::getMesh( "facility_skirting", "", t_1 );
    leftSkirtingMesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 0.75f, 0.75f, 0.75f ),
            omi::ResourceManager::getTexture( "facility_skirting_spec" )
    );
    m_components.add( leftSkirtingMesh );

    // left collision detector
    omi::Transform* t_cl = new omi::Transform(
            "",
            m_position + glm::vec3( 3.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_cl );
    omi::CollisionDetector* leftBlock =
            new omi::CollisionDetector( "", "wall", this );
    leftBlock->addBounding(
                new omi::BoundingRect( glm::vec2( 3.0f, 3.0f ), t_cl ) );
    m_components.add( leftBlock );

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
            8.0f,
            glm::vec3( 0.5f, 0.5f, 0.5f ),
            omi::ResourceManager::getTexture( "facility_wall_spec" )
    );
    m_components.add( rightWallMesh );

    // right skirting
    omi::Mesh* rightSkirtingMesh =
                omi::ResourceManager::getMesh( "facility_skirting", "", t_2 );
    rightSkirtingMesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 0.75f, 0.75f, 0.75f ),
            omi::ResourceManager::getTexture( "facility_skirting_spec" )
    );
    m_components.add( rightSkirtingMesh );


    // ceiling
    omi::Transform* t_3 = new omi::Transform(
            "",
            m_position,
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_3 );
    omi::Mesh* ceilingMesh =
                omi::ResourceManager::getMesh( "facility_ceiling", "", t_3 );
    ceilingMesh->getMaterial().specular = new omi::Specular(
            64.0f,
            glm::vec3( 0.1f, 0.1f, 0.1f ),
            omi::ResourceManager::getTexture( "facility_ceiling_spec" )
    );
    m_components.add( ceilingMesh );
}

void StraightSegment::update()
{

}
