#ifndef REVERIE_ENTITIES_GAMEPLAY_INTRO_LAYOUTTRIGGER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_INTRO_LAYOUTTRIGGER_HPP_

#include "src/omicron/entity/Entity.hpp"

class IntroLayoutTrigger : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of sections mapped to this trigger
    std::vector< size_t > sections;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    IntroLayoutTrigger( const glm::vec3& position );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    /** Returns if this is currently being triggered */
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
