#include "src/entities/gameplay/layout/IntroCore.hpp"

#include "src/entities/gameplay/Player.hpp"
#include "src/entities/gameplay/ProcedualEntity.hpp"

#include "src/entities/gameplay/environment/tile/CornerTile.hpp"
#include "src/entities/gameplay/environment/tile/EndTile.hpp"
#include "src/entities/gameplay/environment/tile/StraightTile.hpp"

#include "src/entities/gameplay/intro/IntroLayoutTrigger.hpp"
#include "src/entities/gameplay/intro/KnockDoor.hpp"
#include "src/entities/gameplay/intro/PhobetorEncounter1.hpp"
#include "src/entities/gameplay/intro/RattleDoor.hpp"
#include "src/entities/gameplay/tutorial/TutorialText.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntroCore::IntroCore( Player* player )
    :
    AbstractLayoutCore( player )
{
    m_initalVis.push_back( 0 );
    m_initalVis.push_back( 1 );
    m_initalVis.push_back( 2 );
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void IntroCore::init()
{
    // set up collision groups
    omi::CollisionDetect::checkGroup( "intro_trigger", "player" );

    // build the initial sections
    initSection0();
    initSection1();
    initSection2();
    initSection3();
    initSection4();
    initSection5();
    initSection6();
}

void IntroCore::update()
{
    // apply initial visibility
    static int tripleShot = 0;
    if ( tripleShot < 3 )
    {
        setSectionsVisible( m_initalVis );
        ++tripleShot;
        return;
    }

    // check triggers
    std::vector< IntroLayoutTrigger* >::iterator trigger = m_triggers.begin();
    for ( ; trigger != m_triggers.end(); ++trigger )
    {
        if ( ( *trigger )->isTriggered() )
        {
            setSectionsVisible( ( *trigger )->sections );
            break;
        }
    }
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

void IntroCore::setSectionsVisible( const std::vector< size_t >& sections )
{
    // disable visibility on all sections
    for ( size_t i = 0; i < m_sections.size(); ++i )
    {
        setSectionVisibility( i, false );
    }

    // renable visibility for provided sections
    std::vector< size_t >::const_iterator index = sections.begin();
    for ( ; index != sections.end(); ++index )
    {
        setSectionVisibility( *index, true );
    }
}

void IntroCore::initSection0()
{
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

    addToSection( 0, new StraightTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 3.0f ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_2
    ) );
    addToSection( 0, new CornerTile(
            global::environment::INTRO,
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0f ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    // look text
    addToSection( 0, new TutorialText(
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0f ),
            0.0f,
            "Move the mouse to look around",
            m_player
    ) );
    // trigger
    IntroLayoutTrigger* trigger = new IntroLayoutTrigger(
            glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0f ) );
    trigger->sections.push_back( 0 );
    trigger->sections.push_back( 1 );
    trigger->sections.push_back( 2 );
    addEntity( trigger );
    m_triggers.push_back( trigger );
}

void IntroCore::initSection1()
{
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
    // knock door
    addToSection( 1, new KnockDoor(
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            m_player
    ) );
    addToSection( 1, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 5.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addToSection( 1, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 6.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::EAST
    ) );
    addToSection( 1, new CornerTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            global::environment::SOUTH,
            global::environment::DECOR_PROP_2 |
            global::environment::DECOR_PROP_3
    ) );
    // run text
    addToSection( 1, new TutorialText(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            ),
            -90.0f,
            "Hold the shift key to run",
            m_player
    ) );
    // trigger
    IntroLayoutTrigger* trigger = new IntroLayoutTrigger(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 4.0f
            )
    );
    trigger->sections.push_back( 0 );
    trigger->sections.push_back( 1 );
    trigger->sections.push_back( 2 );
    trigger->sections.push_back( 3 );
    addEntity( trigger );
    m_triggers.push_back( trigger );
}

void IntroCore::initSection2()
{
    addToSection( 2, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 5.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    addToSection( 2, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 6.0f
            ),
            global::environment::NORTH
    ) );
    addToSection( 2, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 7.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_2
    ) );
    // rattle door
    addToSection( 2, new RattleDoor(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 7.0f
            ),
            m_player
    ) );
    addToSection( 2, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 8.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_LIGHT_1
    ) );
    // pause text
    addToSection( 2, new TutorialText(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 8.0f
            ),
            0.0f,
            "Press ESC to access the menu",
            m_player
    ) );
    addToSection( 2, new CornerTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::EAST,
            global::environment::DECOR_PROP_2
    ) );

    // trigger
    IntroLayoutTrigger* trigger = new IntroLayoutTrigger(
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            )
    );
    trigger->sections.push_back( 1 );
    trigger->sections.push_back( 2 );
    trigger->sections.push_back( 3 );
    trigger->sections.push_back( 4 );
    addEntity( trigger );
    m_triggers.push_back( trigger );
}

