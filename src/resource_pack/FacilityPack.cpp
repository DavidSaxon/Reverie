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
}

} // namespace pack
