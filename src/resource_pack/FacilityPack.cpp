#include "Packs.hpp"

namespace pack {

void buildFacilityPack()
{
    // floor tile
    omi::ResourceManager::addTexture(
        "facility_floor_rust_1",
        resource_group::FACILITY,
        "res/gfx/texture/facility/floor_rust_1.png"
    );
    omi::ResourceManager::addTexture(
        "facility_floor_rust_2",
        resource_group::FACILITY,
        "res/gfx/texture/facility/floor_rust_2.png"
    );
    omi::ResourceManager::addTexture(
        "facility_floor_blood_1",
        resource_group::FACILITY,
        "res/gfx/texture/facility/floor_blood_1.png"
    );
    omi::ResourceManager::addTexture(
        "facility_floor_spec",
        resource_group::FACILITY,
        "res/gfx/texture/facility/floor_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_floor",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/floor_base.png",
        "res/gfx/geometry/environment/floor.obj",
        0
    );

    // ceiling tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_ceiling",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/floor_base.png",
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

    // light 1
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_light_1_pane",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/light_pane.png",
        "res/gfx/geometry/environment/facility/light_pane.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_light_1_fitting",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/skirting.png",
        "res/gfx/geometry/environment/facility/light_fitting.obj",
        0
    );

    // door
    omi::ResourceManager::addMaterialGeometryMesh(
        "facility_door_1_frame",
        resource_group::FACILITY,
        "default_shader",
        glm::vec4( 0.4F, 0.4F, 0.4F, 1.0F ),
        "res/gfx/geometry/environment/facility/door_frame.obj",
        0
    );
    omi::ResourceManager::addTexture(
        "facility_door_1_panel_spec",
        resource_group::FACILITY,
        "res/gfx/texture/facility/door_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_door_1_panel",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/door.png",
        "res/gfx/geometry/environment/facility/door_panel.obj",
        0
    );
    // TODO: THIS IS CURRENTLY UNUSED
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_door_1_handle",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/support.png",
        "res/gfx/geometry/environment/facility/door_handle.obj",
        0
    );

    // support
    omi::ResourceManager::addTexture(
        "facility_support_spec",
        resource_group::FACILITY,
        "res/gfx/texture/facility/support_spec.png"
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_support",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/support.png",
        "res/gfx/geometry/environment/facility/support.obj",
        0
    );

    // support
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_pipe",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/support.png",
        "res/gfx/geometry/environment/facility/pipe.obj",
        0
    );

}

} // namespace pack
