#include "GenTrigger.hpp"

#include "src/entities/gameplay/environment/tile/Tile.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

GenTrigger::GenTrigger( const glm::vec3& position )
    :
    m_position( position ),
    m_active  ( false ),
    m_baseTile( NULL )
{
    // add initial vectors for each direction
    m_passages[ global::environment::NORTH ] = std::vector< Tile* >();
    m_passages[ global::environment::SOUTH ] = std::vector< Tile* >();
    m_passages[ global::environment::EAST  ] = std::vector< Tile* >();
    m_passages[ global::environment::WEST  ] = std::vector< Tile* >();
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GenTrigger::init()
{
    // transform of the trigger
    omi::Transform* transform = new omi::Transform(
            "",
            m_position,
            glm::vec3(),
            glm::vec3( 1.0F, 1.0F, 1.0F )
    );
    m_components.add( transform );

    // collision detector
    m_detector = new omi::CollisionDetector( "", "gen_trigger", this );
    m_detector->addBounding( new omi::BoundingRect(
            glm::vec2( global::TILE_SIZE, global::TILE_SIZE ),
            transform
    ) );
    m_components.add( m_detector );

    // soft detector
    m_softDector = new omi::CollisionDetector( "", "gen_trigger", this );
    m_softDector->addBounding( new omi::BoundingRect(
            glm::vec2( global::TILE_SIZE * 2.0F, global::TILE_SIZE * 2.0F ),
            transform
    ) );
    m_components.add( m_softDector );
}

void GenTrigger::update()
{
    if ( m_softDector->getCollisionData().size() > 0 )
    {
        applySoftVis();
    }

    if ( m_detector->getCollisionData().size() > 0 && !m_active )
    {
        m_active = true;
        // follow passages and gen
        traverseActive();
    }
}

Tile* GenTrigger::getBaseTile()
{
    return m_baseTile;
}

void GenTrigger::setBaseTile( Tile* tile )
{
    m_baseTile = tile;
}

void GenTrigger::appendTile(
        global::environment::Direction direction,
        Tile* tile )
{
    m_passages[ direction ].push_back( tile );
}

void GenTrigger::appendTiles(
            global::environment::Direction direction,
            std::vector< Tile* >& tiles )
{
    std::vector< Tile* >::iterator it = tiles.begin();
    for ( ; it != tiles.end(); ++it )
    {
        m_passages[ direction ].push_back( *it );
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GenTrigger::applySoftVis()
{
    // to be super save make sure the base tile is visible;
    if ( m_baseTile != NULL )
    {
        m_baseTile->setSoftVisibility( true );
    }

    // ensure all directly adjacent passages are visible
    for ( int i = 0; i < 4; ++i )
    {
        global::environment::Direction direction =
                static_cast< global::environment::Direction >( i );
        std::vector< Tile* >::iterator it = m_passages[ direction ].begin();
        for( ; it != m_passages[ direction ].end(); ++it )
        {
            // ( *it )->setSoftVisibility( true );
        }
    }
}

void GenTrigger::traverseActive()
{
    // iterator over the directions and traverse further
    for ( int i = 0; i < 4; ++i )
    {
        global::environment::Direction direction =
                static_cast< global::environment::Direction >( i );
        std::vector< Tile* >::iterator it = m_passages[ direction ].begin();
        for( ; it != m_passages[ direction ].end(); ++it )
        {
            // does the tile have a trigger?
            GenTrigger* trigger = ( *it )->getTrigger();
            if ( trigger != NULL )
            {
                // apply soft visibility false to secondary, and delete tertiary
                trigger->traverseSecondary( direction );

                // TODO:
                // gen new for missing secondary, need to notify for GenCore
            }
        }
    }
}

void GenTrigger::traverseSecondary( global::environment::Direction iDir )
{
    global::environment::Direction inverse =
            static_cast< global::environment::Direction >( iDir + 2 );

    for ( int i = 0; i < 4; ++i )
    {
        global::environment::Direction direction =
                static_cast< global::environment::Direction >( i );

        // skip the input direction and the inverse of the input direction
        if ( direction == iDir || direction == inverse )
        {
            continue;
        }

        for( size_t i = 0; i < m_passages.size(); ++i )
        {
            // tile
            Tile* currentTile = m_passages[ direction ][ i ];

            // set soft visibility to false
            if ( i < 2 )
            {
                currentTile->setSoftVisibility( true );
            }
            else
            {
                currentTile->setSoftVisibility( false );
            }

            // does the tile have a trigger?
            GenTrigger* trigger = currentTile->getTrigger();
            if ( trigger != NULL )
            {
                // delete other tertiary passages (that aren't this)
                // TODO:
            }
        }
    }
}
