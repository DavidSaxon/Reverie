#include "ApplySettings.hpp"

#include <iostream>

#include "lib/Utilitron/StringUtil.hpp"

#include "src/omicron/Omicron.hpp"

namespace settings {

namespace apply {

void resolution( const std::string& value )
{
    // is true if the value cannot be read
    bool undefined = false;

    // find the divider
    unsigned p = value.find( 'x' );
    // check if the divider was found
    if ( p < value.length() )
    {
        // get the x and resolution values
        std::string xRes = value.substr( 0, p );
        std::string yRes = value.substr( p + 1, value.length() );

        // check that the values are integers
        if ( util::str::isInt( xRes ) && util::str::isInt( yRes ) )
        {
            // apply resolution
            omi::renderSettings.setResolution( glm::vec2(
                    atoi( xRes.c_str() ),
                    atoi( yRes.c_str() )
            ) );
        }
        else
        {
            undefined = true;
        }
    }
    else
    {
        undefined = true;
    }

    // the resolution could not be parsed, use the screen size
    if ( undefined )
    {
        // get the screen resolution
        omi::renderSettings.setResolution( omi::displaySettings.getSize() );
    }
}

void fullscreen( const std::string& value )
{
    if ( value.compare( "no" ) == 0 )
    {
        std::cout << "off" << std::endl;
        // omi::displaySettings.setFullscreen( false );
    }
    else
    {
        std::cout << "on" << std::endl;
        omi::displaySettings.setFullscreen( true );
    }
}

} // namespace apply

} // namespace settings
