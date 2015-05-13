#include "Packs.hpp"

#include "src/data/Intro.hpp"

namespace pack
{

void buildIntroPack()
{
    // floor tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_floor",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/carpet.png",
        "res/gfx/geometry/environment/floor.obj",
        0
    );

    // ceiling tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_ceiling",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/ceiling.png",
        "res/gfx/geometry/environment/ceiling.obj",
        0
    );

    // wall tile
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_wall",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/wall.png",
        "res/gfx/geometry/environment/wall.obj",
        0
    );

    // skirting
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_skirting",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/skirting.png",
        "res/gfx/geometry/environment/intro/skirting.obj",
        0
    );

};

} // namespace pack
