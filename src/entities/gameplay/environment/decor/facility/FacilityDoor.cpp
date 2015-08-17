#include "src/entities/gameplay/environment/decor/facility/FacilityDoor.hpp"

FacilityDoor::FacilityDoor( omi::Transform* baseTransform, float dir )
    :
    Decor( baseTransform ),
    m_dir( dir )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void FacilityDoor::init()
{
    // rotate
    omi::Transform* transform = new omi::Transform(
            "",
            m_baseTransform,
            glm::vec3(),
            glm::vec3( 0.0f, m_dir, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( transform );

    // add geometry
    omi::Mesh* frame = omi::ResourceManager::getMesh(
            "facility_door_1_frame", "", transform );
    frame->getMaterial().specular = new omi::Specular(
            128.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "facility_skirting_spec" )
    );
    m_meshComp.push_back( frame );
    m_components.add( frame );

    omi::Mesh* panel = omi::ResourceManager::getMesh(
            "facility_door_1_panel", "", transform );
    panel->getMaterial().specular = new omi::Specular(
            64.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "facility_door_1_panel_spec" )
    );
    m_meshComp.push_back( panel );
    m_components.add( panel );

    // omi::Mesh* handle = omi::ResourceManager::getMesh(
    //         "facility_door_1_handle", "", transform );
    // handle->getMaterial().specular = new omi::Specular(
    //         64.0f,
    //         glm::vec3( 1.0f, 1.0f, 1.0f ),
    //         omi::ResourceManager::getTexture( "facility_support_spec" )
    // );
    // m_meshComp.push_back( handle );
    // m_components.add( handle );
}

void FacilityDoor::update()
{
}
