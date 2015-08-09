#include "src/entities/gameplay/intro/StateTrigger.hpp"

#include "src/data/Globals.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StateTrigger::StateTrigger( const glm::vec3& position )
    :
    m_position ( position ),
    m_triggered( false )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StateTrigger::init()
{
    omi::Transform* transform = new omi::Transform(
            "",
            m_position,
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( transform );

    m_detector = new omi::CollisionDetector( "", "intro_trigger", this );
    m_detector->addBounding( new omi::BoundingRect(
            glm::vec2( global::TILE_SIZE, global::TILE_SIZE ),
            transform
    ) );
    m_components.add( m_detector );
}

void StateTrigger::update()
{
    // check collisions
    if ( m_detector->getCollisionData().size() > 0 )
    {
        m_triggered = true;
    }
}

bool StateTrigger::isTriggered()
{
    return m_triggered;
}
