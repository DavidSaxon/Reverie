#include "StartUpScene.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StartUpScene::init() {

    // apply settings
    omi::systemSettings.setCursorHidden( true );
    omi::renderSettings.setDepthTest(false);
    // TODO: figure out why this was here
    // omi::renderSettings.setResolution( omi::displaySettings.getSize() );

    // load the need resources
    omi::ResourceManager::load(resource_group::ALL);
    omi::ResourceManager::load(resource_group::START_UP);

    // add entities
    m_omicronLogo = new OmicronLogo();
    addEntity(m_omicronLogo);
}

bool StartUpScene::update() {

    if (m_omicronLogo->done()) {

        // load the next resources we'll need
        omi::ResourceManager::load(resource_group::TEST);
        // start up finished
        return true;
    }

    return false;
}

omi::Scene* StartUpScene::nextScene() {

    // release resources
    // TODO: release
    omi::ResourceManager::release(resource_group::START_UP);

    // revert settings
    omi::renderSettings.setDepthTest( true );

    return new TestScene();
}
