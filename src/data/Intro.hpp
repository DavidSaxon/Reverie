#ifndef REVERIE_DATA_INTRO_HPP_
#   define REVERIE_DATA_INTRO_HPP_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

/****************************************\
| variables relating to the intro stage. |
\****************************************/
namespace intro
{

//---------------------------------ENVIRONMENT----------------------------------

// the colour of walls
extern const glm::vec4 WALL_COLOUR;
// the brightness of walls
extern const float WALL_BRIGHTNESS;

} // namespace intro

#endif
