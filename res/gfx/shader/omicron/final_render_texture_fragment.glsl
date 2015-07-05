#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;
uniform sampler2D u_depthTexture;
// random multiplier
uniform float u_randMul;
// the amount of film grain
uniform float u_filmGrain;

// screen resolution
uniform vec2 u_res;

//the texture coords
varying vec2 v_texCoord;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

// generates a pseudo random number
float rand( vec2 co )
{
    return fract( sin( dot( co.xy, vec2( 12.9898, 78.233 ) ) )
                                    * 43758.5453 * u_randMul );
}

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    // calculate pixel size
    vec2 pixelSize = vec2( 1.0 / u_res.x, 1.0 / u_res.y );

    // get texture colour
    vec4 texCol = texture2D( u_texture, v_texCoord );

    //---------------------------------FILTERS----------------------------------

    vec2 uv = ( v_texCoord * 2.0 ) - 1.0;
    // TODO: testing sepia
    // if ( length( uv ) < 0.25 )
    // {
    //     texCol.r = ( texCol.r * 0.393 ) +
    //                ( texCol.g * 0.769 ) +
    //                ( texCol.b * 0.189 );
    //     texCol.g = ( texCol.r * 0.349 ) +
    //                ( texCol.g * 0.686 ) +
    //                ( texCol.b * 0.168 );
    //     texCol.b = ( texCol.r * 0.272 ) +
    //                ( texCol.g * 0.534 ) +
    //                ( texCol.b * 0.131 );
    // }
    // TODO: testing invert
    // if ( length( uv ) < 0.25 )
    // {
    //     texCol.r = 1.0 - texCol.r;
    //     texCol.g = 1.0 - texCol.g;
    //     texCol.b = 1.0 - texCol.b;
    // }
    // TODO: testing shuffle
    // if ( length( uv ) < 0.25 )
    // {
    //     texCol.r = texCol.g;
    //     texCol.g = texCol.b;
    //     texCol.b = texCol.r;
    // }


    // apply film grain to output
    float noise = clamp( rand( v_texCoord ), 0.0, 1.0 );
    noise = ( noise * 2.0 ) - 1.0;
    noise *= u_filmGrain;
    texCol.r += noise;
    texCol.g += noise;
    texCol.b += noise;

    // set final colour
    gl_FragColor = texCol;
}
