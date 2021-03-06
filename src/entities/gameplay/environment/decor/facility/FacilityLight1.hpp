#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_LIGHT1_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_FACILITY_LIGHT1_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class FacilityLight1 : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    FacilityLight1( omi::Transform* baseTransform, bool flicker = false );

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

    // the light source component
    omi::PointLight* m_lightSource;
    // the light pane mesh
    omi::Mesh* m_paneMesh;

    // whether the light is flicker or not
    bool m_flicker;
    // whether the light is on or off
    bool m_lightOn;
    // the flicker counter
    float m_flickerCounter;
    // the current flicker threshold
    float m_flickerThreshold;
};

#endif
