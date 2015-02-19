#include "Packs.hpp"

namespace pack {

void buildMenuPack()
{
    // TODO: fix
    // flare
    omi::ResourceManager::addMaterialGeometryMesh(
        "flare",
        resource_group::PLAYER,
        "default_shader",
        glm::vec4( 0.8f, 0.1f, 0.1f, 1.0f ),
        "res/gfx/geometry/player/flare.obj",
        0
    );

    // pause main item text
    omi::ResourceManager::addMaterialText(
        "pause_main_item_text",
        resource_group::MENU,
        "default_shader",
        glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f ),
        0,
        "title_font",
        "",
        0.25f,
        omi::material::SHADELESS
    );
}

} // namespace pack
