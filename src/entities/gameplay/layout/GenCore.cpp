#include "src/entities/gameplay/layout/GenCore.hpp"

#include "lib/Utilitron/MathUtil.hpp"

#include "src/entities/gameplay/CurseRoom.hpp"
#include "src/entities/gameplay/Phobetor.hpp"
#include "src/entities/gameplay/Player.hpp"
#include "src/entities/gameplay/ProcedualEntity.hpp"

#include "src/entities/gameplay/environment/tile/CornerTile.hpp"
#include "src/entities/gameplay/environment/tile/EndTile.hpp"
#include "src/entities/gameplay/environment/tile/IntersectionTile.hpp"
#include "src/entities/gameplay/environment/tile/StraightTile.hpp"
#include "src/entities/gameplay/environment/tile/TIntersectTile.hpp"

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


    // generate the initial level tiles
    genInitial();


    //---------------------------------TESTING----------------------------------

    // addEntity( new Phobetor() );

    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( 0.0f, 0.0f, global::TILE_SIZE ),
    //         global::environment::NORTH
    // ) );
    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( 0.0f, 0.0f, 0.0f ),
    //         global::environment::NORTH,
    //         global::environment::DECOR_LIGHT_1
    // ) );
    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE ),
    //         global::environment::NORTH,
    //         global::environment::DECOR_PROP_5
    // ) );
    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 2.0F ),
    //         global::environment::NORTH,
    //         global::environment::DECOR_LIGHT_2
    // ) );
    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 3.0F ),
    //         global::environment::NORTH,
    //         global::environment::DECOR_PROP_6
    // ) );
    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 4.0F ),
    //         global::environment::NORTH,
    //         global::environment::DECOR_LIGHT_1
    // ) );


    // // addEntity( new CornerTile(
    // //         m_stage,
    // //         glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 5.0F ),
    // //         global::environment::NORTH
    // // ) );

    // addEntity( new IntersectionTile(
    //         m_stage,
    //         glm::vec3( 0.0f, 0.0f, -global::TILE_SIZE * 5.0F ),
    //         global::environment::NORTH
    // ) );



    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( global::TILE_SIZE, 0.0f, -global::TILE_SIZE * 5.0F ),
    //         global::environment::EAST,
    //         global::environment::DECOR_LIGHT_1
    // ) );

    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( -global::TILE_SIZE, 0.0f, -global::TILE_SIZE * 5.0F ),
    //         global::environment::WEST,
    //         global::environment::DECOR_LIGHT_1
    // ) );

    // addEntity( new StraightTile(
    //         m_stage,
    //         glm::vec3( 0.0F, 0.0f, -global::TILE_SIZE * 6.0F ),
    //         global::environment::NORTH,
    //         global::environment::DECOR_LIGHT_1
    // ) );
    // addEntity( new EndTile(
    //         m_stage,
    //         glm::vec3( 0.0F, 0.0f, -global::TILE_SIZE * 7.0F ),
    //         global::environment::NORTH
    // ) );

}

