#include "src/entities/gameplay/intro/IntroLayoutTrigger.hpp"

#include "src/data/Globals.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntroLayoutTrigger::IntroLayoutTrigger( const glm::vec3& position )
    :
    m_position ( position ),
    m_triggered( false )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void IntroLayoutTrigger::init()
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

void IntroLayoutTrigger::update()
{
    // check collisions
    if ( m_detector->getCollisionData().size() > 0 )
    {
        m_triggered = true;
    }
}

bool IntroLayoutTrigger::isTriggered()
{
    bool temp = m_triggered;
    m_triggered = false;
    return temp;
}
