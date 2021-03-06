#include "GameplayScene.hpp"

#include "src/omicron/input/Input.hpp"

#include "src/entities/debug/FPSCounter.hpp"

#include "src/entities/gameplay/Player.hpp"
#include "src/entities/gameplay/layout/LayoutManager.hpp"
#include "src/entities/menu/PauseMenu.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GameplayScene::init()
{
    // apply lock the mouse to the centre of the screen
    omi::systemSettings.setCursorLocked( true );
    omi::systemSettings.setCursorLockPosition(
            omi::displaySettings.getCentre() );

    // collision check groups
    omi::CollisionDetect::checkGroup( "curse_room_trigger", "player" );

    // TODO: MOVE?
    // ambient lighting
    omi::renderSettings.setAmbientStrength( 0.05f );
    omi::renderSettings.setAmbientColour( glm::vec3( 1.0f, 1.0f, 1.0f ) );
    omi::renderSettings.setFilmGrain( 0.04f );

    // TODO: REMOVE ME
    addEntity( new FPSCounter() );

    // add the initial entities
    addEntity( new PauseMenu() );
    Player* player = new Player();
    addEntity( player );
    addEntity( new LayoutManager( player ) );

    // set up collision groups
    omi::CollisionDetect::checkGroup( "intro_trigger", "player" );
    omi::CollisionDetect::checkGroup( "gen_trigger",   "player" );
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
