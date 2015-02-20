#include "GameplayScene.hpp"

#include "src/omicron/input/Input.hpp"

#include "src/entities/debug/FPSCounter.hpp"

#include "src/entities/gameplay/menu/PauseMenu.hpp"
#include "src/entities/gameplay/Player.hpp"
// TODO: REMOVE ME:
#include "src/entities/gameplay/TestEntity.hpp"

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
    omi::renderSettings.setAmbientStrength( 0.25f );
    omi::renderSettings.setAmbientColour( glm::vec3( 1.0f, 1.0f, 1.0f ) );

    // TODO: REMOVE ME
    addEntity( new FPSCounter() );

    // add the initial entities
    addEntity( new Player() );
    addEntity( new PauseMenu() );
    // TODO: REMOVE ME:
    addEntity( new TestEntity() );
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
