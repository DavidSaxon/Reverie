#include "Player.hpp"

#include "src/data/Globals.hpp"
#include "src/omicron/input/Input.hpp"

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the base speed at which the player moves
static const float MOVE_BASE_SPEED = 0.03f;
// the base speed at which the player can look around
static const float LOOK_BASE_SPEED = 0.055f;

// the speed at which the player steps
static const float STEP_SPEED = 185.0f;
// the height of the player's steps
static const float STEP_HEIGHT = 0.026f;
// the rotation amount of the step animation
static const float STEP_ROT_AMOUNT = 0.185f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Player::Player()
    :
    m_zPriority    ( player::Z_NONE ),
    m_yPriority    ( player::Y_NONE ),
    m_stepAnimation( 0.0f )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Player::init()
{
    // main player transform
    m_transform = new omi::Transform(
            "",
            glm::vec3( 0.0f, 0.0f, 2.0f ),
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
    // omi::Mesh* flare =
    //     omi::ResourceManager::getMesh( "flare", "", NULL );
    // flare->overlay = true;
    // flare->castShadow = false;
    // m_components.add( flare );
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
        LOOK_BASE_SPEED * global::lookSensitivity * global::timeScale;
    m_camT->rotation.y +=
        ( omi::displaySettings.getCentre().x - omi::input::getMousePos().x ) *
        LOOK_BASE_SPEED * global::lookSensitivity * global::timeScale;
}

void Player::move()
{
    // calculate the distance the player is being asked to move
    glm::vec3 moveDis;
    float moveSpeed =
            MOVE_BASE_SPEED *
            omi::fpsManager.getTimeScale() *
            global::timeScale;
    // whether the step animation has been applied yet or not
    bool stepApplied = false;

    // forward
    if ( omi::input::isKeyPressed( global::keyForwards ) )
    {
        if ( m_zPriority != player::Z_BACKWARD )
        {
            // set priority
            m_zPriority = player::Z_FORWARD;
            // move forwards
            moveDis.z +=
                    -util::math::cosd( m_camT->rotation.y ) * moveSpeed;
            moveDis.x +=
                    -util::math::sind( m_camT->rotation.y ) * moveSpeed;
            // increase the step animation
            m_stepAnimation += moveSpeed * STEP_SPEED;
            stepApplied = true;
        }
    }
    else
    {
        m_zPriority = player::Z_NONE;
    }
    // backwards
    if ( omi::input::isKeyPressed( global::keyBackwards ) )
    {
        if ( m_zPriority != player::Z_FORWARD )
        {
            // set priority
            m_zPriority = player::Z_BACKWARD;
            // move backwards
            moveDis.z +=
                    util::math::cosd( m_camT->rotation.y ) * moveSpeed;
            moveDis.x +=
                    util::math::sind( m_camT->rotation.y ) * moveSpeed;
            // decrease the step animation
            m_stepAnimation -= moveSpeed * STEP_SPEED;
            stepApplied = true;
        }
    }
    else
    {
        m_zPriority = player::Z_NONE;
    }
    // left
    if ( omi::input::isKeyPressed( global::keyLeft ) )
    {
        moveDis.z +=  util::math::sind( m_camT->rotation.y ) * moveSpeed;
        moveDis.x += -util::math::cosd( m_camT->rotation.y ) * moveSpeed;
        // if not moving along z increase the step animation
        if ( !stepApplied )
        {
            m_stepAnimation += moveSpeed * STEP_SPEED;
            stepApplied = true;
        }
    }
    // right
    if ( omi::input::isKeyPressed( global::keyRight ) )
    {
        moveDis.z += -util::math::sind( m_camT->rotation.y ) * moveSpeed;
        moveDis.x +=  util::math::cosd( m_camT->rotation.y ) * moveSpeed;
        // if not moving along z decrease the step animation
        if ( !stepApplied )
        {
            m_stepAnimation -= moveSpeed * STEP_SPEED;
        }
    }

    // TODO: key release shit

    // get the actual move distance based on obstacles
    moveDis = m_collisionChecker->forwardBestCheck( moveDis, "wall" );

    // final shift the transformation
    m_transform->translation += moveDis;


    // TODO: clamp stepAni to 360
    // TODO: step should be done on move amount and direction

    // animate the players step
    // TODO: should this use post collision data?
    m_transform->translation.y =
            util::math::sind( m_stepAnimation ) * STEP_HEIGHT;
    m_transform->rotation.z =
            util::math::sind( m_stepAnimation ) * STEP_ROT_AMOUNT;
}

