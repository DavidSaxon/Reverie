#include "Input.hpp"

namespace omi {

namespace input {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

bool isKeyPressed( key::Type key )
{
    return sf::Keyboard::isKeyPressed( sf::Keyboard::Key( key ) );
}

} // namespace input

} // namespace omi
