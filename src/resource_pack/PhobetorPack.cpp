#include "Packs.hpp"

namespace pack
{

void buildPhobetorPack()
{
    omi::ResourceManager::addTextureMatrialKeyFrameMesh(
        "phobetor_basic", resource_group::PHOBETOR,
        "default_shader",
        "res/gfx/texture/phobetor/skin.png",
        0,
        "res/gfx/geometry/phobetor/basic/phobetor_basic.key"
    );
}

} // namespace pack
