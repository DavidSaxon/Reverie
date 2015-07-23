#ifndef REVERIE_ENTITIES_GAMEPLAY_CURSEROOM_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_CURSEROOM_HPP_

#include "src/omicron/entity/Entity.hpp"

class CurseRoom : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    CurseRoom( const glm::vec3& pos );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void init();

    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    glm::vec3 m_position;
};

#endif
