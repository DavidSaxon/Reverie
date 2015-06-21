#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORUP_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORUP_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class IntroDoorUp : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    IntroDoorUp( omi::Transform* baseTransform );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
