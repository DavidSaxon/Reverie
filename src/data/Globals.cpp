#include "Globals.hpp"

namespace global {

bool pause = false;
float timeScale = 1.0f;

//-----------------------------------SETTINGS-----------------------------------

// the master volume for all sounds
float masterVolume = 1.0f;

// the look sensitivity multiplier
float lookSensitivity = 1.0f;
// the key bindings
omi::input::key::Type keyForwards  = omi::input::key::W;
omi::input::key::Type keyBackwards = omi::input::key::S;
omi::input::key::Type keyLeft      = omi::input::key::A;
omi::input::key::Type keyRight     = omi::input::key::D;

//----------------------------------MENU STYLE----------------------------------

const glm::vec4 MENU_ITEM_SELECTED_COLOUR( 1.0f, 0.0f, 0.0f, 1.0f );
const glm::vec4 MENU_ITEM_NON_SELECTED_COLOUR( 0.9f, 0.9f, 0.9f, 1.0f );

//---------------------------------ENVIRONMENT----------------------------------

const float TILE_SIZE = 3.0f;
const std::string WALL_COLLISION_GROUP = "wall";

} // namespace global
