#ifndef REVERIE_ENTITIES_GAMEPLAY_LAYOUT_ABSTRACTLAYOUTCORE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_LAYOUT_ABSTRACTLAYOUTCORE_HPP_

#include "src/omicron/entity/Entity.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Player;

class AbstractLayoutCore : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    AbstractLayoutCore( Player* player );

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // a pointer to the player
    Player* m_player;

};

#endif
