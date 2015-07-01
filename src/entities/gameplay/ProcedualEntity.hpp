#ifndef REVERIE_ENTITIES_GAMEPLAY_PROCEDUALENTITY_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_PROCEDUALENTITY_HPP_

#include "src/omicron/entity/Entity.hpp"

class ProcedualEntity : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    virtual void setVisibility( bool state );

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    std::vector< omi::Mesh* > m_meshComp;
    std::vector< omi::Light* > m_lightComp;
};

#endif
