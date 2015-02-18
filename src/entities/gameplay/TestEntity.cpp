#include "TestEntity.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestEntity::init()
{
    //----------------------------------LIGHTS----------------------------------

    {
        omi::Transform* transform = new omi::Transform(
                "",
                glm::vec3( 0.0f, 2.0f, 0.0f ),
                glm::vec3(),
                glm::vec3( 1.0f, 1.0f, 1.0f )
        );
        m_components.add( transform );
        omi::PointLight* pointLight = new omi::PointLight(
                "",
                transform,
                1.0f,
                glm::vec3( 1.0f, 1.0f, 1.0f ),
                0.05f,
                0.2f,
                0.00005f
        );
        m_components.add( pointLight );
    }

    //----------------------------------FLOOR-----------------------------------

    {
        omi::Mesh* floorMesh =
                    omi::ResourceManager::getMesh( "facility_floor", "", NULL );
        floorMesh->getMaterial().specular = new omi::Specular(
                64.0f,
                glm::vec3( 0.5f, 0.5f, 0.5f ),
                omi::ResourceManager::getTexture( "facility_floor_spec" )
        );
        m_components.add( floorMesh );
    }

    {
        omi::Transform* transform = new omi::Transform(
                "",
                glm::vec3( 3.0f, 0.0f, 0.0f ),
                glm::vec3(),
                glm::vec3( 1.0f, 1.0f, 1.0f )
        );
        m_components.add( transform );
        omi::Mesh* floorMesh = omi::ResourceManager::getMesh(
                "facility_floor",
                "",
                transform
        );
        floorMesh->getMaterial().specular = new omi::Specular(
                64.0f,
                glm::vec3( 0.5f, 0.5f, 0.5f ),
                omi::ResourceManager::getTexture( "facility_floor_spec" )
        );
        m_components.add( floorMesh );
    }

    {
        omi::Transform* transform = new omi::Transform(
                "",
                glm::vec3( -3.0f, 0.0f, 0.0f ),
                glm::vec3(),
                glm::vec3( 1.0f, 1.0f, 1.0f )
        );
        m_components.add( transform );
        omi::Mesh* floorMesh = omi::ResourceManager::getMesh(
                "facility_floor",
                "",
                transform
        );
        floorMesh->getMaterial().specular = new omi::Specular(
                64.0f,
                glm::vec3( 0.5f, 0.5f, 0.5f ),
                omi::ResourceManager::getTexture( "facility_floor_spec" )
        );
        m_components.add( floorMesh );
    }

    {
        omi::Transform* transform = new omi::Transform(
                "",
                glm::vec3( 0.0f, 0.0f, 3.0f ),
                glm::vec3(),
                glm::vec3( 1.0f, 1.0f, 1.0f )
        );
        m_components.add( transform );
        omi::Mesh* floorMesh = omi::ResourceManager::getMesh(
                "facility_floor",
                "",
                transform
        );
        floorMesh->getMaterial().specular = new omi::Specular(
                64.0f,
                glm::vec3( 0.5f, 0.5f, 0.5f ),
                omi::ResourceManager::getTexture( "facility_floor_spec" )
        );
        m_components.add( floorMesh );
    }

    {
        omi::Transform* transform = new omi::Transform(
                "",
                glm::vec3( 0.0f, 0.0f, -3.0f ),
                glm::vec3(),
                glm::vec3( 1.0f, 1.0f, 1.0f )
        );
        m_components.add( transform );
        omi::Mesh* floorMesh = omi::ResourceManager::getMesh(
                "facility_floor",
                "",
                transform
        );
        floorMesh->getMaterial().specular = new omi::Specular(
                64.0f,
                glm::vec3( 0.5f, 0.5f, 0.5f ),
                omi::ResourceManager::getTexture( "facility_floor_spec" )
        );
        m_components.add( floorMesh );
    }
}

void TestEntity::update()
{
    // do nothing
}
