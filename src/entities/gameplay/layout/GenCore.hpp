#ifndef REVERIE_ENTITIES_GAMEPLAY_LAYOUT_GENCORE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_LAYOUT_GENCORE_HPP_

#include <memory>

#include "src/data/Globals.hpp"
#include "src/entities/gameplay/layout/AbstractLayoutCore.hpp"
#include "src/entities/gameplay/layout/LevelGrid.hpp"


//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Player;
class ProcedualEntity;

class GenCore : public AbstractLayoutCore
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    GenCore( global::environment::Stage stage, Player* player );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // stage
    global::environment::Stage m_stage;

    // the level grid
    std::unique_ptr< LevelGrid > m_levelGrid;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Generates the initial layout when empty */
    void genInitial();
};

#endif