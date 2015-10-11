#ifndef REVERIE_ENTITIES_GAMEPLAY_GEN_GENTRIGGER_HPP_
#define REVERIE_ENTITIES_GAMEPLAY_GEN_GENTRIGGER_HPP_

#include "src/omicron/entity/Entity.hpp"

#include "src/data/Globals.hpp"

class Tile;

class GenTrigger : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    GenTrigger( const glm::vec3& position );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    Tile* getBaseTile();

    void setBaseTile( Tile* tile );

    void appendTile( global::environment::Direction direction, Tile* tile );

    void appendTiles(
                global::environment::Direction direction,
                std::vector< Tile* >& tiles );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //  the position of the trigger
    const glm::vec3 m_position;
    // the collision detector associated with the trigger
    omi::CollisionDetector* m_detector;
    // the collision detector for soft visibility
    omi::CollisionDetector* m_softDector;

    bool m_active;

    // the tile this trigger is located at
    Tile* m_baseTile;
    // mapping from directions to passages of Tiles extending from this trigger
    std::map< global::environment::Direction, std::vector< Tile* > > m_passages;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void applySoftVis();

    void traverseActive();

    void traverseSecondary( global::environment::Direction iDir );
};

#endif
