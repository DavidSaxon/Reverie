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

    // TODO: file error

    // the settings values
    std::string resolution = "corrupt";

    while ( file.good() )
    {
        // get the current line as a string
        char lineBuffer[ 2048 ];
        file.getline( lineBuffer, 2048 );
        std::string line( lineBuffer );

        // read resolution
        if ( util::str::beginsWith( line, "resolution:" ) )
        {
            // split out the resolution
            unsigned p = line.find( ' ' );
            resolution = line.substr( p + 1, line.length() - p );
        }
    }

    // TODO: file error

    // apply settings
    // apply::resolution( resolution );

}

} // namespace config

} // namespace settings
