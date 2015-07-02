#include "LayoutManager.hpp"

#include "src/entities/gameplay/Player.hpp"

#include "src/entities/gameplay/environment/tile/CornerTile.hpp"
#include "src/entities/gameplay/environment/tile/EndTile.hpp"
#include "src/entities/gameplay/environment/tile/StraightTile.hpp"

#include "src/entities/gameplay/intro/KnockDoor.hpp"
#include "src/entities/gameplay/intro/RattleDoor.hpp"
#include "src/entities/gameplay/tutorial/TutorialText.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LayoutManager::LayoutManager( Player* player )
    :
    m_player( player )
{
}

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
    // // TODO: create lighting manager.. or use stage manager which you deleted
    // // set ambient lighting
    // // omi::renderSettings.setAmbientStrength( 1.0f );


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
    // title text
    addEntity( new TutorialText(
            glm::vec3( 0.0f, -0.4f, -global::TILE_SIZE ),
            0.0f,
            "Use the WASD keys to move",
            m_player,
            true
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
    // look text
    addEntity( new TutorialText(
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0f ),
            0.0f,
            "Move the mouse to look around",
            m_player
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
            global::environment::DECOR_PROP_2
    ) );
    // knock door
    addEntity( new KnockDoor(
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            m_player
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
    // run text
    addEntity( new TutorialText(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            -90.0f,
            "Hold the shift key to run",
            m_player
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
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 6.0f
            ),
            global::environment::NORTH
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 7.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_2
    ) );
    // rattle door
    addEntity( new RattleDoor(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 7.0f
            ),
            m_player
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 8.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    // pause text
    addEntity( new TutorialText(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 8.0f
            ),
            0.0f,
            "Press ESC to access the menu",
            m_player
    ) );
    addEntity( new CornerTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::EAST
    ) );



    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 6.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 5.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST,
            global::environment::DECOR_LIGHT_3
    ) );
    addEntity( new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 3.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST
    ) );
    addEntity( new CornerTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST,
            global::environment::DECOR_LIGHT_1
    ) );
}

void LayoutManager::nonIntroInit()
{

}
