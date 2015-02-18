#include "GameplayScene.hpp"

#include "src/omicron/input/Input.hpp"

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

    // add the initial entities
    addEntity( new Player() );
    // TODO: REMOVE ME:
    addEntity( new TestEntity() );
}

bool GameplayScene::update()
{
    // exit if the escape key has been pressed
    if ( omi::input::isKeyPressed( omi::input::key::ESCAPE ) )
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
