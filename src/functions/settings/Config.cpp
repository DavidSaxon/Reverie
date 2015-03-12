#include "Config.hpp"

#include <fstream>

#include "lib/Utilitron/StringUtil.hpp"

#include "src/functions/settings/ApplySettings.hpp"

namespace settings {

namespace config {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

std::string configDefaultTemplate =
    "resolution: undefined\n"
    "fullscreen: yes\n"
    "gamma: 22\n" // TODO
    "shadows: off\n";

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void applySettingsFromConfig()
{
    // is true if the file is corrupt or missing
    bool fileError = false;

    // open the file
    std::ifstream file( "config.omi_pref" );

    // check of the file exists
    if ( !file.good() )
    {
        file.close();
        fileError = true;
    }

    // the settings values
    std::string resolution = "undefined";
    std::string fullscreen = "undefined";
    std::string vsync      = "undefined";
    std::string gamma      = "undefined";

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
    }

    // apply settings
    apply::resolution( resolution );
    apply::fullscreen( fullscreen );
    apply::vsync     ( fullscreen );
    apply::gamma     ( gamma );

    // TODO: write settings back to config file

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

} // namespace config

} // namespace settings
