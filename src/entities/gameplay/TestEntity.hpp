#ifndef REVERIE_ENTITIES_GAMEPLAY_TESTENTITY_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_TESTENTITY_HPP_

#include "src/omicron/entity/Entity.hpp"

class TestEntity : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

};

#endif
