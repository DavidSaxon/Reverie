#include "Packs.hpp"

namespace pack
{

void buildCurseRoomPack()
{
    // floor tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_room_floor",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/floor.png",
        "res/gfx/geometry/environment/floor.obj",
        0
    );

    // ceiling tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_room_ceiling",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/ceiling.png",
        "res/gfx/geometry/environment/ceiling.obj",
        0
    );

    // wall tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_room_wall",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/wall.png",
        "res/gfx/geometry/environment/wall.obj",
        0
    );

    // Curse giver
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_giver_body",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/curse_giver_skin.png",
        "res/gfx/geometry/curse_room/curse_giver.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "curse_giver_pants",
        resource_group::CURSE_ROOM,
        "default_shader",
        "res/gfx/texture/curse_room/curse_giver_pants.png",
        "res/gfx/geometry/curse_room/curse_giver_pants.obj",
        0
    );
}

} // namespace pack
