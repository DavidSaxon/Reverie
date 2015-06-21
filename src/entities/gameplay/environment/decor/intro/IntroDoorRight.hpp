#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORRIGHT_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_INTRO_DOORRIGHT_HPP_

#include "src/entities/gameplay/environment/decor/Decor.hpp"

class IntroDoorRight : public Decor
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    IntroDoorRight( omi::Transform* baseTransform );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
