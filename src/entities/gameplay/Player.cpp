#include "Player.hpp"

#include "lib/Utilitron/MathUtil.hpp"

#include "src/data/Globals.hpp"
#include "src/omicron/input/Input.hpp"

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the base speed at which the player moves
static const float MOVE_BASE_SPEED = 0.03f;
// move multiplier when running
static const float RUN_SPEED_MULTIPLIER = 2.4f;
// multiplier for debug speed
static const float DEBUG_SPEED_MULTIPLIER = 7.5f;
// animation multiplier when running
static const float RUN_STEP_MULTIPLIER = 1.5f;
// the base speed at which the player can look around
static const float LOOK_BASE_SPEED = 0.055f;
// the angle at which up/down looking is clamped
static const float LOOK_CLAMP = 80.0f;

// the speed at which the player steps
static const float STEP_SPEED = 186.0f;
// the height of the player's steps
static const float STEP_HEIGHT = 0.01f;
// the rotation amount of the step animation
static const float STEP_ROT_AMOUNT = 0.25f;

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
    omi::Camera* camera = new omi::Camera(
            "",
            omi::cam::PERSPECTIVE,
            m_camT,
            0.01f,
            100.0f
    );
    camera->setExposure( 1.2f );
    m_components.add( camera );

    // collision detector
    omi::CollisionDetector* detector =
            new omi::CollisionDetector( "", "player", this );
    detector->addBounding(
            new omi::BoundingRect( glm::vec2( 0.75f, 0.75f ), m_transform ) );
    m_components.add( detector );

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

    // TODO: MOVE TO MUSIC PLAYER ENTITIY
    // music
    omi::Music* music = new omi::Music(
            "", "res/sound/music/welcome_to_the_reverie.ogg", 1.0f, true
    );
    m_components.add( music );
    music->play();
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

omi::Transform* Player::getTransform()
{
    return m_transform;
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

    // clamp up/down look
    m_camT->rotation.x = util::math::clamp<float>(
            m_camT->rotation.x,
            -LOOK_CLAMP,
            LOOK_CLAMP
    );
}

void Player::move()
{
    // calculate the distance the player is being asked to move
    glm::vec3 moveDis;
    float moveSpeed =
            MOVE_BASE_SPEED *
            omi::fpsManager.getTimeScale() *
            global::timeScale;
    // the step animation amount
    float stepAnimationRate = 0.0f;
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
            stepAnimationRate += moveSpeed * STEP_SPEED;
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
            stepAnimationRate -= moveSpeed * STEP_SPEED;
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
            stepAnimationRate += moveSpeed * STEP_SPEED;
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
            stepAnimationRate -= moveSpeed * STEP_SPEED;
        }
    }

    // the multiplier for how animated the player is
    float animationBoost = 1.0f;

    // run key
    if ( omi::input::isKeyPressed( omi::input::key::LEFT_SHIFT ) )
    {
        moveDis           *= RUN_SPEED_MULTIPLIER;
        stepAnimationRate *= RUN_STEP_MULTIPLIER;
        animationBoost    *= RUN_STEP_MULTIPLIER;
    }
    if ( omi::input::isKeyPressed( omi::input::key::LEFT_ALT ) )
    {
        moveDis           *= DEBUG_SPEED_MULTIPLIER;
        stepAnimationRate *= 0.0f;
        animationBoost    *= 0.0f;
    }

    // TODO: key release shit

    // get the actual move distance based on obstacles
    float orgMoveDis = fabs( moveDis.x ) + fabs( moveDis.z );
    moveDis = m_collisionChecker->forwardBestCheck( moveDis, "wall" );

    // slow animation based on how far the player has actually moved
    float slowPercent = 1.0f;
    if ( !util::math::floatEquals( orgMoveDis, 0.0f ) )
    {
        float newMoveDis = fabs( moveDis.x ) + fabs( moveDis.z );
        slowPercent = fabs( newMoveDis ) / fabs( orgMoveDis );
    }
    stepAnimationRate *= slowPercent;

    // final shift the transformation
    m_transform->translation += moveDis;
    // TODO: clamp stepAni to 360
    // TODO: step should be done on move amount and direction
    // apply the step animation
    m_stepAnimation += stepAnimationRate;

    // animate the players step
    m_transform->translation.y =
            -util::math::cosd( m_stepAnimation + 180.0f ) *
            STEP_HEIGHT * animationBoost;
    // m_transform->rotation.z =
    //         util::math::sind( m_stepAnimation ) *
    //         STEP_ROT_AMOUNT * animationBoost;
}

