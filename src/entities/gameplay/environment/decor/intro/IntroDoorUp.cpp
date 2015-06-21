#include "src/entities/gameplay/environment/decor/intro/IntroDoorUp.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntroDoorUp::IntroDoorUp( omi::Transform* baseTransform )
    :
    Decor( baseTransform )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void IntroDoorUp::init()
{
    // rotate
    omi::Transform* transform = new omi::Transform(
            "",
            m_baseTransform,
            glm::vec3(),
            glm::vec3( 0.0f, 90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( transform );

    // add geometry
    omi::Mesh* frame = omi::ResourceManager::getMesh(
            "intro_door_1_frame", "", transform );
    m_components.add( frame );
    omi::Mesh* panel = omi::ResourceManager::getMesh(
            "intro_door_1_panel", "", transform );
    m_components.add( panel );
    omi::Mesh* handle = omi::ResourceManager::getMesh(
            "intro_door_1_handle", "", transform );
    handle->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_components.add( handle );
}

void IntroDoorUp::update()
{
}