void GenCore::update()
{
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GenCore::genInitial()
{
    // TODO: uncomment
    // decide on the initial number of exits
    unsigned exitCount = ( rand() % 2 ) + 3;

    // pick a direction
    global::environment::Direction direction =
            static_cast< global::environment::Direction >( rand() % 4 );
    // exit directions
    global::environment::Direction north =
            static_cast< global::environment::Direction >(
                    ( global::environment::NORTH + direction ) % 4 );
    global::environment::Direction east =
            static_cast< global::environment::Direction >(
                    ( global::environment::EAST + direction ) % 4 );
    global::environment::Direction south =
            static_cast< global::environment::Direction >(
                    ( global::environment::SOUTH + direction ) % 4 );
    global::environment::Direction west =
            static_cast< global::environment::Direction >(
                    ( global::environment::WEST + direction ) % 4 );

    // generate the first tile based on how many exits there are
    Tile* tile = NULL;
    if ( exitCount == 2 )
    {
        tile = new StraightTile(
                m_stage,
                glm::vec3( 0.0F, 0.0F, 0.0F ),
                direction,
                global::environment::DECOR_LIGHT_1 // TODO:?
        );

        // assign exits counts
        unsigned p1d = rand() % 10;
        unsigned p2d = rand() % 10;

        float pTotal = static_cast< float >( p1d + p2d );

        float exitTotal = static_cast< float >( ( rand() % 3 ) + 3 );

        p1d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p1d ) / pTotal ) * exitTotal
        ) );
        p2d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p2d ) / pTotal ) * exitTotal
        ) );

        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), north, p1d, true );
        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), south, p2d, true );
    }
    else if ( exitCount == 3 )
    {
        tile = new TIntersectTile(
                m_stage,
                glm::vec3( 0.0F, 0.0F, 0.0F ),
                direction,
                global::environment::DECOR_LIGHT_1 // TODO:?
        );

        // there are 2-6 passages to distribute
        unsigned p1d = rand() % 10;
        unsigned p2d = rand() % 10;
        unsigned p3d = rand() % 10;

        float pTotal = static_cast< float >( p1d + p2d + p3d );

        float exitTotal = static_cast< float >( ( rand() % 3 ) + 4 );

        p1d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p1d ) / pTotal ) * exitTotal
        ) );
        p2d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p2d ) / pTotal ) * exitTotal
        ) );
        p3d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p3d ) / pTotal ) * exitTotal
        ) );

        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), east,  p1d, true );
        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), west,  p2d, true );
        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), south, p3d, true );
    }
    else
    {
        tile = new IntersectionTile(
                m_stage,
                glm::vec3( 0.0F, 0.0F, 0.0F ),
                direction,
                global::environment::DECOR_LIGHT_1 // TODO:?
        );

        // there are 2-6 passages to distribute
        unsigned p1d = rand() % 10;
        unsigned p2d = rand() % 10;
        unsigned p3d = rand() % 10;
        unsigned p4d = rand() % 10;

        float pTotal = static_cast< float >( p1d + p2d + p3d + p4d );

        float exitTotal = static_cast< float >( ( rand() % 3 ) + 4 );

        p1d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p1d ) / pTotal ) * exitTotal
        ) );
        p2d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p2d ) / pTotal ) * exitTotal
        ) );
        p3d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p3d ) / pTotal ) * exitTotal
        ) );
        p4d = static_cast< unsigned > ( util::math::round(
                ( static_cast< float >( p4d ) / pTotal ) * exitTotal
        ) );

        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), north, p1d, true );
        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), east,  p2d, true );
        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), west,  p3d, true );
        genPassage( glm::vec3( 0.0F, 0.0F, 0.0F ), south, p4d, true );
    }

    // add the tile
    m_levelGrid->addTile( tile );
    addEntity( tile );
}

