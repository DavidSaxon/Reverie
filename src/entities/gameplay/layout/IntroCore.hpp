#ifndef REVERIE_ENTITIES_GAMEPLAY_LAYOUT_INTROCORE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_LAYOUT_INTROCORE_HPP_

#include "src/entities/gameplay/layout/AbstractLayoutCore.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class CurseRoom;
class IntroLayoutTrigger;
class Player;
class ProcedualEntity;
class StateTrigger;

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
    // initial visible sections
    std::vector< size_t > m_initalVis;
    // layout triggers
    std::vector< IntroLayoutTrigger* > m_triggers;

    // end trigger
    StateTrigger* m_endTrigger;
    bool m_end;

    // curse room
    CurseRoom* m_curseRoom;
    ProcedualEntity* m_replaceTile;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void addToSection( size_t section, ProcedualEntity* entity );

    void setSectionVisibility( size_t section, bool state );

    void setSectionsVisible( const std::vector< size_t >& sections );

    void initSection0();

    void initSection1();

    void initSection2();

    void initSection3();

    void initSection4();

    void initSection5();

    void initSection6();
};

#endif
