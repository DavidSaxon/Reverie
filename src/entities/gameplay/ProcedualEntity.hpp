#ifndef REVERIE_ENTITIES_GAMEPLAY_PROCEDUALENTITY_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_PROCEDUALENTITY_HPP_

#include "src/omicron/entity/Entity.hpp"

class ProcedualEntity : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    ProcedualEntity();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void update();

    void removeThis();

    virtual void setVisibility( bool state );

    virtual void setSoftVisibility( bool state );

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    std::vector< omi::Mesh* > m_meshComp;
    std::vector< omi::Text* > m_textComp;
    std::vector< omi::Light* > m_lightComp;

    bool m_usingSoftVisibilty;
    bool m_softVisible;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    virtual void applySoftVisibiltiy();
};

#endif
