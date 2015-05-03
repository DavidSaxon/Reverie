#include "Packs.hpp"

namespace pack
{

void buildIntroPack()
{
    // floor tile
    omi::ResourceManager::addMaterialGeometryMesh(
        "intro_floor",
        resource_group::INTRO,
        "default_shader",
        glm::vec4( 0.9f, 0.9f, 0.9f, 1.0f ),
        "res/gfx/geometry/environment/floor.obj",
        0
    );

    // ceiling tile
    omi::ResourceManager::addMaterialGeometryMesh(
        "intro_ceiling",
        resource_group::INTRO,
        "default_shader",
        glm::vec4( 0.9f, 0.9f, 0.9f, 1.0f ),
        "res/gfx/geometry/environment/ceiling.obj",
        0
    );

    // wall tile
    omi::ResourceManager::addMaterialGeometryMesh(
        "intro_wall",
        resource_group::INTRO,
        "default_shader",
        glm::vec4( 0.9f, 0.9f, 0.9f, 1.0f ),
        "res/gfx/geometry/environment/wall.obj",
        0
    );

};

} // namespace pack
