#include "Settings.hpp"

namespace rev_settings
{

// the master volume for all sounds
float masterVolume = 1.0f;

// the look sensitivity multiplier
float lookSensitivity = 1.0f;
// the key bindings
omi::input::key::Type keyForwards  = omi::input::key::W;
omi::input::key::Type keyBackwards = omi::input::key::S;
omi::input::key::Type keyLeft      = omi::input::key::A;
omi::input::key::Type keyRight     = omi::input::key::D;

} // namespace rev_settings
