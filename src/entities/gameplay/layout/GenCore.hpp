#ifndef REVERIE_ENTITIES_GAMEPLAY_LAYOUT_GENCORE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_LAYOUT_GENCORE_HPP_

#include "src/data/Globals.hpp"
#include "src/entities/gameplay/layout/AbstractLayoutCore.hpp"

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

    // reference to the player
    Player* m_player;
};

#endif