void IntroCore::initSection3()
{
    addToSection( 3, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 6.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST
    ) );
    addToSection( 3, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 5.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST
    ) );
    addToSection( 3, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST,
            global::environment::DECOR_LIGHT_1 |
            global::environment::DECOR_PROP_1  |
            global::environment::DECOR_PROP_2
    ) );
    // hunt text
    addToSection( 1, new TutorialText(
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            90.0f,
            "You are being hunted",
            m_player
    ) );
    addToSection( 3, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 3.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST
    ) );
    addToSection( 3, new CornerTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            ),
            global::environment::WEST,
            global::environment::DECOR_LIGHT_1 |
            global::environment::DECOR_PROP_3
    ) );

    // trigger
    IntroLayoutTrigger* trigger = new IntroLayoutTrigger(
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 9.0f
            )
    );
    trigger->sections.push_back( 2 );
    trigger->sections.push_back( 3 );
    trigger->sections.push_back( 4 );
    trigger->sections.push_back( 5 );
    addEntity( trigger );
    m_triggers.push_back( trigger );
}

void IntroCore::initSection4()
{
    addToSection( 4, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 10.0f
            ),
            global::environment::NORTH
    ) );
    addToSection( 4, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 11.0f
            ),
            global::environment::NORTH
    ) );
    addToSection( 4, new StraightTile(
            global::environment::INTRO,
                        glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 12.0f
            ),
            global::environment::NORTH
    ) );
    addToSection( 4, new StraightTile(
            global::environment::INTRO,
                        glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 13.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_1  |
            global::environment::DECOR_PROP_2
    ) );
    addToSection( 4, new StraightTile(
            global::environment::INTRO,
                        glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 14.0f
            ),
            global::environment::NORTH
    ) );
    // Phobetor encouter
    addToSection( 4, new PhobetorEncounter1(
                        glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 14.0f
            ),
            m_player
    ) );
    addToSection( 4, new StraightTile(
            global::environment::INTRO,
                        glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 15.0f
            ),
            global::environment::NORTH
    ) );
    addToSection( 4, new CornerTile(
            global::environment::INTRO,
                        glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            global::environment::NORTH,
            global::environment::DECOR_PROP_3
    ) );

    // trigger
    IntroLayoutTrigger* trigger = new IntroLayoutTrigger(
            glm::vec3(
                    global::TILE_SIZE * 2.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            )
    );
    trigger->sections.push_back( 3 );
    trigger->sections.push_back( 4 );
    trigger->sections.push_back( 5 );
    trigger->sections.push_back( 6 );
    addEntity( trigger );
    m_triggers.push_back( trigger );
}

void IntroCore::initSection5()
{
    addToSection( 5, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 3.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            global::environment::EAST,
            global::environment::DECOR_LIGHT_1
    ) );
    addToSection( 5, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 4.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            global::environment::EAST
    ) );
    addToSection( 5, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 5.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            global::environment::EAST
    ) );
    addToSection( 5, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 6.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            global::environment::EAST,
            global::environment::DECOR_LIGHT_1 |
            global::environment::DECOR_PROP_1  |
            global::environment::DECOR_PROP_2
    ) );
    // hunt text
    addToSection( 5, new TutorialText(
            glm::vec3(
                    global::TILE_SIZE * 6.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            -90.0f,
            "Find the curse room to progress",
            m_player
    ) );
    addToSection( 5, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 7.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            global::environment::EAST
    ) );
    addToSection( 5, new CornerTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 8.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            ),
            global::environment::EAST,
            global::environment::DECOR_PROP_3
    ) );
    // trigger
    IntroLayoutTrigger* trigger = new IntroLayoutTrigger(
            glm::vec3(
                    global::TILE_SIZE * 8.0f, 0.0f,
                    -global::TILE_SIZE * 16.0f
            )
    );
    trigger->sections.push_back( 4 );
    trigger->sections.push_back( 5 );
    trigger->sections.push_back( 6 );
    addEntity( trigger );
    m_triggers.push_back( trigger );
}

void IntroCore::initSection6()
{
    addToSection( 6, new StraightTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 8.0f, 0.0f,
                    -global::TILE_SIZE * 15.0f
            ),
            global::environment::SOUTH,
            global::environment::DECOR_LIGHT_1
    ) );
    addToSection( 6, new EndTile(
            global::environment::INTRO,
            glm::vec3(
                    global::TILE_SIZE * 8.0f, 0.0f,
                    -global::TILE_SIZE * 14.0f
            ),
            global::environment::SOUTH,
            global::environment::DECOR_PROP_3

    ) );
    addToSection( 5, new TutorialText(
            glm::vec3(
                    global::TILE_SIZE * 8.0f, 0.0f,
                    -global::TILE_SIZE * 14.0f
            ),
            -180.0f,
            "Turn back",
            m_player
    ) );
}
