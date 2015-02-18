#include "Packs.hpp"

namespace pack {

void buildPlayerPack()
{
    // player right arm
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "player_right_arm",
        resource_group::PLAYER,
        "default_shader",
        "res/gfx/texture/player/player_right_arm.png",
        "res/gfx/geometry/player/player_right_arm.obj",
        1
    );

    // curse text
    omi::ResourceManager::addMaterialText(
        "loading_text", resource_group::LOADING,
        "default_shader",
        glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f ),
        2,
        "title_font",
        "Loading",
        0.25f
    );
}

} // namespace pack
