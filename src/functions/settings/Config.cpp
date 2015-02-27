#include "Config.hpp"

namespace settings {

namespace config {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

std::string& configDefaultTemplate =
    "resolution: undefined\n"
    "fullscreen: yes\n"
    "gamma: 22\n" // TODO
    "shadows: off\n";

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void applySettingsFromConfig()
{

}

} // namespace config

} // namespace settings
