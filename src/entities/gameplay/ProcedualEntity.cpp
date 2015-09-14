#include "src/entities/gameplay/ProcedualEntity.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

ProcedualEntity::ProcedualEntity()
    :
    m_usingSoftVisibilty( false ),
    m_softVisible       ( true )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void ProcedualEntity::update()
{
    // apply soft visibility
    applySoftVisibiltiy();
}

void ProcedualEntity::removeThis()
{
    remove();
}


void ProcedualEntity::setVisibility( bool state )
{
    // set mesh visibility
    for ( std::vector< omi::Mesh* >::iterator it = m_meshComp.begin();
        it != m_meshComp.end();
        ++it )
    {
        ( *it )->visible = state;
    }
    // set text visibility
    for ( std::vector< omi::Text* >::iterator it = m_textComp.begin();
        it != m_textComp.end();
        ++it )
    {
        ( *it )->visible = state;
    }
    // set light active state
    for ( std::vector< omi::Light* >::iterator it = m_lightComp.begin();
        it != m_lightComp.end();
        ++it )
    {
        ( *it )->active = state;
    }
}

void ProcedualEntity::setSoftVisibility( bool state )
{
    m_usingSoftVisibilty = true;
    m_softVisible = state;

    applySoftVisibiltiy();
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void ProcedualEntity::applySoftVisibiltiy()
{
    // is soft visibility being used?
    if ( !m_usingSoftVisibilty )
    {
        return;
    }

    // set mesh visibility
    for ( std::vector< omi::Mesh* >::iterator it = m_meshComp.begin();
        it != m_meshComp.end();
        ++it )
    {
        ( *it )->visible = m_softVisible;
    }
    // set text visibility
    for ( std::vector< omi::Text* >::iterator it = m_textComp.begin();
        it != m_textComp.end();
        ++it )
    {
        ( *it )->visible = m_softVisible;
    }
    // lights are always active when using soft visibility
    for ( std::vector< omi::Light* >::iterator it = m_lightComp.begin();
        it != m_lightComp.end();
        ++it )
    {
        ( *it )->active = true;
    }
}
