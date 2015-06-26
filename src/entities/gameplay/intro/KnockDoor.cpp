#include "src/entities/gameplay/intro/KnockDoor.hpp"

#include "src/entities/gameplay/Player.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

KnockDoor::KnockDoor( const glm::vec3 basePos, Player* player )
    :
    m_basePos  ( basePos ),
    m_player   ( player ),
    m_triggered( false )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KnockDoor::init()
{
    // position
    m_pos = new omi::Transform(
            "",
            m_basePos,
            glm::vec3( 0.0f, -90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_pos );

    // add geometry
    omi::Mesh* frame = omi::ResourceManager::getMesh(
            "intro_door_1_frame", "", m_pos );
    m_components.add( frame );
    omi::Mesh* panel = omi::ResourceManager::getMesh(
            "intro_door_1_panel", "", m_pos );
    m_components.add( panel );
    omi::Mesh* handle = omi::ResourceManager::getMesh(
            "intro_door_1_handle", "", m_pos );
    handle->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_components.add( handle );
}

void KnockDoor::update()
{
    // check if the sound should be played
    if ( !m_triggered )
    {
        // calculate the distance from the player
        float distance = fabs(
                m_pos->translation.x - m_player->getTransform()->translation.x
        );

        // play the sound
        if ( distance < 1.0 )
        {
            omi::SoundPool::play(
                    omi::ResourceManager::getSound( "intro_door_knock_1" ),
                    false,
                    1.0f
            );
            m_triggered = true;
        }
    }
}
