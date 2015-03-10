#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;
// the gamma value to use
uniform float u_gamma;

//the texture coords
varying vec2 v_texCoord;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    // get texture rgb colour
    vec3 output = texture2D( u_texture, v_texCoord ).rgb;
    // apply gamma correction
    gl_FragColor.rgb = pow( output, vec3( 1.0 / u_gamma ) );
    gl_FragColor.a = 1.0;
}
