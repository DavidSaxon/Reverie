#include "Direction.hpp"

namespace dir
{

float toAngle( global::environment::Direction direction )
{
    switch ( direction )
    {
        case global::environment::NORTH:
        {
            return 0.0f;
        }
        case global::environment::EAST:
        {
            return 270.0f;
        }
        case global::environment::SOUTH:
        {
            return 180.0f;
        }
        case global::environment::WEST:
        {
            return 90.0f;
        }
    }

    return 0.0f;
}

} // namespace dir
