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
        0
    );

    // player flare arm
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "player_flare_arm",
        resource_group::PLAYER,
        "default_shader",
        "res/gfx/texture/player/player_flare_arm.png",
        "res/gfx/geometry/player/player_flare_arm.obj",
        0
    );

    omi::ResourceManager::addMaterialGeometryMesh(
        "flare",
        resource_group::PLAYER,
        "default_shader",
        glm::vec4( 0.8f, 0.1f, 0.1f, 1.0f ),
        "res/gfx/geometry/player/flare.obj",
        0
    );

    // curse text
    omi::ResourceManager::addMaterialText(
        "curse_text",
        resource_group::PLAYER,
        "default_shader",
        glm::vec4( 0.7f, 0.1f, 0.1f, 1.0f ),
        0,
        "title_font",
        "Curse of Madness",
        0.13f,
        omi::material::SHADELESS
    );
}

} // namespace pack
