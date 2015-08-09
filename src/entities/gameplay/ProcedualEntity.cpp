#include "src/entities/gameplay/ProcedualEntity.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

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
