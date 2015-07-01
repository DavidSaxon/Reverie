#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_DECOR_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_DECOR_DECOR_HPP_

#include "src/entities/gameplay/ProcedualEntity.hpp"

class Decor : public ProcedualEntity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Decor( omi::Transform* baseTransform )
        :
        m_baseTransform( baseTransform )
    {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void remove()
    {
        // super call
        Entity::remove();
    }

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    omi::Transform* m_baseTransform;
};

#endif


