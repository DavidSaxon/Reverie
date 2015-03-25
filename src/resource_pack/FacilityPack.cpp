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
        "res/gfx/geometry/facility/floor.obj",
        0
    );

    // ceiling tile
    omi::ResourceManager::addTexture(
            "facility_ceiling_spec",
            resource_group::FACILITY,
            "res/gfx/texture/facility/floor_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_ceiling",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/floor.png",
        "res/gfx/geometry/facility/ceiling.obj",
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
        "res/gfx/geometry/facility/wall.obj",
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
        "res/gfx/geometry/facility/skirting_front.obj",
        0
    );

    // light pane
    omi::ResourceManager::addTexture(
            "facility_light_glow",
            resource_group::FACILITY,
            "res/gfx/texture/facility/light_glow.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_light_pane",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/light_pane.png",
        "res/gfx/geometry/facility/light_pane.obj",
        0
    );

    // light fitting
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_light_fitting",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/wall.png",
        "res/gfx/geometry/facility/light_fitting.obj",
        0
    );
}

} // namespace pack
