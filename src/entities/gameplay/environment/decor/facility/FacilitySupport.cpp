#include "src/entities/gameplay/environment/decor/facility/FacilitySupport.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

FacilitySupport::FacilitySupport( omi::Transform* baseTransform )
    :
    Decor( baseTransform )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void FacilitySupport::init()
{
    // transform
    omi::Transform* transform = new omi::Transform(
            "",
            m_baseTransform,
            glm::vec3(),
            glm::vec3(),
            glm::vec3( 1.0F, 1.0F, 1.0F )
    );
    m_components.add( transform );

    // add geometry
    omi::Mesh* mesh = omi::ResourceManager::getMesh(
            "facility_support", "", transform );
    mesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 1.0F, 1.0F, 1.0F ),
            omi::ResourceManager::getTexture( "facility_support_spec" )
    );
    mesh->castShadow = true;
    mesh->receiveShadows = false;
    m_meshComp.push_back( mesh );
    m_components.add( mesh );
}

void FacilitySupport::update()
{
}

