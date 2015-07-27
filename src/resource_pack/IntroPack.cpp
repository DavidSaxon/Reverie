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
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_skirting_corner",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/skirting.png",
        "res/gfx/geometry/environment/intro/skirting_corner.obj",
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
    omi::ResourceManager::addTextureMaterialGeometryMesh(
        "intro_rattle_handle",
        resource_group::INTRO,
        "default_shader",
        "res/gfx/texture/intro/light_fitting.png",
        "res/gfx/geometry/environment/intro/rattle_handle.obj",
        0
    );

    // intro title text
    omi::ResourceManager::addMaterialText(
        "intro_title_text",
        resource_group::INTRO,
        "default_shader",
        glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f ),
        1,
        "title_font", // TODO:
        "REVERIE",
        0.24f,
        omi::material::SHADELESS
    );
    // tutorial text
    omi::ResourceManager::addMaterialText(
        "intro_tutorial_text",
        resource_group::INTRO,
        "default_shader",
        glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f ),
        1,
        "title_font", // TODO:
        "Tutorial text",
        0.12f,
        omi::material::SHADELESS
    );

    //----------------------------------SOUNDS----------------------------------

    omi::ResourceManager::addSound(
        "intro_door_knock_1", resource_group::INTRO,
        "res/sound/fx/intro/door_knock_1.ogg", 1
    );
    omi::ResourceManager::addSound(
        "intro_door_rattle_1", resource_group::INTRO,
        "res/sound/fx/intro/door_rattle_1.ogg", 1
    );
    omi::ResourceManager::addSound(
        "intro_lights_off", resource_group::INTRO,
        "res/sound/fx/intro/lights_off.ogg", 1
    );
    omi::ResourceManager::addSound(
        "intro_drone_1", resource_group::INTRO,
        "res/sound/fx/intro/drone_1.ogg", 1
    );
    omi::ResourceManager::addSound(
        "intro_voices_1", resource_group::INTRO,
        "res/sound/fx/intro/voices_1.ogg", 1
    );

    // walk sounds
    omi::ResourceManager::addSound(
        "intro_foot_left_1", resource_group::INTRO,
        "res/sound/fx/intro/foot_left_1.ogg", 2
    );
    omi::ResourceManager::addSound(
        "intro_foot_left_2", resource_group::INTRO,
        "res/sound/fx/intro/foot_left_2.ogg", 2
    );
    omi::ResourceManager::addSound(
        "intro_foot_left_3", resource_group::INTRO,
        "res/sound/fx/intro/foot_left_3.ogg", 2
    );
    omi::ResourceManager::addSound(
        "intro_foot_right_1", resource_group::INTRO,
        "res/sound/fx/intro/foot_right_1.ogg", 2
    );
    omi::ResourceManager::addSound(
        "intro_foot_right_2", resource_group::INTRO,
        "res/sound/fx/intro/foot_right_2.ogg", 2
    );
    omi::ResourceManager::addSound(
        "intro_foot_right_3", resource_group::INTRO,
        "res/sound/fx/intro/foot_right_3.ogg", 2
    );
};

} // namespace pack
