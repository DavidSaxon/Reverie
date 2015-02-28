#include "ApplySettings.hpp"

#include <iostream>

#include "src/omicron/Omicron.hpp"

namespace settings {

namespace apply {

void resolution( const std::string& value )
{
    std::cout << "value: " << value << std::endl;

    // use screen size if the value is undefined
    if ( value.compare( "undefined" ) == 0 )
    {

        std::cout << "actually undefined" << std::endl;

        omi::renderSettings.setResolution( omi::displaySettings.getSize() );

        // write to config
        // TODO:
    }
    else
    {
        std::cout << "FUCK!" << std::endl;

        unsigned p = value.find( 'x' );

        omi::renderSettings.setResolution( glm::vec2(
                atoi( value.substr( 0, p ).c_str() ),
                atoi( value.substr( p + 1, value.length() ).c_str() )
        ) );
    }
}

} // namespace apply

} // namespace settings
