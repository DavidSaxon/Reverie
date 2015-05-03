#ifndef OMICRON_RESOURCE_PACK_BUILD_H_
#   define OMICRON_RESOURCE_PACK_BUILD_H_

#include "src/omicron/resource/ResourceManager.hpp"
#include "src/override/ResourceGroups.hpp"

/************************************************************************\
| Contains all resources packs that can be built to add resources to the |
| resource manager.                                                      |
\************************************************************************/
namespace pack {

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

//--------------------------------RESOURCE PACKS--------------------------------

void buildAllPack();

void buildDebugPack();

void buildStartUpPack();

void buildLoadingPack();

void buildMenuPack();

void buildPlayerPack();

void buildIntroPack();

void buildFacilityPack();

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/** Builds all resource packs */
inline void build()
{
    buildAllPack();
    buildDebugPack();
    buildStartUpPack();
    buildLoadingPack();
    buildMenuPack();
    buildPlayerPack();
    buildIntroPack();
    buildFacilityPack();
}

} // namespace pack

#endif
