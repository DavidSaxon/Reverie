#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;
uniform sampler2D u_depthTexture;

// screen resolution
uniform vec2 u_res;

//the texture coords
varying vec2 v_texCoord;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    // // calculate pixel size
    // vec2 pixelSize = vec2( 1.0 / u_res.x, 1.0 / u_res.y );

    // // get the depth for the current fragment
    // float depth = texture2D( u_depthTexture, v_texCoord ).r;

    // // is true if we have detected an edge
    // bool detectedEdge = false;

    // // compare against surrounding depth
    // // up
    // float neighbourDepth = texture2D(
    //         u_depthTexture,
    //         vec2( v_texCoord.x, v_texCoord.y + pixelSize.y )
    // ).r;
    // if ( abs( depth - neighbourDepth ) > 0.00001 )
    // {
    //     detectedEdge = true;
    // }
    // // down
    // neighbourDepth = texture2D(
    //         u_depthTexture,
    //         vec2( v_texCoord.x, v_texCoord.y - pixelSize.y )
    // ).r;
    // if ( abs( depth - neighbourDepth ) > 0.00001 )
    // {
    //     detectedEdge = true;
    // }
    // // left
    // neighbourDepth = texture2D(
    //         u_depthTexture,
    //         vec2( v_texCoord.x - pixelSize.x, v_texCoord.y )
    // ).r;
    // if ( abs( depth - neighbourDepth ) > 0.00001 )
    // {
    //     detectedEdge = true;
    // }
    // // right
    // neighbourDepth = texture2D(
    //         u_depthTexture,
    //         vec2( v_texCoord.x + pixelSize.x, v_texCoord.y )
    // ).r;
    // if ( abs( depth - neighbourDepth ) > 0.00001 )
    // {
    //     detectedEdge = true;
    // }

    // // read the texture colour
    // // vec3 finalColour = texture2D( u_texture, v_texCoord ).rgb;
    // vec3 finalColour = vec3( 0.0, 0.0, 0.0 );

    // // set final colour
    // if ( detectedEdge )
    // {
    //     // blur since we're an edge
    //     finalColour = vec3( 1.0, 0.0, 0.0 );

    //     // finalColour *= 0.1;
    //     // finalColour += texture2D(
    //     //         u_texture,
    //     //         vec2( v_texCoord.x, v_texCoord.y + pixelSize.y )
    //     // ).rgb * 0.225;
    //     // finalColour += texture2D(
    //     //         u_texture,
    //     //         vec2( v_texCoord.x, v_texCoord.y - pixelSize.y )
    //     // ).rgb * 0.225;
    //     // finalColour += texture2D(
    //     //         u_texture,
    //     //         vec2( v_texCoord.x - pixelSize.x, v_texCoord.y )
    //     // ).rgb * 0.225;
    //     // finalColour += texture2D(
    //     //         u_texture,
    //     //         vec2( v_texCoord.x + pixelSize.x, v_texCoord.y )
    //     // ).rgb * 0.225;

    //     // finalColour += vec3( 1.0, 0.0, 0.0 ) * 0.1;

    // }

    // gl_FragColor = vec4( finalColour, 1.0 );
    gl_FragColor = texture2D( u_texture, v_texCoord );
}
