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
    // calculate pixel size
    vec2 pixelSize = vec2( 1.0 / u_res.x, 1.0 / u_res.y );

    // get texture colour
    vec4 texCol = texture2D( u_texture, v_texCoord );

    // get the depth for the current fragment
    float depth = texture2D( u_depthTexture, v_texCoord ).r;

    // depth of field
    if ( depth > 0.9995 )
    {
        texCol *= 0.076;

        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y + pixelSize.y * 3.0 )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y + pixelSize.y * 2.0 )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y + pixelSize.y * 1.0 )
        ) * 0.076;

        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y - pixelSize.y * 1.0 )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y - pixelSize.y * 2.0 )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y - pixelSize.y * 3.0 )
        ) * 0.076;


        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x + pixelSize.x * 3.0, v_texCoord.y )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x + pixelSize.x * 2.0, v_texCoord.y )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x + pixelSize.x * 1.0, v_texCoord.y )
        ) * 0.076;

        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x - pixelSize.x * 1.0, v_texCoord.y )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x - pixelSize.x * 2.0, v_texCoord.y )
        ) * 0.076;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x - pixelSize.x * 3.0, v_texCoord.y )
        ) * 0.076;
    }
    else if ( depth > 0.999 )
    {
        texCol *= 0.111;

        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y + pixelSize.y * 2.0 )
        ) * 0.111;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y + pixelSize.y * 1.0 )
        ) * 0.111;

        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y - pixelSize.y * 1.0 )
        ) * 0.111;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y - pixelSize.y * 2.0 )
        ) * 0.111;


        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x + pixelSize.x * 2.0, v_texCoord.y )
        ) * 0.111;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x + pixelSize.x * 1.0, v_texCoord.y )
        ) * 0.111;

        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x - pixelSize.x * 1.0, v_texCoord.y )
        ) * 0.111;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x - pixelSize.x * 2.0, v_texCoord.y )
        ) * 0.111;
    }
    else if ( depth > 0.9985 )
    {
        texCol *= 0.2;


        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y + pixelSize.y * 1.0 )
        ) * 0.2;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x, v_texCoord.y - pixelSize.y * 1.0 )
        ) * 0.2;


        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x + pixelSize.x * 1.0, v_texCoord.y )
        ) * 0.2;
        texCol += texture2D(
                u_texture,
                vec2( v_texCoord.x - pixelSize.x * 1.0, v_texCoord.y )
        ) * 0.2;
    }

    gl_FragColor = texCol;
}
