#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_DOOR_HPP
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_DOOR_HPP

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class FacilityDoor : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    FacilityDoor( omi::Transform* baseTransform, float dir );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    float m_dir;
};

#endif
