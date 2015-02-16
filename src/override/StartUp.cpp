#include "StartUp.hpp"

// TODO: include settings
#include <iostream>

namespace start_up {

omi::Scene* init() {

    // TODO: should be true for final release
    // resources
    omi::ResourceServer::loadFromLibrary( false );

    // system settings
    omi::systemSettings.enableForcedLag( false );

    // display settings
    omi::displaySettings.setSize( glm::vec2( 960, 540 ) );
    omi::displaySettings.setPos( glm::vec2( 250, 330 ) );
    omi::displaySettings.setTitle( "Omicron Test" );
    omi::displaySettings.setFullscreen( true );
    omi::displaySettings.setVsync( true );

    // render settings
    omi::renderSettings.setDepthTest( true );
    omi::renderSettings.setBackFaceCulling( true );
    omi::renderSettings.setClearColour( glm::vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );
    omi::renderSettings.setResolution( glm::vec2( 1920, 1080 ) );
    // omi::renderSettings.setResolution( glm::vec2( 960, 540 ) );
    omi::renderSettings.setShadows( false );
    omi::renderSettings.setShadowFrustumSize( 40.0f );
    omi::renderSettings.setShadowMapResolutionScale( 4.0f );
    omi::renderSettings.setColourPicking( true );
    omi::renderSettings.setVisibilityChecking( false );

    //audio settings
    omi::audioSettings.setSoundDisabled( true );
    omi::audioSettings.setMusicDisabled( true );
    omi::audioSettings.setSoundVolume( 1.0f );
    omi::audioSettings.setMusicVolume( 1.0f );

    return new StartUpScene();
}

} // namespace start_up
