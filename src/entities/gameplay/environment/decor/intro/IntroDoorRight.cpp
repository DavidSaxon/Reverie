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
            "intro_door_1_frame", "", NULL );
    m_meshComp.push_back( frame );
    m_components.add( frame );
    omi::Mesh* panel = omi::ResourceManager::getMesh(
            "intro_door_1_panel", "", NULL );
    m_meshComp.push_back( panel );
    m_components.add( panel );
    omi::Mesh* handle = omi::ResourceManager::getMesh(
            "intro_door_1_handle", "", NULL );
    handle->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_meshComp.push_back( handle );
    m_components.add( handle );
}

void IntroDoorRight::update()
{
}
