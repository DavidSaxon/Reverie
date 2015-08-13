#include "src/entities/gameplay/Phobetor.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Phobetor::init()
{
    omi::Transform* pos = new omi::Transform(
            "",
            glm::vec3( 0.0F, 0.0F, -13.5F ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( pos );

    omi::KeyFrameMesh* mesh = omi::ResourceManager::getKeyFrameMesh(
                "phobetor_basic", "", pos );
    mesh->castShadow = true;
    mesh->receiveShadows = false;
    m_components.add( mesh );
}

void Phobetor::update()
{
}
