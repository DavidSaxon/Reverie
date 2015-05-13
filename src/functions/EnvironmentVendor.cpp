#include "EnvironmentVendor.hpp"

#include "src/data/Intro.hpp"
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
            omi::Mesh* m = omi::ResourceManager::getMesh(
                    "intro_floor", "", baseTransform );
            // m->getMaterial().glow = new omi::Glow(
            //         intro::WALL_COLOUR.rgb(), intro::WALL_BRIGHTNESS );
            return m;
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
            omi::Mesh* m = omi::ResourceManager::getMesh(
                    "intro_ceiling", "", baseTransform );
            // m->getMaterial().glow = new omi::Glow(
            //         intro::WALL_COLOUR.rgb(), intro::WALL_BRIGHTNESS );
            return m;
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
            // m->getMaterial().glow = new omi::Glow(
            //         intro::WALL_COLOUR.rgb(), intro::WALL_BRIGHTNESS );
            return m;
        }
        // TODO: other stages
        default:
        {
            return NULL;
        }
    }
}

omi::Mesh* vendSkirting(
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
                    "intro_skirting", "", t );
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
        void* entity,
        omi::Transform* baseTransform,
        global::environment::Direction baseDirection,
        global::environment::Direction colliderDirection )
{
    // create the collider
    omi::CollisionDetector* c = new omi::CollisionDetector(
            "",
            global::WALL_COLLISION_GROUP,
            entity
    );
    // the direction vector for the bounding
    glm::vec3 dirVector( 0.0f, 0.0f, 0.0f );
    // the bounding direction
    omi::bounding::Direction dirEnum = omi::bounding::ALL;

    // get the actual direction of the collider
    global::environment::Direction finalDirection =
        static_cast<global::environment::Direction>(
                ( colliderDirection + baseDirection ) % 4 );

    // return the collider based on direction
    switch ( finalDirection )
    {
        case global::environment::NORTH:
        {
            dirVector = glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE );
            dirEnum = omi::bounding::UP;
            break;
        }
        case global::environment::EAST:
        {
            dirVector = glm::vec3( global::TILE_SIZE, 0.0f, 0.0f );
            dirEnum = omi::bounding::RIGHT;
            break;
        }
        case global::environment::SOUTH:
        {
            dirVector = glm::vec3( 0.0f, 0.0f, global::TILE_SIZE );
            dirEnum = omi::bounding::DOWN;
            break;
        }
        case global::environment::WEST:
        {
            dirVector = glm::vec3( -global::TILE_SIZE, 0.0f, 0.0f );
            dirEnum = omi::bounding::LEFT;
            break;
        }
    }

    // create and add the bounding to the collider
    omi::Transform* t = new omi::Transform(
            "",
            baseTransform->translation + dirVector,
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    c->addBounding( new omi::BoundingRect(
            glm::vec2( 3.0f, 3.0f ),
            t,
            dirEnum
    ) );

    return c;
}

} // namespace vendor
