#include "GlowCollateRenderTexture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

GlowCollateRenderTexture::GlowCollateRenderTexture() :
    RenderTexture(
        "res/gfx/shader/omicron/render_texture_vertex.glsl",
        "res/gfx/shader/omicron/glow_collate_render_texture_fragment.glsl",
        0.2f
    )
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GlowCollateRenderTexture::shaderParameters( GLuint program )
{
    // do nothing
}

} // namespace omi
