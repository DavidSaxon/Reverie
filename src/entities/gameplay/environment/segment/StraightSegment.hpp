#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_SEGMENT_STRAIGHT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_SEGMENT_STRAIGHT_HPP_

#include "src/entities/gameplay/environment/segment/Segment.hpp"

class StraightSegment : public Segment {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    StraightSegment( const glm::vec3& position );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
