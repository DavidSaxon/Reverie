#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_LIGHT1_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_LIGHT1_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class IntroLight1 : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    IntroLight1(
            omi::Transform* baseTransform,
            bool flicker = false,
            bool phobetor = false  );

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
    // whether or not to show phobetor or not
    bool m_phobetor;
    // whether the light is on or off
    bool m_lightOn;
    // the flicker counter
    float m_flickerCounter;
    // the current flicker threshold
    float m_flickerThreshold;
};

#endif
