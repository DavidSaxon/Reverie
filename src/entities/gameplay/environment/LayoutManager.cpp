#include "LayoutManager.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LayoutManager::init()
{
    m_stage = global::environment::INTRO;

    if ( m_stage == global::environment::INTRO )
    {
        introInit();
    }
    else
    {
        nonIntroInit();
    }
}

void LayoutManager::update()
{

}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LayoutManager::introInit()
{

}

void LayoutManager::nonIntroInit()
{

}
