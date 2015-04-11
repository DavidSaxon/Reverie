#include "GameplayScene.hpp"

#include "src/omicron/input/Input.hpp"

#include "src/entities/debug/FPSCounter.hpp"

#include "src/entities/gameplay/Player.hpp"
#include "src/entities/menu/PauseMenu.hpp"
// TODO: REMOVE ME:
#include "src/entities/gameplay/TestCube.hpp"
#include "src/entities/gameplay/TestEntity.hpp"
#include "src/entities/gameplay/environment/segment/CornerSegment.hpp"
#include "src/entities/gameplay/environment/segment/StraightSegment.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GameplayScene::init()
{
    // apply lock the mouse to the centre of the screen
    omi::systemSettings.setCursorLocked( true );
    omi::systemSettings.setCursorLockPosition(
            omi::displaySettings.getCentre() );

    // TODO:
    // ambient lighting
    omi::renderSettings.setAmbientStrength( 0.3f );
    omi::renderSettings.setAmbientColour( glm::vec3( 1.0f, 1.0f, 1.0f ) );
    omi::renderSettings.setFilmGrain( 0.04f );

    // TODO: REMOVE ME
    addEntity( new FPSCounter() );

    // add the initial entities
    addEntity( new Player() );
    addEntity( new PauseMenu() );
    // TODO: REMOVE ME:
    addEntity( new TestEntity() );
    addEntity( new TestCube() );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  48.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  45.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  42.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  39.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  36.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  33.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  30.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  27.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  24.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  21.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  18.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  15.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  12.0f ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  9.0f  ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  6.0f  ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  3.0f  ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  0.0f  ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -3.0f  ), 0.0f ) );
    addEntity( new CornerSegment  ( glm::vec3( 0.0f, 0.0f, -6.0f  ), 0.0f ) );
    addEntity( new StraightSegment( glm::vec3( 3.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 6.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 9.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 12.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 15.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 18.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 21.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 24.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 27.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 30.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 33.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 36.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 39.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 42.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 45.0f, 0.0f, -6.0f  ), 90.0f ) );
    addEntity( new StraightSegment( glm::vec3( 48.0f, 0.0f, -6.0f  ), 90.0f ) );

}

bool GameplayScene::update()
{
    // TODO: REMOVE ME
    if ( omi::input::isKeyPressed( omi::input::key::F7 ) )
    {
        // TODO: go to menu
        return true;
    }

    return false;
}

omi::Scene* GameplayScene::nextScene()
{
    // revert settings
    omi::systemSettings.setCursorLocked( false );

    return NULL;

}
