#include "CornerSegment.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

CornerSegment::CornerSegment( const glm::vec3& position, float rotation ) :
        Segment( position, rotation )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CornerSegment::init()
{
    // floor
    omi::Transform* t_0 = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, m_rotation, 0.0f ),
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

    //--------------------------------LEFT WALL---------------------------------

    omi::Transform* t_1 = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, m_rotation + 90.0f, 0.0f ),
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
    glm::vec3 leftPos( -3.0f, 0.0f, 0.0f );
    omi::bounding::Direction leftDirection = omi::bounding::LEFT;
    if ( m_rotation > 45.0f )
    {
        leftPos = glm::vec3( 0.0f, 0.0f, 3.0f );
        leftDirection = omi::bounding::DOWN;
    }
    omi::Transform* t_cl = new omi::Transform(
            "",
            m_position + leftPos,
            glm::vec3( 0.0f, m_rotation, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_cl );
    omi::CollisionDetector* leftBlock =
            new omi::CollisionDetector( "", "wall", this );
    leftBlock->addBounding( new omi::BoundingRect(
            glm::vec2( 3.0f, 3.0f ),
            t_cl,
            leftDirection
    ) );
    m_components.add( leftBlock );


    //--------------------------------FRONT WALL--------------------------------

    omi::Transform* t_2 = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, m_rotation, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_2 );
    omi::Mesh* frontWallMesh =
                omi::ResourceManager::getMesh( "facility_wall", "", t_2 );
    frontWallMesh->getMaterial().specular = new omi::Specular(
            64.0f,
            glm::vec3( 0.5f, 0.5f, 0.5f ),
            omi::ResourceManager::getTexture( "facility_wall_spec" )
    );
    m_components.add( frontWallMesh );

    // left skirting
    omi::Mesh* frontSkirting =
                omi::ResourceManager::getMesh( "facility_skirting", "", t_2 );
    frontSkirting->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 0.75f, 0.75f, 0.75f ),
            omi::ResourceManager::getTexture( "facility_skirting_spec" )
    );
    m_components.add( frontSkirting );

    // left collision detector
    omi::Transform* t_c2 = new omi::Transform(
            "",
            m_position + glm::vec3( 0.0f, 0.0f, -3.0f ),
            glm::vec3( 0.0f, m_rotation, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t_c2 );
    omi::CollisionDetector* frontBlock =
            new omi::CollisionDetector( "", "wall", this );
    frontBlock->addBounding( new omi::BoundingRect(
            glm::vec2( 3.0f, 3.0f ),
            t_c2,
            omi::bounding::UP
    ) );
    m_components.add( frontBlock );

    // ceiling
    omi::Transform* t_3 = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, m_rotation, 0.0f ),
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

void CornerSegment::update()
{
}
