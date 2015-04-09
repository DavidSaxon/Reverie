#include "Player.hpp"

#include "src/data/Globals.hpp"
#include "src/omicron/input/Input.hpp"

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the base speed at which the player moves
static const float MOVE_BASE_SPEED = 0.075f;
// the base speed at which the player can look around
static const float LOOK_BASE_SPEED = 0.055f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Player::init()
{
    // main player transform
    m_transform = new omi::Transform(
            "",
            glm::vec3(),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_transform );

    // create the camera
    m_camT = new omi::Transform(
            "",
            m_transform,
            glm::vec3( 0.0f, 1.7f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_camT );
    omi::Camera* camera =
            new omi::Camera( "", omi::cam::PERSPECTIVE, m_camT );
    camera->setExposure( 1.2f );
    m_components.add( camera );

    // collision checker
    m_collisionChecker = new omi::CollisionChecker( "" );
    m_collisionChecker->addBounding(
            new omi::BoundingRect( glm::vec2( 0.75f, 0.75f ), m_transform ) );
    m_components.add( m_collisionChecker );

    // TODO: fix
    // the flare light source
    omi::Mesh* flare =
        omi::ResourceManager::getMesh( "flare", "", NULL );
    flare->overlay = true;
    flare->castShadow = false;
    m_components.add( flare );
}

void Player::update()
{
    // skip if omicron is paused
    if ( global::pause )
    {
        return;
    }

    // don't perform key presses if omicron doesn't have focus
    if ( omi::omi_hasFocus )
    {
        look();
        move();
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Player::look()
{
    // rotate the camera based on how far the mouse has moved
    m_camT->rotation.x +=
        ( omi::displaySettings.getCentre().y - omi::input::getMousePos().y ) *
        LOOK_BASE_SPEED * global::lookSensitivity;
    m_transform->rotation.y +=
        ( omi::displaySettings.getCentre().x - omi::input::getMousePos().x ) *
        LOOK_BASE_SPEED * global::lookSensitivity;
}

void Player::move()
{
    // calculate the distance the player is being asked to move
    glm::vec3 moveDis;
    float moveSpeed = MOVE_BASE_SPEED * omi::fpsManager.getTimeScale();

    // forward
    if ( omi::input::isKeyPressed( global::keyForwards ) )
    {
        moveDis.z += -util::math::cosd( m_transform->rotation.y ) * moveSpeed;
        moveDis.x += -util::math::sind( m_transform->rotation.y ) * moveSpeed;
    }
    // backwards
    if ( omi::input::isKeyPressed( global::keyBackwards ) )
    {
        moveDis.z += util::math::cosd( m_transform->rotation.y ) * moveSpeed;
        moveDis.x += util::math::sind( m_transform->rotation.y ) * moveSpeed;
    }
    // left
    if ( omi::input::isKeyPressed( global::keyLeft ) )
    {
        moveDis.z +=  util::math::sind( m_transform->rotation.y ) * moveSpeed;
        moveDis.x += -util::math::cosd( m_transform->rotation.y ) * moveSpeed;
    }
    // right
    if ( omi::input::isKeyPressed( global::keyRight ) )
    {
        moveDis.z += -util::math::sind( m_transform->rotation.y ) * moveSpeed;
        moveDis.x +=  util::math::cosd( m_transform->rotation.y ) * moveSpeed;
    }

    // TODO: walk animation!

    // TODO: diagonal move

    // TODO: key release shit

    // TODO: friction

    // store the original move distance
    // glm::vec3 orgMove( moveDis );
    // // get the actual move distance based on obstacles
    moveDis = m_collisionChecker->forwardBestCheck( moveDis, "wall" );

    // // apply friction
    // glm::vec3 moveScale(
    //         fabs( orgMove.x ),
    //         fabs( orgMove.y ),
    //         fabs( orgMove.z )
    // );
    // glm::vec3 tempMove( moveDis );

    // if ( moveScale.x > ( moveScale.z * 2.0f ) )
    // {
    //     if ( fabs( orgMove.x - tempMove.x ) > moveScale.x )
    //     {
    //         moveDis.z = tempMove.z * ( moveScale.x / ( moveScale.z * 3.0f ) );
    //     }
    // }

    // if ( fabs( orgMove.x - tempMove.x ) > ( moveScale.x / 2.0f ) )
    // {
    //     moveDis.z = 0.0f;
    // }
    // if ( fabs( orgMove.z - tempMove.z ) > ( moveScale.z / 2.0f ) )
    // {
    //     moveDis.x = 0.0f;
    // }

    // final shift the transformation
    m_transform->translation += moveDis;

    // m_transform->translation += moveDis;
}
