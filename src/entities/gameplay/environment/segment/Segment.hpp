#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_SEGMENT_SEGMENT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_SEGMENT_SEGMENT_HPP_

#include "src/omicron/entity/Entity.hpp"

class Segment : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Segment( const glm::vec3& position  );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    glm::vec3 m_position;
};

#endif
