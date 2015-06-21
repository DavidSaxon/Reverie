#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORLEFT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORLEFT_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class IntroDoorLeft : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    IntroDoorLeft( omi::Transform* baseTransform );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
