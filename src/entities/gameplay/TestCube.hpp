#ifndef REVERIE_ENTITIES_GAMEPLAY_TESTCUBE_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_TESTCUBE_HPP_

#include "src/omicron/entity/Entity.hpp"

class TestCube : public omi::Entity {
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

    omi::Transform* m_t1;

};

#endif
