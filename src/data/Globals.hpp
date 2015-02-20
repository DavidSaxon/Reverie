#ifndef REVERIE_DATA_GLOBALS_HPP_
#   define REVERIE_DATA_GLOBALS_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

/***********************************************\
| Variables that can be accessed by any object. |
\***********************************************/
namespace global {

// is true if reverie is paused
extern bool pause;

//----------------------------------MENU STYLE----------------------------------

// the colour of a selected menu item
extern const glm::vec4 MENU_ITEM_SELECTED_COLOUR;
// the colour of a non-selected menu item
extern const glm::vec4 MENU_ITEM_NON_SELECTED_COLOUR;

} // namespace global

#endif
