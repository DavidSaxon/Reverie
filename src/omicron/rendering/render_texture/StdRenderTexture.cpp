#include "StdRenderTexture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StdRenderTexture::StdRenderTexture() :
    RenderTexture(
        "res/gfx/shader/omicron/render_texture_vertex.glsl",
        "res/gfx/shader/omicron/fxaa_render_texture_fragment.glsl"
    )
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StdRenderTexture::shaderParameters( GLuint program )
{
    // pass in resolution
    glUniform2f(
        glGetUniformLocation( program, "u_res" ),
        renderSettings.getResolution().x * m_resScale,
        renderSettings.getResolution().y * m_resScale
    );
}

} // namespace omi
