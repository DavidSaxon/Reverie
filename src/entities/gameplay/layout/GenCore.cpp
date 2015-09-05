#include "src/entities/gameplay/layout/GenCore.hpp"

#include "src/entities/gameplay/CurseRoom.hpp"
#include "src/entities/gameplay/Phobetor.hpp"
#include "src/entities/gameplay/Player.hpp"
#include "src/entities/gameplay/ProcedualEntity.hpp"

#include "src/entities/gameplay/environment/tile/CornerTile.hpp"
#include "src/entities/gameplay/environment/tile/EndTile.hpp"
#include "src/entities/gameplay/environment/tile/StraightTile.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

GenCore::GenCore( global::environment::Stage stage, Player* player )
    :
    AbstractLayoutCore( player ),
    m_stage           ( stage ),
    m_levelGrid       ( new LevelGrid() )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GenCore::init()
{
    // zero the player
    m_player->getTransform()->translation = glm::vec3( 0.0F, 0.0F, 0.0F );
    m_player->getCamT()->rotation = glm::vec3( 0.0F, 0.0F, 0.0F );

    // TODO: take into account curses
    omi::Transform* casterT = new omi::Transform(
            "",
            glm::vec3( 0.0f, -0.5f, -1.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( casterT );
    omi::DirectionalLight* shadowCaster =
    shadowCaster =  new omi::DirectionalLight(
        "", casterT, 0.0f, glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    shadowCaster->setCastShadow( true );
    m_components.add( shadowCaster );

    //---------------------------------TESTING----------------------------------

    // addEntity( new Phobetor() );

    addEntity( new StraightTile(
            m_stage,
            glm::vec3( 0.0f, 0.0f, global::TILE_SIZE ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_1
    ) );
    addEntity( new StraightTile(
            m_stage,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    addEntity( new StraightTile(
            m_stage,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_5
    ) );
    addEntity( new StraightTile(
            m_stage,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 2.0F ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_2
    ) );
    addEntity( new StraightTile(
            m_stage,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 3.0F ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_6
    ) );
    addEntity( new StraightTile(
            m_stage,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0F ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    addEntity( new CornerTile(
            m_stage,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 5.0F ),
            global::environment::NORTH
    ) );
    addEntity( new StraightTile(
            m_stage,
            glm::vec3( global::TILE_SIZE, 0.0f, -global::TILE_SIZE * 5.0F ),
            global::environment::EAST
    ) );

}

void GenCore::update()
{
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GenCore::genInitial()
{
    // TODO:
}
