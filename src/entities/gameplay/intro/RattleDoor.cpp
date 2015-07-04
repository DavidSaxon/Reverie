#include "src/entities/gameplay/intro/RattleDoor.hpp"

#include "src/data/Globals.hpp"
#include "src/entities/gameplay/Player.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RattleDoor::RattleDoor( const glm::vec3& basePos, Player* player )
    :
    m_basePos        ( basePos ),
    m_player         ( player ),
    m_triggered      ( false ),
    m_handleAnimation( 0.0f )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void RattleDoor::init()
{
    // position
    m_pos = new omi::Transform(
            "",
            m_basePos,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_pos );

    // add geometry
    omi::Mesh* frame = omi::ResourceManager::getMesh(
            "intro_door_1_frame", "", m_pos );
    m_meshComp.push_back( frame );
    m_components.add( frame );

    // panel manipulator
    m_panelManipulator = new omi::Transform(
            "",
            m_pos,
            glm::vec3(),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_panelManipulator );


    omi::Mesh* panel = omi::ResourceManager::getMesh(
            "intro_door_1_panel", "", m_panelManipulator );
    m_meshComp.push_back( panel );
    m_components.add( panel );

    // handle manipulator
    m_handleManipulator = new omi::Transform(
            "",
            m_panelManipulator,
            glm::vec3( 0.0f, 1.0f, -0.5148f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_handleManipulator );

    omi::Mesh* handle = omi::ResourceManager::getMesh(
            "intro_rattle_handle", "", m_handleManipulator );
    handle->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_meshComp.push_back( handle );
    m_components.add( handle );
}

void RattleDoor::update()
{
    // check if the sound should be played
    if ( !m_triggered )
    {
        // calculate the distance from the player
        float distance = fabs(
                m_pos->translation.z - m_player->getTransform()->translation.z
        );

        // play the sound
        if ( distance < 2.0 )
        {
            omi::SoundPool::play(
                    omi::ResourceManager::getSound( "intro_door_rattle_1" ),
                    false,
                    1.0f
            );
            m_triggered = true;
        }
    }

    // skip if omicron is paused
    if ( global::pause )
    {
        return;
    }

    // play the handle rattle animation
    if ( m_triggered && m_handleAnimation <= 1.4 )
    {
        // shake the door panel
        m_panelManipulator->translation.x = (
                ( static_cast<float>( rand() % 1000 ) / 1000.0f ) * 0.018f );

        const float turnSpeed = 4.0f;

        // increase the handle animation
        m_handleAnimation += 0.015f * omi::fpsManager.getTimeScale();

        if ( m_handleAnimation < 0.1 )
        {
            m_handleManipulator->rotation.x +=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
        else if ( m_handleAnimation < 0.3 )
        {
            m_handleManipulator->rotation.x -=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
        else if ( m_handleAnimation < 0.5 )
        {
            m_handleManipulator->rotation.x +=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
        else if ( m_handleAnimation < 0.7 )
        {
            m_handleManipulator->rotation.x -=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
        else if ( m_handleAnimation < 0.9 )
        {
            m_handleManipulator->rotation.x +=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
        else if ( m_handleAnimation < 1.1 )
        {
            m_handleManipulator->rotation.x -=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
        else if ( m_handleAnimation < 1.3 )
        {
            m_handleManipulator->rotation.x +=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
        else
        {
            m_handleManipulator->rotation.x -=
                    turnSpeed * omi::fpsManager.getTimeScale();
        }
    }
    else
    {
        m_handleManipulator->rotation.x = 0.0f;
    }
}
