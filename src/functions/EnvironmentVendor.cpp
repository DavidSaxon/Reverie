#include "EnvironmentVendor.hpp"

#include "src/data/Intro.hpp"
#include "src/entities/gameplay/environment/decor/intro/IntroDoorDown.hpp"
#include "src/entities/gameplay/environment/decor/intro/IntroDoorLeft.hpp"
#include "src/entities/gameplay/environment/decor/intro/IntroDoorRight.hpp"
#include "src/entities/gameplay/environment/decor/intro/IntroDoorUp.hpp"
#include "src/entities/gameplay/environment/decor/intro/IntroLight1.hpp"
#include "src/functions/Direction.hpp"


namespace vendor
{

//------------------------------------------------------------------------------
//                               PRIVATE FUNCTIONS
//------------------------------------------------------------------------------

void vendDecorIntro(
        omi::Transform* transform,
        unsigned long mask,
        std::vector<Decor*>& decor );

//------------------------------------------------------------------------------
//                                PUBLIC FUNCTIONS
//------------------------------------------------------------------------------

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
            m->castShadow = false;
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
            m->castShadow = false;
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
            m->castShadow = false;
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
            m->castShadow = false;
            return m;
        }
        // TODO: other stages
        default:
        {
            return NULL;
        }
    }
}

omi::Mesh* vendSkirtingCorner(
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
                    "intro_skirting_corner", "", t );
            m->castShadow = false;
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
    // the size of the collider bounding
    const float colliderConst = 0.1f;
    glm::vec2 colliderSize( 0.0f, 0.0f );

    const float shiftConst = ( global::TILE_SIZE + colliderConst ) / 2.0f;

    // get the actual direction of the collider
    global::environment::Direction finalDirection =
        static_cast<global::environment::Direction>(
                ( colliderDirection + baseDirection ) % 4 );

    // return the collider based on direction
    switch ( finalDirection )
    {
        case global::environment::NORTH:
        {
            dirVector = glm::vec3( 0.0f, 0.0f, -shiftConst );
            dirEnum = omi::bounding::UP;
            colliderSize = glm::vec2( global::TILE_SIZE, colliderConst );
            break;
        }
        case global::environment::EAST:
        {
            dirVector = glm::vec3( shiftConst, 0.0f, 0.0f );
            dirEnum = omi::bounding::RIGHT;
            colliderSize = glm::vec2( colliderConst, global::TILE_SIZE );
            break;
        }
        case global::environment::SOUTH:
        {
            dirVector = glm::vec3( 0.0f, 0.0f, shiftConst );
            dirEnum = omi::bounding::DOWN;
            colliderSize = glm::vec2( global::TILE_SIZE, colliderConst );
            break;
        }
        case global::environment::WEST:
        {
            dirVector = glm::vec3( -shiftConst, 0.0f, 0.0f );
            dirEnum = omi::bounding::LEFT;
            colliderSize = glm::vec2( colliderConst, global::TILE_SIZE );
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
            colliderSize,
            t,
            dirEnum
    ) );

    return c;
}

void vendDecor(
        global::environment::Stage stage,
        omi::Transform* baseTransform,
        unsigned long mask,
        std::vector<Decor*>& decor )
{
    // calculate the transform
    omi::Transform* t = new omi::Transform(
            "",
            baseTransform,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );

    switch ( stage )
    {
        case global::environment::INTRO:
        {
            vendDecorIntro( t, mask, decor );
            break;
        }
        // TODO: other stages
        default:
        {
            break;
        }
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void vendDecorIntro(
        omi::Transform* transform,
        unsigned long mask,
        std::vector<Decor*>& decor )
{
    // check against mask
    if ( mask & global::environment::DECOR_LIGHT_1 )
    {
        decor.push_back( new IntroLight1( transform ) );
    }
    if ( mask & global::environment::DECOR_LIGHT_2 )
    {
        decor.push_back( new IntroLight1( transform, true ) );
    }
    if ( mask & global::environment::DECOR_LIGHT_3 )
    {
        decor.push_back( new IntroLight1( transform, true, true ) );
    }
    if ( mask & global::environment::DECOR_PROP_1 )
    {
        decor.push_back( new IntroDoorRight( transform ) );
    }
    if ( mask & global::environment::DECOR_PROP_2 )
    {
        decor.push_back( new IntroDoorLeft( transform ) );
    }
    if ( mask & global::environment::DECOR_PROP_3 )
    {
        decor.push_back( new IntroDoorUp( transform ) );
    }
    if ( mask & global::environment::DECOR_PROP_4 )
    {
        decor.push_back( new IntroDoorDown( transform ) );
    }

    // TODO: other
}

} // namespace vendor
