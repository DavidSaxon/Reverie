#ifndef REVERIE_SCENES_GAMEPLAYSCENE_HPP_
#   define REVERIE_SCENES_GAMEPLAYSCENE_HPP_

#include "src/omicron/input/Input.hpp"
#include "src/omicron/scene/Scene.hpp"

/****************************************************\
| The main scene of reverie which controls game-play. |
\****************************************************/
class GameplayScene : public omi::Scene {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void init();

    /** #Override */
    virtual bool update();

    /** #Override */
    virtual omi::Scene* nextScene();
};

#endif
