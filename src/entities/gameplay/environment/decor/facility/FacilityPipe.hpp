#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_PIPE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_PIPE_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class FacilityPipe : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    FacilityPipe( omi::Transform* baseTransform );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
