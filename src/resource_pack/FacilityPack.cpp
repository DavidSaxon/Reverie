#include "Packs.hpp"

namespace pack {

void buildFacilityPack()
{
    // floor tile
    omi::ResourceManager::addTexture(
        "facility_floor_spec",
        resource_group::FACILITY,
        "res/gfx/texture/facility/floor_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_floor",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/floor.png",
        "res/gfx/geometry/environment/floor.obj",
        0
    );

    // ceiling tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_ceiling",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/floor.png",
        "res/gfx/geometry/environment/ceiling.obj",
        0
    );

    // wall tile
    omi::ResourceManager::addTexture(
        "facility_wall_spec",
        resource_group::FACILITY,
        "res/gfx/texture/facility/wall_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_wall",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/wall.png",
        "res/gfx/geometry/environment/wall.obj",
        0
    );

    // skirting
    omi::ResourceManager::addTexture(
        "facility_skirting_spec",
        resource_group::FACILITY,
        "res/gfx/texture/facility/skirting_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_skirting",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/skirting.png",
        "res/gfx/geometry/environment/skirting.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_skirting_corner",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/skirting.png",
        "res/gfx/geometry/environment/skirting_corner.obj",
        0
    );
}

} // namespace pack
