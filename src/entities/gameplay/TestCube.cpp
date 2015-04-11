#include "TestCube.hpp"

#include "src/omicron/input/Input.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TestCube::init()
{
    m_t1 = new omi::Transform(
            "",
            glm::vec3( 0.0f, 1.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 0.7f, 0.7f, 0.7f )
    );
    m_components.add( m_t1 );

    omi::Mesh* testCube = omi::ResourceManager::getMesh(
            "test_cube", "", m_t1 );
    m_components.add( testCube );
}

void TestCube::update()
{
    if ( omi::input::isKeyPressed( omi::input::key::UP ) )
    {
        m_t1->rotation.x -= 0.35f * omi::fpsManager.getTimeScale();
    }
    else if ( omi::input::isKeyPressed( omi::input::key::DOWN ) )
    {
        m_t1->rotation.x += 0.35f * omi::fpsManager.getTimeScale();
    }

    if ( omi::input::isKeyPressed( omi::input::key::LEFT ) )
    {
        m_t1->rotation.y -= 0.35f * omi::fpsManager.getTimeScale();
    }
    else if ( omi::input::isKeyPressed( omi::input::key::RIGHT ) )
    {
        m_t1->rotation.y += 0.35f * omi::fpsManager.getTimeScale();
    }


    if ( omi::input::isKeyPressed( omi::input::key::N ) )
    {
        m_t1->rotation.z -= 0.35f * omi::fpsManager.getTimeScale();
    }
    else if ( omi::input::isKeyPressed( omi::input::key::M ) )
    {
        m_t1->rotation.z += 0.35f * omi::fpsManager.getTimeScale();
    }


    if ( omi::input::isKeyPressed( omi::input::key::R ) )
    {
        m_t1->rotation = glm::vec3();
    }
}
