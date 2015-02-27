#ifndef REVERIE_FUNCTIONS_SETTINGS_CONFIG_HPP_
#   define REVERIE_FUNCTIONS_SETTINGS_CONFIG_HPP_

namespace settings {

/*****************************************************************************\
| Is used for loading settings from the config file, and handling cases where |
| the config file doesn't exists or is corrupt.                               |
\*****************************************************************************/
namespace config {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the default template for the config file
extern std::string& configDefaultTemplate;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/** Loads and applies the settings from the config file. If the config file is
corrupted or missing then it will be reinstated with the default template */
void applySettingsFromConfig();

} // namespace config

} // namespace settings

#endif
