#include "Packs.hpp"

namespace pack {

void buildPlayerPack()
{
    // TODO: fix
    // flare
    omi::ResourceManager::addMaterialGeometryMesh(
        "flare",
        resource_group::PLAYER,
        "default_shader",
        glm::vec4( 0.8f, 0.1f, 0.1f, 1.0f ),
        "res/gfx/geometry/player/flare.obj",
        0
    );

    // TODO: REMOVE ME
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "test_cube",
        resource_group::PLAYER,
        "default_shader",
        "res/gfx/texture/test/chesterfield.png",
        "res/gfx/geometry/test/test_cube.obj",
        0
    );
}

} // namespace pack
