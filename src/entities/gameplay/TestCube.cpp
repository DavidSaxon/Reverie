#include "TestCube.hpp"

#include "src/omicron/input/Input.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestCube::init()
{
    m_parentT = new omi::Transform(
            "",
            glm::vec3( 0.0f, 1.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 0.7f, 0.7f, 0.7f )
    );
    m_components.add( m_parentT );

    omi::Mesh* testCube = omi::ResourceManager::getMesh(
            "test_cube", "", m_parentT );
    m_components.add( testCube );

    m_childT = new omi::Transform(
            "",
            m_parentT,
            glm::vec3( 0.0f, 0.0f, -1.3f ),
            glm::vec3( 45.0f, 0.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_childT );

    omi::Mesh* testCubeChild = omi::ResourceManager::getMesh(
        "test_cube", "", m_childT );
    m_components.add( testCubeChild );
}

void TestCube::update()
{
    if ( omi::input::isKeyPressed( omi::input::key::UP ) )
    {
        m_parentT->rotation.x -= 0.35f * omi::fpsManager.getTimeScale();
    }
    else if ( omi::input::isKeyPressed( omi::input::key::DOWN ) )
    {
        m_parentT->rotation.x += 0.35f * omi::fpsManager.getTimeScale();
    }

    if ( omi::input::isKeyPressed( omi::input::key::LEFT ) )
    {
        m_parentT->rotation.y -= 0.35f * omi::fpsManager.getTimeScale();
    }
    else if ( omi::input::isKeyPressed( omi::input::key::RIGHT ) )
    {
        m_parentT->rotation.y += 0.35f * omi::fpsManager.getTimeScale();
    }


    if ( omi::input::isKeyPressed( omi::input::key::N ) )
    {
        m_parentT->rotation.z -= 0.35f * omi::fpsManager.getTimeScale();
    }
    else if ( omi::input::isKeyPressed( omi::input::key::M ) )
    {
        m_parentT->rotation.z += 0.35f * omi::fpsManager.getTimeScale();
    }


    if ( omi::input::isKeyPressed( omi::input::key::R ) )
    {
        m_parentT->rotation = glm::vec3();
    }
}
