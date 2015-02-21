#include "Packs.hpp"

#include "src/data/layers/GUILayers.hpp"

namespace pack {

void buildMenuPack()
{
    // pause menu overlay
    omi::ResourceManager::addMaterialSprite(
            "pause_menu_overlay",
            resource_group::MENU,
            "default_shader",
            glm::vec4( 0.0f, 0.0f, 0.0f, 0.75f ),
            layer::gui::PAUSE_OVERLAY,
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
        layer::gui::MAIN_MENU_ITEM,
        "title_font",
        "",
        0.25f,
        omi::material::SHADELESS
    );

    // pause second item text
    omi::ResourceManager::addMaterialText(
        "pause_secondary_item_text",
        resource_group::MENU,
        "default_shader",
        glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f ),
        layer::gui::MAIN_MENU_ITEM,
        "title_font",
        "",
        0.125f,
        omi::material::SHADELESS
    );
}

} // namespace pack
