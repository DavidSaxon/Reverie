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

    // light 1
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_light_1_pane",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/light_pane.png",
        "res/gfx/geometry/environment/intro/light_pane_1.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_light_1_fitting",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/light_fitting.png",
        "res/gfx/geometry/environment/intro/light_fitting_1.obj",
        0
    );

    // door 1
    omi::ResourceManager::addMaterialGeometryMesh(
        "intro_door_1_frame",
        resource_group::INTRO,
        "default_shader",
        glm::vec4( 0.2, 0.13f, 0.05f, 1.0f ),
        "res/gfx/geometry/environment/intro/door_1_frame.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_door_1_panel",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/door_1_panel.png",
        "res/gfx/geometry/environment/intro/door_1_panel.obj",
        0
    );
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_door_1_handle",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/light_fitting.png",
        "res/gfx/geometry/environment/intro/door_1_handle.obj",
        0
    );

};

} // namespace pack
