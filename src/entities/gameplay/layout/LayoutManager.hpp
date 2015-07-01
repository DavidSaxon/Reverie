#ifndef REVERIE_ENTITIES_GAMEPLAY_LAYOUT_MANAGER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_LAYOUT_MANAGER_HPP_

#include "src/data/Globals.hpp"
#include "src/omicron/entity/Entity.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class AbstractLayoutCore;
class Player;

class LayoutManager : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    LayoutManager( Player* player );

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

    // the current stage the environment is in
    global::environment::Stage m_stage;
    // the current layout core
    AbstractLayoutCore* m_layoutCore;

    // pointer to the player
    Player* m_player;
};

#endif