void GenCore::genPassage(
        const glm::vec3& p,
        global::environment::Direction direction,
        unsigned exits,
        bool hard )
{
    glm::vec3 pos( p );

    // generate a length for the passage between 2 and 8
    unsigned length = ( rand() % 7 ) + 2;

    // should we place a light in the wall way
    bool addLight = false;
    if ( length == 3 )
    {
        addLight = ( rand() % 2 ) == 0;
    }
    else if ( length > 3 )
    {
        addLight = true;
    }
    // position the light
    unsigned lightPosition = 0;
    if ( addLight )
    {
        lightPosition = ( length + 1 ) / 2;
        // int lightRand = rand() % 5;
        // if ( lightRand == 0 )
        // {
        //     --lightPosition;
        // }
        // else if ( lightRand == 1 )
        // {
        //     ++lightPosition;
        // }
    }

    // where will the exits be placed
    unsigned endExitCount = 0;
    if ( length > 4 )
    {
        unsigned exitRand = rand() % 45;
        if ( exitRand < 15 )
        {
            endExitCount = 1;
        }
        else if ( exitRand < 30 )
        {
            endExitCount = 2;
        }
        // clamp exits
        if ( endExitCount > exits )
        {
            endExitCount = exits;
        }
    }
    else
    {
        if ( exits > 2 )
        {
            exits = 2;
        }
        endExitCount = exits;
    }

    unsigned passageExitCount = exits - endExitCount;
    std::vector< unsigned > passageExits;
    std::vector< bool > exitDoubles;
    for ( unsigned i = 0; i < passageExitCount; ++i )
    {
        unsigned exitPos = ( rand() % ( length - 4 ) ) + 2;

        bool abortExitAssign = false;
        // check if the exit is too near
        std::vector< unsigned >::const_iterator existingExit =
                passageExits.begin();
        for ( ; existingExit != passageExits.end(); ++existingExit )
        {
            if ( exitPos         == *existingExit ||
                 ( exitPos - 1 ) == *existingExit ||
                 ( exitPos + 1 ) == *existingExit    )
            {
                abortExitAssign = true;
                break;
            }
        }

        if ( abortExitAssign )
        {
            continue;
        }

        passageExits.push_back( exitPos );
        if ( rand() % 2 == 0 )
        {
            exitDoubles.push_back( false );
        }
        else
        {
            exitDoubles.push_back( true );
        }
    }

    // create tiles for the length
    for ( unsigned i = 1; i <= length; ++i )
    {
        // calculate the position
        switch ( direction )
        {
            case global::environment::NORTH:
            {
                pos.z -= global::TILE_SIZE;
                break;
            }
            case global::environment::EAST:
            {
                pos.x += global::TILE_SIZE;
                break;
            }
            case global::environment::SOUTH:
            {
                pos.z += global::TILE_SIZE;
                break;
            }
            case global::environment::WEST:
            {
                pos.x -= global::TILE_SIZE;
                break;
            }
        }

        // is this an exit?
        bool isExit = false;
        bool isDoubleExit = false;
        for ( unsigned ie = 0; ie < passageExits.size(); ++ie )
        {
            if ( ( i - 1 ) == passageExits[ ie ] )
            {
                isExit = true;
                isDoubleExit = exitDoubles[ ie ];
                break;
            }
        }

        // direct for t intersections
        global::environment::Direction finalDirection = direction;
        global::environment::Direction midDirExit = direction;
        if ( isExit && !isDoubleExit )
        {
            if ( rand() % 2 == 0 )
            {
                finalDirection = static_cast< global::environment::Direction >(
                        ( finalDirection + 1 ) % 4
                );
                midDirExit = static_cast< global::environment::Direction >(
                        ( direction + 3 ) % 4
                );
            }
            else
            {
                finalDirection = static_cast< global::environment::Direction >(
                        ( finalDirection + 3 ) % 4
                );
                midDirExit = static_cast< global::environment::Direction >(
                        ( direction + 1 ) % 4
                );
            }
        }

        // tile decor
        unsigned long decor = 0;
        if ( addLight && i == lightPosition )
        {
            decor |= global::environment::DECOR_LIGHT_1;
        }

        // create a tile
        Tile* tile = NULL;
        if ( isExit && isDoubleExit )
        {
            tile = new IntersectionTile( m_stage, pos, finalDirection, decor );
            // TODO: gen passages

            if ( hard )
            {
                global::environment::Direction d1 =
                        static_cast< global::environment::Direction >(
                                ( finalDirection + 1 ) % 4
                        );
                global::environment::Direction d2 =
                        static_cast< global::environment::Direction >(
                                ( finalDirection + 3 ) % 4
                        );
                // TODO: ASSIGN EXITS
                genPassage( pos, d1, 0, false );
                genPassage( pos, d2, 0, false );
            }
        }
        else if ( isExit && !isDoubleExit )
        {
            tile = new TIntersectTile( m_stage, pos, finalDirection, decor );
            if ( hard )
            {
                // TODO: ASSIGN EXITS
                genPassage( pos, midDirExit, 0, false );
            }
        }
        else
        {
            tile = new StraightTile( m_stage, pos, finalDirection, decor );
        }

        // add the tile
        m_levelGrid->addTile( tile );
        tile->setSoftVisibility( hard );
        addEntity( tile );
    }

    // add the final tile
    Tile* tile = NULL;

    // calculate the position
    switch ( direction )
    {
        case global::environment::NORTH:
        {
            pos.z -= global::TILE_SIZE;
            break;
        }
        case global::environment::EAST:
        {
            pos.x += global::TILE_SIZE;
            break;
        }
        case global::environment::SOUTH:
        {
            pos.z += global::TILE_SIZE;
            break;
        }
        case global::environment::WEST:
        {
            pos.x -= global::TILE_SIZE;
            break;
        }
    }

    // decor
    unsigned long decor = 0;
    if ( !addLight || length >= 6 || ( addLight && ( ( rand() % 5 ) != 0 ) ) )
    {
        decor |= global::environment::DECOR_LIGHT_1;
    }

    if ( endExitCount == 0 )
    {
        tile = new EndTile( m_stage, pos, direction, decor );
    }
    else if ( endExitCount == 1 )
    {
        // should we flip the final corner?
        global::environment::Direction endDirection = direction;
        global::environment::Direction d =
                static_cast< global::environment::Direction >(
                        ( direction + 1 ) % 4
                );
        if ( rand() % 2 == 1 )
        {
            endDirection = static_cast< global::environment::Direction >(
                    ( endDirection + 1 ) % 4 );
            d = static_cast< global::environment::Direction >(
                    ( direction + 3 ) % 4 );
        }
        // create the tile
        tile = new CornerTile( m_stage, pos, endDirection, decor );

        // generate other exits
        if ( hard )
        {
            // TODO: ASSIGN EXIT COUNTS
            genPassage( pos, d, 0, false );
        }
    }
    else
    {
        tile = new TIntersectTile( m_stage, pos, direction, decor );

        // generate other exits
        if ( hard )
        {
            global::environment::Direction d1 =
                    static_cast< global::environment::Direction >(
                            ( direction + 1 ) % 4
                    );
            global::environment::Direction d2 =
                    static_cast< global::environment::Direction >(
                            ( direction + 3 ) % 4
                    );
            // TODO: ASSIGN EXIT COUNTS
            genPassage( pos, d1, 0, false );
            genPassage( pos, d2, 0, false );
        }
    }

    m_levelGrid->addTile( tile );
    tile->setSoftVisibility( hard );
    addEntity( tile );
}
