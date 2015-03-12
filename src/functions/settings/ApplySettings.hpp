#ifndef REVERIE_FUNCTIONS_SETTINGS_APPLYSETTINGS_HPP_
#   define REVERIE_FUNCTIONS_SETTINGS_APPLYSETTINGS_HPP_

#include <string>

namespace settings {

namespace apply {

/** Applies the resolution from a string */
void resolution( const std::string& value );

/** Applies the fullscreen mode from a string */
void fullscreen( const std::string& value );

/** Applies vertical sync mode from a string */
void vsync( const std::string& value );

/** Applies gamma correction from a string */
void gamma( const std::string& value );

} // namespace apply

} // namespace settings

#endif
