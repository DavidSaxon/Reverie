#include "src/entities/gameplay/layout/LayoutManager.hpp"

#include "src/entities/gameplay/Player.hpp"
#include "src/entities/gameplay/layout/IntroCore.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LayoutManager::LayoutManager( Player* player )
    :
    m_layoutCore( NULL ),
    m_player    ( player )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LayoutManager::init()
{
    m_stage = global::environment::INTRO;

    // create the core matching the state
    if ( m_stage == global::environment::INTRO )
    {
        m_layoutCore = new IntroCore( m_player );
        addEntity( m_layoutCore );
    }
    else
    {
    }
}

void LayoutManager::update()
{
}
