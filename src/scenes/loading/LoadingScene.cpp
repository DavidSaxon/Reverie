#include "LoadingScene.hpp"

// TODO: REMOVE ME
#include "src/omicron/input/Input.hpp"

#include "src/entities/loading/LoadingSplash.hpp"

#include "src/scenes/gameplay/GameplayScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void LoadingScene::init()
{
    // ambient lighting
    omi::renderSettings.setAmbientStrength( 0.0f );

    addEntity( new LoadingSplash() );
}

bool LoadingScene::update()
{
    // TODO: REMOVE ME
    if ( omi::input::isKeyPressed( omi::input::key::ESCAPE ) )
    {
        return true;
    }

    return false;
}

omi::Scene* LoadingScene::nextScene()
{
    // TODO: release resources
    omi::ResourceManager::release( resource_group::LOADING );

    return new GameplayScene();
}
