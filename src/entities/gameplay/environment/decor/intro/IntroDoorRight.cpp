#include "src/entities/gameplay/environment/decor/intro/IntroDoorRight.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntroDoorRight::IntroDoorRight( omi::Transform* baseTransform )
    :
    Decor( baseTransform )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void IntroDoorRight::init()
{
    // add geometry
    omi::Mesh* frame = omi::ResourceManager::getMesh(
            "intro_door_1_frame", "", m_baseTransform );
    m_components.add( frame );
    omi::Mesh* panel = omi::ResourceManager::getMesh(
            "intro_door_1_panel", "", m_baseTransform );
    m_components.add( panel );
    omi::Mesh* handle = omi::ResourceManager::getMesh(
            "intro_door_1_handle", "", m_baseTransform );
    handle->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_components.add( handle );
}

void IntroDoorRight::update()
{
}
