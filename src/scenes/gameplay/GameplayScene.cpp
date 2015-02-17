#include "GameplayScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GameplayScene::init()
{
    // apply lock the mouse to the centre of the screen
    omi::systemSettings.setCursorLocked( true );
    omi::systemSettings.setCursorLockPosition(
            omi::displaySettings.getCentre() );

    // TODO: add entities
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
