#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_SUPPORT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_SUPPORT_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class FacilitySupport : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    FacilitySupport( omi::Transform* baseTransform );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
