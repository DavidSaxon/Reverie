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
        "curse_giver_body",
        resource_group::PLAYER,
        "default_shader",
        "res/gfx/texture/player/curse_giver_skin.png",
        "res/gfx/geometry/player/curse_giver.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_giver_pants",
        resource_group::PLAYER,
        "default_shader",
        "res/gfx/texture/player/curse_giver_pants.png",
        "res/gfx/geometry/player/curse_giver_pants.obj",
        0
    );

    //----------------------------------SOUNDS----------------------------------

    // heart beats
    omi::ResourceManager::addSound(
        "heart_beat_slow", resource_group::PLAYER,
        "res/sound/fx/player/heart_beat_slow.ogg", 1
    );

    // footsteps soft
    omi::ResourceManager::addSound(
        "footsteps_soft_1", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_1.ogg", 2
    );
    omi::ResourceManager::addSound(
        "footsteps_soft_2", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_2.ogg", 2
    );
    omi::ResourceManager::addSound(
        "footsteps_soft_3", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_3.ogg", 2
    );
    omi::ResourceManager::addSound(
        "footsteps_soft_4", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_4.ogg", 2
    );
    omi::ResourceManager::addSound(
        "footsteps_soft_5", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_5.ogg", 2
    );
    omi::ResourceManager::addSound(
        "footsteps_soft_6", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_6.ogg", 2
    );
    omi::ResourceManager::addSound(
        "footsteps_soft_7", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_7.ogg", 2
    );
    omi::ResourceManager::addSound(
        "footsteps_soft_8", resource_group::PLAYER,
        "res/sound/fx/player/footstep_soft_8.ogg", 2
    );
}

} // namespace pack
