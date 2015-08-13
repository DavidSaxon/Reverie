#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_DOORRIGHT_HPP
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_DOORRIGHT_HPP

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class FacilityDoorRight : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    FacilityDoorRight( omi::Transform* baseTransform );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
