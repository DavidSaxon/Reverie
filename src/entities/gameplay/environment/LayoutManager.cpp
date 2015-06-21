#include "LayoutManager.hpp"

#include "src/entities/gameplay/environment/tile/CornerTile.hpp"
#include "src/entities/gameplay/environment/tile/EndTile.hpp"
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
    // TODO: create lighting manager.. or use stage manager which you deleted
    // set ambient lighting
    // omi::renderSettings.setAmbientStrength( 1.0f );

    // the intro is the same every-time
    addEntity( new EndTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, global::TILE_SIZE ),
            global::environment::SOUTH,
            global::environment::DECOR_PROP_3
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            global::environment::NORTH
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1 |
            global::environment::DECOR_PROP_1  |
            global::environment::DECOR_PROP_2
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 2.0f ),
            global::environment::NORTH
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 3.0f ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_2
    ) );
    addEntity( new CornerTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0f ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3( global::TILE_SIZE, 0.0f, -global::TILE_SIZE * 4.0f ),
            global::environment::EAST,
            global::environment::DECOR_PROP_2
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 3.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST,
            global::environment::DECOR_LIGHT_2 |
            global::environment::DECOR_PROP_1  |
            global::environment::DECOR_PROP_2
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 5.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 6.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addEntity( new CornerTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::SOUTH,
            global::environment::DECOR_PROP_2 |
            global::environment::DECOR_PROP_3
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 5.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
}

void LayoutManager::nonIntroInit()
{

}
