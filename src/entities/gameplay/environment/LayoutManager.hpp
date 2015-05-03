#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_LAYOUTMANAGER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_LAYOUTMANAGER_HPP_

#include "src/data/Globals.hpp"
#include "src/omicron/entity/Entity.hpp"

/**************************************************************************\
| The layout manager controls Reverie environment generation. The level is |
| stored is a linked list type structure of segments.                      |
\**************************************************************************/
class LayoutManager : public omi::Entity
{
public:

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

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Does initial generation for the the intro */
    void introInit();

    /** Does initial generation for a non-intro stage, only used in testing */
    void nonIntroInit();
};

#endif
