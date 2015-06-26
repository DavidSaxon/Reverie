#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;
uniform sampler2D u_depthTexture;

//the texture coords
varying vec2 v_texCoord;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    // get the depth for the current fragment
    float depth = texture2D( u_depthTexture, v_texCoord ).r;

    depth = ( depth - 0.9955 ) * 200.0;

    vec3 c = texture2D( u_texture, v_texCoord ).rgb;

    c = ( c * ( 1.0 - depth ) ) + ( vec3( 0.4, 0.1, 0.1 ) * depth );

    gl_FragColor = vec4( c, 1.0 );

    // set final colour
    // gl_FragColor = texture2D( u_texture, v_texCoord );
}
