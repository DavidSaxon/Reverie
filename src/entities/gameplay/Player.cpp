#include "Player.hpp"

#include "lib/Utilitron/MathUtil.hpp"

#include "src/data/Globals.hpp"
#include "src/omicron/input/Input.hpp"

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the base speed at which the player moves
static const float MOVE_BASE_SPEED = 0.035f;
// move acceleration speed
static const float MOVE_ACCEL_SPEED = 0.06f;
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
    m_zPriority        ( player::Z_NONE ),
    m_yPriority        ( player::Y_NONE ),
    m_stepAnimation    ( 0.0f ),
    m_upAccel          ( 0.0f ),
    m_downAccel        ( 0.0f ),
    m_leftAccel        ( 0.0f ),
    m_rightAccel       ( 0.0f ),
    m_stepSoundAni     ( 0.5f ),
    m_heartBeatSlowId  ( 0 ),
    m_camShake         ( 0.0f ),
    m_shakeUp          ( true ),
    m_shakeUpTimer     ( 0.0f ),
    m_runDisabled      ( false ),
    m_footstepsDisabled( false ),
    m_autoMove         ( false ),
    m_autoMoveAngle    ( 0.0F ),
    m_autoLook         ( false ),
    m_autoLookLow      ( 0.0F ),
    m_autoLookHigh     ( 0.0F ),
    m_autoLookDone     ( false )
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
            glm::vec3( 0.0f, 0.0f, -5.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_transform );

    // create the camera
    m_camT = new omi::Transform(
            "",
            m_transform,
            glm::vec3( 0.0f, 1.85f, 0.0f ),
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

    // initialize music
    initMusic();
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

void Player::setMusic( player::Music music )
{
    // TODO:
}

void Player::playMusic()
{
    m_currentMusic->play();
}

void Player::pauseMusic()
{
    m_currentMusic->pause();
}

void Player::setCamShake( float camShake )
{
    m_camShake = camShake;
}

void Player::setRunDisabled( bool state )
{
    m_runDisabled = state;
}

void Player::setFootStepsDisabled( bool state )
{
    m_footstepsDisabled = state;
}

void Player::playHeartBeatSlow()
{
    m_heartBeatSlowId = omi::ResourceManager::getSound( "heart_beat_slow" );
    omi::SoundPool::play(
            m_heartBeatSlowId,
            true,
            1.0f
    );
}

void Player::stopHeartBeatSlow()
{
    omi::SoundPool::stop( m_heartBeatSlowId, 0 );
}

void Player::autoMoveToPosition( const glm::vec3& position )
{
    m_autoMove = true;
    m_autoMovePos = position;

    // calculate the angle to auto-move at
    m_autoMoveAngle = omi::vecutil::angleBetween(
            m_autoMovePos.xz(),
            m_transform->translation.xz()
    );
}

void Player::disableAutoMove()
{
    m_autoMove = false;
}

void Player::autoLookAtAngle( const glm::vec2& angle )
{
    m_autoLook = true;
    m_autoLookDone = false;
    m_autoLookAngle = angle;

    m_autoLookLow = m_autoLookAngle.y;
    m_autoLookHigh = m_autoLookLow + 180.0F;

    m_autoLookInverseCheck = false;
    if ( m_autoLookAngle.y > 180.0F )
    {
        m_autoLookInverseCheck = true;
        m_autoLookHigh = m_autoLookLow - 180.0F;
    }
}

void Player::disableAutoLook()
{
    m_autoLook = false;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Player::look()
{
    // rotate the camera based on how far the mouse has moved
    if ( !m_autoLook )
    {
        m_camT->rotation.x +=
            ( omi::displaySettings.getCentre().y -
              omi::input::getMousePos().y          ) *
            LOOK_BASE_SPEED * global::lookSensitivity * global::timeScale;
        m_camT->rotation.y +=
            ( omi::displaySettings.getCentre().x -
              omi::input::getMousePos().x          ) *
            LOOK_BASE_SPEED * global::lookSensitivity * global::timeScale;
    }

    // apply camera shake
    if ( m_camShake > 0.0f )
    {
        // change upwards shake?
        float r = ( static_cast< float >( rand() % 1000 ) / 1000.0f ) + 0.01f;
        m_shakeUpTimer += m_camShake * r;
        if ( m_shakeUpTimer >= 1.0f )
        {
            m_shakeUpTimer -= 1.0f;
            m_shakeUp = !m_shakeUp;
        }
        // shake up
        if ( m_shakeUp )
        {
            m_camT->rotation.x += 0.1f;
        }
        else
        {
            m_camT->rotation.x -= 0.1f;
        }
    }

    // clamp up/down look
    m_camT->rotation.x = util::math::clamp<float>(
            m_camT->rotation.x,
            -LOOK_CLAMP,
            LOOK_CLAMP
    );

    // apply auto look
    bool lookLow = false;
    if ( m_autoLook )
    {

        const float autoLookSpeed = 1.55F;

        if ( m_camT->rotation.x < m_autoLookAngle.x )
        {
            m_camT->rotation.x +=
                    autoLookSpeed * omi::fpsManager.getTimeScale();
            if ( m_camT->rotation.x > m_autoLookAngle.x )
            {
                m_camT->rotation.x = m_autoLookAngle.x;
            }
        }
        else if ( m_camT->rotation.x > m_autoLookAngle.x )
        {
            m_camT->rotation.x -=
                    autoLookSpeed * omi::fpsManager.getTimeScale();
            if ( m_camT->rotation.x < m_autoLookAngle.x )
            {
                m_camT->rotation.x = m_autoLookAngle.x;
            }
        }

        if ( !m_autoLookDone )
        {
            bool lookCheck = false;
            if ( !m_autoLookInverseCheck )
            {
                lookCheck = m_camT->rotation.y >= m_autoLookLow &&
                            m_camT->rotation.y <  m_autoLookHigh;
            }
            else
            {
                lookCheck = !( m_camT->rotation.y <= m_autoLookLow &&
                               m_camT->rotation.y >  m_autoLookHigh   );
            }

            if ( lookCheck )
            {
                m_camT->rotation.y -=
                        autoLookSpeed * omi::fpsManager.getTimeScale();
                lookLow = true;
            }
            else
            {
                m_camT->rotation.y +=
                        autoLookSpeed * omi::fpsManager.getTimeScale();
            }
        }
    }

    // wrap around y angle
    if ( m_camT->rotation.y < 0.0F )
    {
        m_camT->rotation.y += 360.0F;
    }
    else if ( m_camT->rotation.y >= 360.0F )
    {
        m_camT->rotation.y -= 360.0F;
    }

    // check for the end of auto look
    if ( m_autoLook && !m_autoLookDone )
    {
        bool lookCheck = false;
        if ( !m_autoLookInverseCheck )
        {
            lookCheck = m_camT->rotation.y >= m_autoLookLow &&
                        m_camT->rotation.y <  m_autoLookHigh;
        }
        else
        {
            lookCheck = !( m_camT->rotation.y <= m_autoLookLow &&
                           m_camT->rotation.y >  m_autoLookHigh   );
        }

        if ( lookCheck && !lookLow )
        {
            m_camT->rotation.y = m_camT->rotation.y;
            m_autoLookDone = true;
        }
        else if ( !lookCheck && lookLow )
        {
            m_camT->rotation.y = m_camT->rotation.y;
            m_autoLookDone = true;
        }
    }
}

void Player::move()
{
    glm::vec3 moveDis;

    // forward
    if ( omi::input::isKeyPressed( global::keyForwards ) )
    {
        // apply acceleration
        if ( m_upAccel < 1.0f )
        {
            m_upAccel += MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_upAccel = 1.0f;
        }

        // apply movement
        moveDis.z -= m_upAccel;
    }
    else
    {
        // decelerate
        if ( m_upAccel > 0.0f )
        {
            m_upAccel -= MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_upAccel = 0.0f;
        }
    }
    // backwards
    if ( omi::input::isKeyPressed( global::keyBackwards ) )
    {
        // apply acceleration
        if ( m_downAccel < 1.0f )
        {
            m_downAccel += MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_downAccel = 1.0f;
        }

        // apply movement
        moveDis.z += m_downAccel;
    }
    else
    {
        // decelerate
        if ( m_downAccel > 0.0f )
        {
            m_downAccel -= MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_downAccel = 0.0f;
        }
    }
    // left
    if ( omi::input::isKeyPressed( global::keyLeft ) )
    {
        // apply acceleration
        if ( m_leftAccel < 1.0f )
        {
            m_leftAccel += MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_leftAccel = 1.0f;
        }

        // apply movement
        moveDis.x -= m_leftAccel;
    }
    else
    {
        // decelerate
        if ( m_leftAccel > 0.0f )
        {
            m_leftAccel -= MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_leftAccel = 0.0f;
        }
    }
    // right
    if ( omi::input::isKeyPressed( global::keyRight ) )
    {
        // apply acceleration
        if ( m_rightAccel < 1.0f )
        {
            m_rightAccel += MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_rightAccel = 1.0f;
        }

        // apply movement
        moveDis.x += m_rightAccel;
    }
    else
    {
        // decelerate
        if ( m_rightAccel > 0.0f )
        {
            m_rightAccel -= MOVE_ACCEL_SPEED * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_rightAccel = 0.0f;
        }
    }

    float moveSpeed =
            MOVE_BASE_SPEED *
            omi::fpsManager.getTimeScale() *
            global::timeScale;

    // override with auto-move
    if ( m_autoMove )
    {
        moveDis.x = util::math::cosd( m_autoMoveAngle );
        moveDis.z = util::math::sind( m_autoMoveAngle );
    }

    // calculated weighted move
    float moveTotal = fabs( moveDis.x ) + fabs( moveDis.z );
    if ( moveTotal > 1.0f )
    {
        moveDis.x /= moveTotal;
        moveDis.z /= moveTotal;
    }

    // apply step animation
    moveTotal = util::math::clamp< float >( moveTotal, 0.0f, 1.0f );
    float stepAnimationRate = moveTotal * moveSpeed * STEP_SPEED;

    // the multiplier for how animated the player is
    float animationBoost = 1.0f;

    // run key
    if ( omi::input::isKeyPressed( omi::input::key::LEFT_SHIFT ) &&
         !m_runDisabled && !m_autoMove )
    {
        moveSpeed         *= RUN_SPEED_MULTIPLIER;
        // TODO: apply based on move speed?
        stepAnimationRate *= RUN_STEP_MULTIPLIER;
        animationBoost    *= RUN_STEP_MULTIPLIER;
    }
    // TODO: REMOVE ME
    if ( omi::input::isKeyPressed( omi::input::key::LEFT_ALT ) && !m_autoMove )
    {
        moveSpeed         *= DEBUG_SPEED_MULTIPLIER;
        stepAnimationRate *= 0.0f;
        animationBoost    *= 0.0f;
    }

    moveDis.x *= moveSpeed;
    moveDis.z *= moveSpeed;

    // direct the move based on the look direction
    if ( !m_autoMove )
    {
        glm::vec3 tempMove( moveDis );
        moveDis.x =
                ( tempMove.z * util::math::sind( m_camT->rotation.y ) ) +
                ( tempMove.x * util::math::cosd( m_camT->rotation.y ) );
        moveDis.z =
                ( tempMove.z * util::math::cosd( m_camT->rotation.y ) ) +
                ( tempMove.x * -util::math::sind( m_camT->rotation.y ) );
    }

    // get the actual move distance based on obstacles
    float orgMoveDis = fabs( moveDis.x ) + fabs( moveDis.z );
    if ( !m_autoMove )
    {
        moveDis = m_collisionChecker->forwardBestCheck( moveDis, "wall" );
    }

    // slow animation based on how far the player has actually moved
    float slowPercent = 1.0f;
    if ( !util::math::floatEquals( orgMoveDis, 0.0f ) )
    {
        float newMoveDis = fabs( moveDis.x ) + fabs( moveDis.z );
        slowPercent = fabs( newMoveDis ) / fabs( orgMoveDis );
    }
    stepAnimationRate *= slowPercent;

    // TODO: this needs fixing
    // resolve and clamp auto move
    if ( m_autoMove )
    {
        if ( m_autoMoveAngle > 180.0F )
        {
            if ( ( m_transform->translation.z + moveDis.z ) < m_autoMovePos.z )
            {
                moveDis = glm::vec3( 0.0F );
                stepAnimationRate = 0.0F;
            }
        }
        else
        {
            if ( ( m_transform->translation.z + moveDis.z ) > m_autoMovePos.z )
            {
                moveDis = glm::vec3( 0.0F );
                stepAnimationRate = 0.0F;
            }
        }
    }

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

    // step sound
    if ( moveTotal > 0.0f )
    {
        m_stepSoundAni += stepAnimationRate * animationBoost * 0.003f;
        if ( m_stepSoundAni >= 1.0f )
        {
            m_stepSoundAni = 0.0f;
            int r = ( rand() % 8 ) + 1;
            std::stringstream ss;
            ss << "footsteps_soft_" << r;
            // play sound
            if ( !m_footstepsDisabled )
            {
                omi::SoundPool::play(
                        omi::ResourceManager::getSound( ss.str() ),
                        false,
                        0.6f
                );
            }
        }
    }
    else
    {
        m_stepSoundAni = 0.5f;
    }
}

void Player::initMusic()
{
    m_introMusic = new omi::Music(
            "", "res/sound/music/welcome_to_the_reverie.ogg", 1.0f, true
    );
    m_components.add( m_introMusic );

    // set and play the current music
    m_currentMusic = m_introMusic;
    m_currentMusic->play();
}
