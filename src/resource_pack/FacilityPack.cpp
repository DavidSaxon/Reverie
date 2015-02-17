#include "Packs.hpp"

namespace pack {

void buildFacilityPack()
{
    std::cout << "what the fuck?" << std::endl;

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
