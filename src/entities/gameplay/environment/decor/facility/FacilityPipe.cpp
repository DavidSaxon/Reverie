#include "src/entities/gameplay/environment/decor/facility/FacilityPipe.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

FacilityPipe::FacilityPipe( omi::Transform* baseTransform )
    :
    Decor( baseTransform )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void FacilityPipe::init()
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
            "facility_pipe", "", transform );
    mesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "facility_support_spec" )
    );
    m_meshComp.push_back( mesh );
    m_components.add( mesh );
}

void FacilityPipe::update()
{
}

