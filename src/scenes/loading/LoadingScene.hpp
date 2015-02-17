#ifndef REVERIE_SCENES_LOADINGSCENE_HPP_
#   define REVERIE_SCENES_LOADINGSCENE_HPP_

#include "src/omicron/scene/Scene.hpp"

/**********************************************\
| This scene handles the loading of resources. |
\**********************************************/
class LoadingScene : public omi::Scene {
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
