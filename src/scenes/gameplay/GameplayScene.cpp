#include "GameplayScene.hpp"

#include "src/omicron/input/Input.hpp"

#include "src/entities/debug/FPSCounter.hpp"

#include "src/entities/gameplay/Player.hpp"
#include "src/entities/menu/PauseMenu.hpp"
// TODO: REMOVE ME:
#include "src/entities/gameplay/TestEntity.hpp"
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
    omi::renderSettings.setAmbientStrength( 0.1f );
    omi::renderSettings.setAmbientColour( glm::vec3( 1.0f, 1.0f, 1.0f ) );

    // TODO: REMOVE ME
    addEntity( new FPSCounter() );

    // add the initial entities
    addEntity( new Player() );
    addEntity( new PauseMenu() );
    // TODO: REMOVE ME:
    addEntity( new TestEntity() );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  0.0f  ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  3.0f  ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  6.0f  ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  9.0f  ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  12.0f ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  15.0f ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  18.0f ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f,  21.0f ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -3.0f  ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -6.0f  ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -9.0f  ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -12.0f ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -15.0f ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -18.0f ) ) );
    addEntity( new StraightSegment( glm::vec3( 0.0f, 0.0f, -21.0f ) ) );
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
