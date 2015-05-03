#include "EnvironmentVendor.hpp"

#include "src/functions/Direction.hpp"

namespace vendor
{

omi::Mesh* vendFloorTile(
        global::environment::Stage stage,
        omi::Transform* baseTransform )
{
    switch ( stage )
    {
        case global::environment::INTRO:
        {
            return omi::ResourceManager::getMesh(
                    "intro_floor", "", baseTransform );
        }
        // TODO: other stages
        default:
        {
            return NULL;
        }
    }
}

omi::Mesh* vendCeilingTile(
        global::environment::Stage stage,
        omi::Transform* baseTransform )
{
    switch ( stage )
    {
        case global::environment::INTRO:
        {
            return omi::ResourceManager::getMesh(
                    "intro_ceiling", "", baseTransform );
        }
        // TODO: other stages
        default:
        {
            return NULL;
        }
    }
}

omi::Mesh* vendWallTile(
        global::environment::Stage stage,
        omi::Transform* baseTransform,
        global::environment::Direction direction )
{
    // create the secondary transform
    omi::Transform* t = new omi::Transform(
            "",
            baseTransform,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3( 0.0f, dir::toAngle( direction ), 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    // the mesh point
    omi::Mesh* m = NULL;

    switch ( stage )
    {
        case global::environment::INTRO:
        {
            m = omi::ResourceManager::getMesh(
                    "intro_wall", "", t );
            return m;
        }
        // TODO: other stages
        default:
        {
            return NULL;
        }
    }
}

omi::CollisionDetector* vendWallCollider(
        omi::Transform* baseTransform,
        global::environment::Direction baseDirection,
        global::environment::Direction colliderDirection )
{
    // TODO:

    unsigned vecDir = ( colliderDirection + baseDirection ) % 4;

    return NULL;
}

} // namespace vendor
