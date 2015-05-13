#ifndef REVERIE_DATA_GLOBALS_HPP_
#   define REVERIE_DATA_GLOBALS_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

#include "src/omicron/input/Input.hpp"

/***********************************************\
| Variables that can be accessed by any object. |
\***********************************************/
namespace global {

// is true if reverie is paused
extern bool pause;
// the time scale of the game
extern float timeScale;

//-----------------------------------SETTINGS-----------------------------------

// the master volume for all sounds
extern float masterVolume;

// the look sensitivity multiplier
extern float lookSensitivity;
// the key bindings
extern omi::input::key::Type keyForwards;
extern omi::input::key::Type keyBackwards;
extern omi::input::key::Type keyLeft;
extern omi::input::key::Type keyRight;

//----------------------------------MENU STYLE----------------------------------

// the colour of a selected menu item
extern const glm::vec4 MENU_ITEM_SELECTED_COLOUR;
// the colour of a non-selected menu item
extern const glm::vec4 MENU_ITEM_NON_SELECTED_COLOUR;

//---------------------------------ENVIRONMENT----------------------------------

// the size of a tile
extern const float TILE_SIZE;
// the collider group for walls
extern const std::string WALL_COLLISION_GROUP;

namespace environment
{

// Represents the different stages the environment can be in
enum Stage
{
    INTRO = 0,
    CLINIC,
    FACILITY,
    CELLAR,
    TUNNELS
};

// Represents the different directions tile can be facing
enum Direction
{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
};

} // namespace environment

} // namespace global

#endif
