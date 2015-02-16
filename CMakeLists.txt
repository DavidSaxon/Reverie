cmake_minimum_required(VERSION 2.6)
project(TestRun)

set(SRCS

    src/omicron/Omicron.cpp
    src/omicron/audio/SoundPool.cpp
    src/omicron/component/light/DirectionalLight.cpp
    src/omicron/component/light/Light.cpp
    src/omicron/component/light/PointLight.cpp
    src/omicron/component/light/SpotLight.cpp
    src/omicron/component/physics/CollisionChecker.cpp
    src/omicron/component/physics/CollisionDetector.cpp
    src/omicron/component/Camera.cpp
    src/omicron/component/renderable/KeyFrameMesh.cpp
    src/omicron/component/renderable/Mesh.cpp
    src/omicron/component/renderable/Renderable.cpp
    src/omicron/component/renderable/Sprite.cpp
    src/omicron/component/renderable/Text.cpp
    src/omicron/component/updatable/audio/Music.cpp
    src/omicron/display/Window.cpp
    src/omicron/entity/ComponentTable.cpp
    src/omicron/input/Keyboard.cpp
    src/omicron/input/Mouse.cpp
    src/omicron/logic/FPSManager.cpp
    src/omicron/logic/LogicManager.cpp
    src/omicron/physics/collision_detect/CollisionDetect.cpp
    src/omicron/rendering/Renderer.cpp
    src/omicron/rendering/RenderLists.cpp
    src/omicron/rendering/VisibilityCheckThread.cpp
    src/omicron/rendering/lighting/ShadowMap.cpp
    src/omicron/rendering/render_texture/FinalRenderTexture.cpp
    src/omicron/rendering/render_texture/GlowBlurHorRenderTexture.cpp
    src/omicron/rendering/render_texture/GlowBlurVertRenderTexture.cpp
    src/omicron/rendering/render_texture/GlowCollateRenderTexture.cpp
    src/omicron/rendering/render_texture/GlowFirstPassRenderTexture.cpp
    src/omicron/rendering/render_texture/RenderTexture.cpp
    src/omicron/rendering/render_texture/VisCheckRenderTexture.cpp
    src/omicron/rendering/shading/Animation.cpp
    src/omicron/rendering/shading/Material.cpp
    src/omicron/rendering/shading/Shader.cpp
    src/omicron/rendering/shading/Texture.cpp
    src/omicron/rendering/shading/material_property/Glow.cpp
    src/omicron/rendering/shading/material_property/Specular.cpp
    src/omicron/resource/ResourceManager.cpp
    src/omicron/resource/ResourceServer.cpp
    src/omicron/resource/VirtualFile.cpp
    src/omicron/resource/loader/FontLoader.cpp
    src/omicron/resource/loader/GeometryLoader.cpp
    src/omicron/resource/loader/ShaderLoader.cpp
    src/omicron/resource/loader/TextureLoader.cpp
    src/omicron/resource/type/FontResource.cpp
    src/omicron/resource/type/GeometryResource.cpp
    src/omicron/resource/type/KeyFrameMeshResource.cpp
    src/omicron/resource/type/MaterialResource.cpp
    src/omicron/resource/type/MeshResource.cpp
    src/omicron/resource/type/ShaderResource.cpp
    src/omicron/resource/type/SpriteResource.cpp
    src/omicron/resource/type/SoundResource.cpp
    src/omicron/resource/type/TextResource.cpp
    src/omicron/resource/type/TextureResource.cpp
    src/omicron/scene/Scene.cpp
    src/omicron/settings/AudioSettings.cpp
    src/omicron/settings/DisplaySettings.cpp
    src/omicron/settings/RenderSettings.cpp
    src/omicron/settings/SystemSettings.cpp
    src/omicron/system/System.cpp
    src/override/StartUp.cpp

    src/resource_pack/AllPack.cpp
    src/resource_pack/StartUpPack.cpp
    src/resource_pack/TestPack.cpp

    src/scenes/start_up/StartUpScene.cpp

    src/entities/start_up/OmicronLogo.cpp

    src/scenes/test/TestScene.cpp

    src/entities/test/GlowCube.cpp
    src/entities/test/Human.cpp
    src/entities/test/MapCube.cpp
    src/entities/test/Monkey.cpp
    src/entities/test/TestEnvironment.cpp
    src/entities/test/TestEvil.cpp
    src/entities/test/TestFps.cpp
    src/entities/test/TestPlayer.cpp
    src/entities/test/TestSun.cpp

)

find_package(Boost)

set(BASEPATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x -DGL_GLEXT_PROTOTYPES")

add_definitions(-DBOOST_TEST_DYN_LINK)

find_package(Freetype REQUIRED)
include_directories("${BASEPATH}" ${INCLUDE_DIRECTORIES} ${FREETYPE_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

link_directories(${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})

add_executable(TestRun ${SRCS})

target_link_libraries(TestRun

    ${Boost_LIBRARIES}
    -lboost_system
    -lboost_thread
    -lGL
    -lGLU
    -lGLEW
    -lm
    -lIL
    -lsfml-system
    -lsfml-graphics
    -lsfml-window
    -lsfml-audio
    ${FREETYPE_LIBRARIES}
)
