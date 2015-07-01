#ifndef REVERIE_ENTITIES_GAMEPLAY_LAYOUT_INTROCORE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_LAYOUT_INTROCORE_HPP_

#include "src/entities/gameplay/layout/AbstractLayoutCore.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Player;
class ProcedualEntity;

class IntroCore : public AbstractLayoutCore
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    IntroCore( Player* player );

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

    // the layout sections
    std::vector< std::vector< ProcedualEntity* > > m_sections;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void addToSection( size_t section, ProcedualEntity* entity );

    void setSectionVisibility( size_t section, bool state );
};

#endif
