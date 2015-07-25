#include "src/entities/gameplay/CurseRoom.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

CurseRoom::CurseRoom( const glm::vec3& pos )
    :
    m_position( pos )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CurseRoom::init()
{
    // base transform
    omi::Transform* baseT = new omi::Transform(
            "",
            m_position,
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( baseT );

    // room walls
    omi::Mesh* floorMesh =
            omi::ResourceManager::getMesh( "curse_room_floor", "", baseT );
    floorMesh->castShadow = false;
    m_components.add( floorMesh );
    omi::Mesh* ceilingMesh =
            omi::ResourceManager::getMesh( "curse_room_ceiling", "", baseT );
    ceilingMesh->castShadow = false;
    m_components.add( ceilingMesh );
    omi::Mesh* wallBackMesh =
            omi::ResourceManager::getMesh( "curse_room_wall", "", baseT );
    wallBackMesh->castShadow = false;
    m_components.add( wallBackMesh );
    omi::Transform* wallLeftT = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, 90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( wallLeftT );
    omi::Mesh* wallLeftMesh =
            omi::ResourceManager::getMesh( "curse_room_wall", "", wallLeftT );
    wallLeftMesh->castShadow = false;
    m_components.add( wallLeftMesh );
    omi::Transform* wallRightT = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0f, -90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( wallRightT );
    omi::Mesh* wallRightMesh =
            omi::ResourceManager::getMesh( "curse_room_wall", "", wallRightT );
    wallRightMesh->castShadow = false;
    m_components.add( wallRightMesh );



    // TODO: collision detectors

    // lights
    omi::Transform* lowLightT = new omi::Transform(
            "",
            baseT,
            glm::vec3( 0.0f, 1.0f, 1.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( lowLightT );
    omi::PointLight* lowLight = new omi::PointLight(
            "",
            lowLightT,
            0.15F,
            glm::vec3( 1.0f, 0.8f, 0.8f ),
            0.0f,
            0.1f,
            0.02f
    );
    m_components.add( lowLight );

    omi::Transform* highLightT = new omi::Transform(
            "",
            baseT,
            glm::vec3( 0.0f, 2.1f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( highLightT );
    omi::PointLight* highLight = new omi::PointLight(
            "",
            highLightT,
            0.1F,
            glm::vec3( 0.7f, 0.7f, 1.0f ),
            0.0f,
            0.1f,
            0.02f
    );
    m_components.add( highLight );

    // TODO: curse giver

    // TODO: hooks
}

void CurseRoom::update()
{

}
