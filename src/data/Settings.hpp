#ifndef REVERIE_DATA_SETTINGS_HPP_
#   define REVERIE_DATA_SETTINGS_HPP_

#include "src/omicron/input/Input.hpp"

/************************************\
| Miscellaneous settings for Reverie |
\************************************/
namespace rev_settings
{

// the master volume for all sounds
extern float masterVolume;

// the look sensitivity multiplier
extern float lookSensitivity;
// the key bindings
extern omi::input::key::Type keyForwards;
extern omi::input::key::Type keyBackwards;
extern omi::input::key::Type keyLeft;
extern omi::input::key::Type keyRight;

} // namespace rev_settings

#endif
