#include "Config.hpp"

#include <fstream>

#include "lib/Utilitron/StringUtil.hpp"

#include "src/data/Settings.hpp"
#include "src/functions/settings/ApplySettings.hpp"
#include "src/omicron/Omicron.hpp"

namespace settings {

namespace config {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

// the path to the config file
static const std::string CONFIG_PATH = "config.omi_pref";

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void applySettingsFromConfig()
{
    // open the file
    std::ifstream file( CONFIG_PATH.c_str() );

    // the settings values
    std::string resolution = "undefined";
    std::string fullscreen = "undefined";
    std::string vsync      = "undefined";
    std::string gamma      = "undefined";
    std::string shadows    = "undefined";
    std::string master     = "undefined";
    std::string sound      = "undefined";
    std::string music      = "undefined";
    std::string look       = "undefined";
    std::string forwards   = "undefined";
    std::string backwards  = "undefined";
    std::string left       = "undefined";
    std::string right      = "undefined";

    // read what we can from the config file
    while ( file.good() )
    {
        // get the current line as a string
        char lineBuffer[ 2048 ];
        file.getline( lineBuffer, 2048 );
        std::string line( lineBuffer );

        // read resolution
        if ( util::str::beginsWith( line, "resolution:" ) )
        {
            parseConfigLine( line, resolution );
        }
        // read fullscreen
        else if ( util::str::beginsWith( line, "fullscreen:" ) )
        {
            parseConfigLine( line, fullscreen );
        }
        // read vsync
        else if ( util::str::beginsWith( line, "vsync:" ) )
        {
            parseConfigLine( line, vsync );
        }
        // read gamma
        else if ( util::str::beginsWith( line, "gamma:" ) )
        {
            parseConfigLine( line, gamma );
        }
        // read shadows
        else if ( util::str::beginsWith( line, "shadows:" ) )
        {
            parseConfigLine( line, shadows );
        }
        // read master volume
        else if ( util::str::beginsWith( line, "master:" ) )
        {
            parseConfigLine( line, master );
        }
        // read sound volume
        else if ( util::str::beginsWith( line, "sound:" ) )
        {
            parseConfigLine( line, sound );
        }
        // read music volume
        else if ( util::str::beginsWith( line, "music:" ) )
        {
            parseConfigLine( line, music );
        }
        // read look sensitivity
        else if ( util::str::beginsWith( line, "look:" ) )
        {
            parseConfigLine( line, look );
        }
        // read forwards key
        else if ( util::str::beginsWith( line, "forwards:" ) )
        {
            parseConfigLine( line, forwards );
        }
        // read backwards key
        else if ( util::str::beginsWith( line, "backwards:" ) )
        {
            parseConfigLine( line, backwards );
        }
        // read left key
        else if ( util::str::beginsWith( line, "left:" ) )
        {
            parseConfigLine( line, left );
        }
        // read right key
        else if ( util::str::beginsWith( line, "right:" ) )
        {
            parseConfigLine( line, right );
        }

    }

    // apply settings
    apply::resolution( resolution );
    apply::fullscreen( fullscreen );
    apply::vsync     ( fullscreen );
    apply::gamma     ( gamma );
    apply::shadows   ( shadows );
    apply::master    ( master );
    apply::sound     ( sound );
    apply::music     ( music );
    apply::look      ( look );
    apply::forwards  ( forwards );
    apply::backwards ( backwards );
    apply::left      ( left );
    apply::right     ( right );

    // write settings back to the config file
    writeConfig();
}

void parseConfigLine( const std::string& line, std::string& value )
{
    // split at the first space
    unsigned p = line.find( ' ' );
    if ( p < line.length() )
    {
        value = line.substr( p + 1, line.length() - p );
    }
}

void writeConfig()
{
    // open the config file
    std::ofstream file( CONFIG_PATH.c_str() );

    // write resolution
    file << "resolution: "
         << omi::renderSettings.getResolution().x << "x"
         << omi::renderSettings.getResolution().y << std::endl;
    // write fullscreen state
    file << "fullscreen: ";
    if ( omi::displaySettings.getFullscreen() )
    {
        file << "on" << std::endl;
    }
    else
    {
        file << "off" << std::endl;
    }
    // write vsync state
    file << "vsync: ";
    if ( omi::displaySettings.getVsync() )
    {
        file << "on" << std::endl;
    }
    else
    {
        file << "off" << std::endl;
    }
    // write gamma correction
    file << "gamma: " << omi::renderSettings.getGammaCorrection() << std::endl;
    // write shadows
    file << "shadows: ";
    if ( !omi::renderSettings.getShadows() )
    {
        file << "off" << std::endl;
    }
    else if ( omi::renderSettings.getShadowMapResolutionScale() < 2.0f )
    {
        file << "low" << std::endl;
    }
    else if ( omi::renderSettings.getShadowMapResolutionScale() < 3.5f )
    {
        file << "medium" << std::endl;
    }
    else
    {
        file << "high" << std::endl;
    }
    // write master volume
    file << "master: " << rev_settings::masterVolume << std::endl;
    // write sound volume
    file << "sound: " << omi::audioSettings.getSoundVolume() /
            rev_settings::masterVolume << std::endl;
    // write music volume
    file << "music: " << omi::audioSettings.getMusicVolume() /
            rev_settings::masterVolume << std::endl;
    // write look sensitivity
    file << "look: " << rev_settings::lookSensitivity << std::endl;
    // write forwards key binding
    file << "forwards: "
         << static_cast<int>( rev_settings::keyForwards ) << std::endl;
    // write backwards key binding
    file << "backwards: "
         << static_cast<int>( rev_settings::keyBackwards ) << std::endl;
    // write left key binding
    file << "left: "
         << static_cast<int>( rev_settings::keyLeft ) << std::endl;
    // write right key binding
    file << "right: "
         << static_cast<int>( rev_settings::keyRight ) << std::endl;


    // clean up
    file.close();
}

} // namespace config

} // namespace settings
