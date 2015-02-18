#include "Player.hpp"

#include "src/omicron/input/Input.hpp"

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the base speed at which the player moves
static const float MOVE_BASE_SPEED = 0.075f;
// the base speed at which the player can look around
static const float LOOK_BASE_SPEED = 0.075f;

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
    camera->setExposure( 0.85f );
    m_components.add( camera );

    // the players right right arm
    m_rightArm =
        omi::ResourceManager::getMesh( "player_right_arm", "", NULL );
    m_rightArm->overlay = true;
    m_components.add( m_rightArm );
}

void Player::update()
{
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
          MOVE_BASE_SPEED * omi::fpsManager.getTimeScale();
    m_transform->rotation.y +=
        ( omi::displaySettings.getCentre().x - omi::input::getMousePos().x ) *
          MOVE_BASE_SPEED * omi::fpsManager.getTimeScale();
}

void Player::move()
{
    // calculate the distance the player is being asked to move
    glm::vec3 moveDis;
    float moveSpeed = MOVE_BASE_SPEED * omi::fpsManager.getTimeScale();

    // forward
    if ( omi::input::isKeyPressed( omi::input::key::W ) )
    {
        moveDis.z = -util::math::cosd( m_transform->rotation.y ) * moveSpeed;
        moveDis.x = -util::math::sind( m_transform->rotation.y ) * moveSpeed;
    }
    // backwards
    if ( omi::input::isKeyPressed( omi::input::key::S ) )
    {
        moveDis.z = util::math::cosd( m_transform->rotation.y ) * moveSpeed;
        moveDis.x = util::math::sind( m_transform->rotation.y ) * moveSpeed;
    }
    // left
    if ( omi::input::isKeyPressed( omi::input::key::A ) )
    {
        moveDis.z =  util::math::sind( m_transform->rotation.y ) * moveSpeed;
        moveDis.x = -util::math::cosd( m_transform->rotation.y ) * moveSpeed;
    }
    // right
    if ( omi::input::isKeyPressed( omi::input::key::D ) )
    {
        moveDis.z = -util::math::sind( m_transform->rotation.y ) * moveSpeed;
        moveDis.x =  util::math::cosd( m_transform->rotation.y ) * moveSpeed;
    }

    // TODO: diagonal move

    // TODO: key release shit

    // TODO: take into account collision detection
    m_transform->translation += moveDis;
}
