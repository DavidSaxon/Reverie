#include "Packs.hpp"

namespace pack {

void buildFacilityPack()
{
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "facility_floor",
        resource_group::FACILITY,
        "default_shader",
        "res/gfx/texture/facility/floor.png",
        "res/gfx/geometry/facility/floor.obj",
        1
    );
}

} // namespace pack
