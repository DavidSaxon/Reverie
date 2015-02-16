#include "FinalRenderTexture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

FinalRenderTexture::FinalRenderTexture() :
    RenderTexture(
        "res/gfx/shader/omicron/render_texture_vertex.glsl",
        "res/gfx/shader/omicron/final_render_texture_fragment.glsl"
    )
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void FinalRenderTexture::shaderParameters( GLuint program )
{
    // calculate a random number for the shader to use and pass in
    float randMul = static_cast<float>( rand() % 1000 ) / 100.0f;
    randMul += 1.0f;
    glUniform1f(
        glGetUniformLocation( program, "u_randMul" ), randMul );
    // pass in film grain amount
    glUniform1f(
        glGetUniformLocation( program, "u_filmGrain" ),
        renderSettings.getFilmGrain() );
}

} // namespace omi
