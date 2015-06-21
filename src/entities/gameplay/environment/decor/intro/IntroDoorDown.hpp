#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORDOWN_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORDOWN_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class IntroDoorDown : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    IntroDoorDown( omi::Transform* baseTransform );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
