#include "src/entities/gameplay/layout/IntroCore.hpp"

#include "src/entities/gameplay/Player.hpp"
#include "src/entities/gameplay/ProcedualEntity.hpp"

#include "src/entities/gameplay/environment/tile/CornerTile.hpp"
#include "src/entities/gameplay/environment/tile/EndTile.hpp"
#include "src/entities/gameplay/environment/tile/StraightTile.hpp"

#include "src/entities/gameplay/intro/KnockDoor.hpp"
#include "src/entities/gameplay/intro/RattleDoor.hpp"
#include "src/entities/gameplay/tutorial/TutorialText.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntroCore::IntroCore( Player* player )
    :
    AbstractLayoutCore( player )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void IntroCore::init()
{
    // TODO:
    addToSection( 0, new EndTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, global::TILE_SIZE ),
            global::environment::SOUTH,
            global::environment::DECOR_PROP_3
    ) );
    addToSection( 0, new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            global::environment::NORTH
    ) );
    addToSection( 0, new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1 |
            global::environment::DECOR_PROP_1  |
            global::environment::DECOR_PROP_2
    ) );
    // title text
    addToSection( 0, new TutorialText(
            glm::vec3( 0.0f, -0.4f, -global::TILE_SIZE ),
            0.0f,
            "Use the WASD keys to move",
            m_player,
            true
    ) );
    addToSection( 0, new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 2.0f ),
            global::environment::NORTH
    ) );

    addToSection( 1, new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 3.0f ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_2
    ) );
    addToSection( 1, new CornerTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0f ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    // look text
    addToSection( 1, new TutorialText(
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0f ),
            0.0f,
            "Move the mouse to look around",
            m_player
    ) );
    addToSection( 1, new StraightTile(
            global::environment::INTRO,
            glm::vec3( global::TILE_SIZE, 0.0f, -global::TILE_SIZE * 4.0f ),
            global::environment::EAST,
            global::environment::DECOR_PROP_2
    ) );
    addToSection( 1, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addToSection( 1, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 3.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addToSection( 1, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST,
            global::environment::DECOR_LIGHT_2 |
            global::environment::DECOR_PROP_2
    ) );
}

void IntroCore::update()
{
    setSectionVisibility( 0, false );
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void IntroCore::addToSection( size_t section, ProcedualEntity* entity )
{
    if ( m_sections.size() <= section )
    {
        m_sections.resize( section + 1, std::vector< ProcedualEntity* >() );
    }

    m_sections[ section ].push_back( entity );
    addEntity( entity );
}

void IntroCore::setSectionVisibility( size_t section, bool state )
{
    if ( section < m_sections.size() )
    {
        std::vector< ProcedualEntity* >::iterator it =
                m_sections[ section ].begin();
        for ( ; it != m_sections[ section ].end(); ++it )
        {
            ( *it )->setVisibility( state );
        }
    }
}
