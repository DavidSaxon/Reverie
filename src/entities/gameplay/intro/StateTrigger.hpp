#ifndef REVERIE_ENTITIES_GAMEPLAY_INTRO_STATETRIGGER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_INTRO_STATETRIGGER_HPP_

#include "src/omicron/entity/Entity.hpp"

class StateTrigger: public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    StateTrigger( const glm::vec3& position );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    bool isTriggered();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    const glm::vec3 m_position;
    omi::CollisionDetector* m_detector;
    bool m_triggered;
};

#endif
