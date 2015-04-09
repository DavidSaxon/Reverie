#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_SEGMENT_CORNER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_SEGMENT_CORNER_HPP_

#include "src/entities/gameplay/environment/segment/Segment.hpp"

class CornerSegment : public Segment {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    CornerSegment( const glm::vec3& position, float rotation );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
