#include "LayoutManager.hpp"

#include "src/entities/gameplay/environment/tile/StraightTile.hpp"

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
    // the intro is the same every-time
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            global::environment::NORTH
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE ),
            global::environment::SOUTH
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( global::TILE_SIZE, 0.0f, -global::TILE_SIZE * 2.0f ),
            global::environment::EAST
    ) );
}

void LayoutManager::nonIntroInit()
{

}
