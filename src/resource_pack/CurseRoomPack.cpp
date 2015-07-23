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
}

} // namespace pack
