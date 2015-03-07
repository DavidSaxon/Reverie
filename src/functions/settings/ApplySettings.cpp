#include "ApplySettings.hpp"

#include <iostream>

#include "lib/Utilitron/StringUtil.hpp"

#include "src/omicron/Omicron.hpp"

namespace settings {

namespace apply {

void resolution( const std::string& value )
{
    // // use screen size if the value is undefined
    // if ( value.compare( "undefined" ) == 0 )
    // {

    // }
    // // use the value from the config file
    // else
    // {
    //     unsigned p = value.find( 'x' );

    //     omi::renderSettings.setResolution( glm::vec2(
    //             atoi( value.substr( 0, p ).c_str() ),
    //             atoi( value.substr( p + 1, value.length() ).c_str() )
    //     ) );
    // }

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

        // write to config
        // TODO:
    }
}

} // namespace apply

} // namespace settings
