#include "Packs.hpp"

namespace pack {

void buildMenuPack()
{
    // TODO: menu layers

    // pause menu overlay
    omi::ResourceManager::addMaterialSprite(
            "pause_menu_overlay",
            resource_group::MENU,
            "default_shader",
            glm::vec4( 0.0f, 0.0f, 0.0f, 0.75f ),
            0,
            glm::vec2( 10.0f, 10.0f ),
            glm::vec2( 1.0f, 1.0f ),
            glm::vec2( 0.0f, 0.0f ),
            omi::material::SHADELESS
    );

    // pause main item text
    omi::ResourceManager::addMaterialText(
        "pause_main_item_text",
        resource_group::MENU,
        "default_shader",
        glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f ),
        1,
        "title_font",
        "",
        0.25f,
        omi::material::SHADELESS
    );
}

} // namespace pack
