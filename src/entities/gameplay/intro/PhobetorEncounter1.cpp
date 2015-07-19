#include "src/entities/gameplay/intro/PhobetorEncounter1.hpp"

#include "src/data/Globals.hpp"
#include "src/entities/gameplay/Player.hpp"

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace
{

static const float LIGHT_POWER       = 0.5f;
static const float GLOW_BRIGHTNESS   = 0.1f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PhobetorEncounter1::PhobetorEncounter1( const glm::vec3& basePos, Player* player )
    :
    m_basePos        ( basePos ),
    m_player         ( player ),
    m_startFlag      ( false ),
    m_endFlag        ( false ),
    m_turnOnAnimation( 0.0f ),
    m_droneId        ( 0 ),
    m_voicesId       ( 0 )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PhobetorEncounter1::init()
{
    m_pos = new omi::Transform(
            "",
            m_basePos,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_pos );

    // light
    omi::Transform* lightPos = new omi::Transform(
            "",
            m_pos,
            glm::vec3( 0.0f, 2.7f, 0.0f ),
            glm::vec3( 0.0f, 90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( lightPos );
    m_lightSource = new omi::PointLight(
            "",
            lightPos,
            LIGHT_POWER,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            0.0f,
            0.1f,
            0.02f
    );
    m_lightComp.push_back( m_lightSource );
    m_components.add( m_lightSource );

    // light pane
    m_paneMesh = omi::ResourceManager::getMesh(
            "intro_light_1_pane", "", m_pos );
    m_paneMesh->getMaterial().glow =
            new omi::Glow( glm::vec3( 1.0f, 1.0f, 1.0f ), GLOW_BRIGHTNESS );
    m_meshComp.push_back( m_paneMesh );
    m_components.add( m_paneMesh );

    // light fitting
    omi::Mesh* fittingMesh = omi::ResourceManager::getMesh(
            "intro_light_1_fitting", "", m_pos );
    fittingMesh->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_meshComp.push_back( fittingMesh );
    m_components.add( fittingMesh );


    // phobetor
    m_phobetorMesh = omi::ResourceManager::getKeyFrameMesh(
                "phobetor_basic", "", m_pos );
    m_phobetorMesh->visible = false;
    m_components.add( m_phobetorMesh );

    // start detector
    omi::Transform* startTriggerPos = new omi::Transform(
            "",
            m_basePos + glm::vec3( 0.0f, 0.0f, global::TILE_SIZE * 3.0f ),
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( startTriggerPos );
    m_startDetector = new omi::CollisionDetector( "", "intro_trigger", this );
    m_startDetector->addBounding( new omi::BoundingRect(
            glm::vec2( global::TILE_SIZE, global::TILE_SIZE ),
            startTriggerPos
    ) );
    m_components.add( m_startDetector );

    omi::Transform* endTriggerPos = new omi::Transform(
            "",
            m_basePos + glm::vec3( 0.0f, 0.0f, global::TILE_SIZE ),
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( endTriggerPos );
    m_endDetector = new omi::CollisionDetector( "", "intro_trigger", this );
    m_endDetector->addBounding( new omi::BoundingRect(
            glm::vec2( global::TILE_SIZE, global::TILE_SIZE ),
            endTriggerPos
    ) );
    m_components.add( m_endDetector );
}

void PhobetorEncounter1::update()
{
    // check the start trigger
    if ( !m_startFlag && m_startDetector->getCollisionData().size() > 0 )
    {
        m_startFlag = true;

        // turn off light
        m_lightSource->setPower( 0.0f );
        m_paneMesh->getMaterial().glow->setBrightness( 0.0f );

        // show phobetor
        m_phobetorMesh->visible = true;

        // shake the camera
        m_player->setCamShake( 1.5f );
        m_player->setRunDisabled( true );
        // m_player->setFootStepsDisabled( true );
        m_player->playHeartBeatSlow();

        // pause music
        m_player->pauseMusic();

        // play sounds
        omi::SoundPool::play(
                omi::ResourceManager::getSound( "intro_lights_off" ),
                false,
                1.0f
        );
        m_droneId = omi::ResourceManager::getSound( "intro_drone_1" );
        omi::SoundPool::play( m_droneId, true, 1.0f );
        m_voicesId = omi::ResourceManager::getSound( "intro_voices_1" );
        omi::SoundPool::play( m_voicesId, true, 1.0f );
    }

    if ( !m_startFlag )
    {
        return;
    }

    // check the end trigger
    if ( !m_endFlag && m_endDetector->getCollisionData().size() > 0 )
    {
        m_endFlag = true;

        // turn light back on
        m_paneMesh->getMaterial().glow->setBrightness( GLOW_BRIGHTNESS );

        // hide phobetor again
        m_phobetorMesh->visible = false;

        m_player->setCamShake( -1.0f );
        m_player->setRunDisabled( false );
        // m_player->setFootStepsDisabled( false );
        m_player->stopHeartBeatSlow();

        // resume playing music
        m_player->playMusic();

        omi::SoundPool::stop( m_droneId, 0 );
        omi::SoundPool::stop( m_voicesId, 0 );
    }

    if ( !m_endFlag )
    {
        return;
    }

    if ( m_turnOnAnimation < 1.0f )
    {
        m_turnOnAnimation += 0.01f * omi::fpsManager.getTimeScale();
    }
    else
    {
        m_turnOnAnimation = 1.0f;
    }

    m_lightSource->setPower( LIGHT_POWER * m_turnOnAnimation );
}
