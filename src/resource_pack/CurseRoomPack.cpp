#include "Packs.hpp"

namespace pack
{

void buildCurseRoomPack()
{
    // floor tile
    omi::ResourceManager::addTexture(
        "curse_room_floor_spec",
        resource_group::CURSE_ROOM,
        "res/gfx/texture/curse_room/floor_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_room_floor",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/floor.png",
        "res/gfx/geometry/environment/floor.obj",
        0
    );

    // ceiling tile
    omi::ResourceManager::addTexture(
        "curse_room_ceiling_spec",
        resource_group::CURSE_ROOM,
        "res/gfx/texture/curse_room/ceiling_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_room_ceiling",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/ceiling.png",
        "res/gfx/geometry/environment/ceiling.obj",
        0
    );

    // wall tile
    omi::ResourceManager::addTexture(
        "curse_room_wall_spec",
        resource_group::CURSE_ROOM,
        "res/gfx/texture/curse_room/wall_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_room_wall",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/wall.png",
        "res/gfx/geometry/environment/wall.obj",
        0
    );

    // Curse giver
    omi::ResourceManager::addTexture(
        "curse_giver_skin_spec",
        resource_group::CURSE_ROOM,
        "res/gfx/texture/curse_room/curse_giver_skin_spec.png"
    );
    omi::ResourceManager::addTextureMatrialKeyFrameMesh(
        "curse_giver_body", resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/curse_giver_skin.png",
        0,
        "res/gfx/geometry/curse_room/curse_giver/curse_giver.key"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_giver_pants",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/curse_giver_pants.png",
        "res/gfx/geometry/curse_room/curse_giver_pants.obj",
        0
    );

    // hook
    omi::ResourceManager::addTexture(
        "curse_room_hook_spec",
        resource_group::CURSE_ROOM,
        "res/gfx/texture/curse_room/hook_spec.png"
    );
    omi::ResourceManager::addTextureMatrialKeyFrameMesh(
        "curse_room_hook", resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/hook.png",
        0,
        "res/gfx/geometry/curse_room/hook/hook.key"
    );
}

} // namespace pack
