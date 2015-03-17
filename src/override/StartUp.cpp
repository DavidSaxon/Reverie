#include "StartUp.hpp"

#include <iostream>

#include "src/functions/settings/Config.hpp"

namespace start_up {

omi::Scene* init()
{
    // TODO: should be true for final release
    // resources
    omi::ResourceServer::loadFromLibrary( false );

    // system settings
    omi::systemSettings.enableForcedLag( false );
    omi::systemSettings.setCursorHidden( true );

    // display settings
    omi::displaySettings.setTitle( "Reverie" );
    omi::displaySettings.setFrameRateCap( 60 );

    // render settings
    omi::renderSettings.setDepthTest( true );
    omi::renderSettings.setBackFaceCulling( true );
    omi::renderSettings.setClearColour( glm::vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );
    omi::renderSettings.setColourPicking( true );
    omi::renderSettings.setVisibilityChecking( false );
    omi::renderSettings.setShadowFrustumSize( 20.0f );

    //audio settings
    omi::audioSettings.setSoundDisabled( false );
    omi::audioSettings.setMusicDisabled( false );

    // apply settings from disk
    settings::config::applySettingsFromConfig();

    // display settings
    // omi::displaySettings.setSize( glm::vec2( 960, 540 ) );
    // omi::displaySettings.setPos( glm::vec2( 250, 330 ) );
    // omi::displaySettings.setSize( glm::vec2( 1920, 1080 ) );
    // omi::displaySettings.setFullscreen( true );
    // omi::displaySettings.setVsync( true );

    // omi::renderSettings.setResolution( glm::vec2( 1920, 1080 ) );
    // omi::renderSettings.setGammaCorrection( 1.0f );
    // omi::renderSettings.setShadows( true );
    // omi::renderSettings.setShadowMapResolutionScale( 4.0f );

    // omi::audioSettings.setSoundVolume( 1.0f );
    // omi::audioSettings.setMusicVolume( 1.0f );

    return new StartUpScene();
}

} // namespace start_up
