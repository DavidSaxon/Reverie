#ifndef REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_VENDOR_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_ENVIRONMENT_VENDOR_HPP_

#include "src/data/Globals.hpp"
#include "src/omicron/entity/Entity.hpp"

namespace vendor
{

/** Vends a floor tile
@param stage the stage to vend a floor tile for
@param baseTransform the transformation to use for the tile
@return the mesh for the floor tile */
omi::Mesh* vendFloorTile(
        global::environment::Stage stage,
        omi::Transform* baseTransform );

/** Vends a ceiling tile
@param stage the stage to vend the ceiling tile for
@param baseTransform the transformation to use for the tile
@return the mesh for the ceiling tile */
omi::Mesh* vendCeilingTile(
        global::environment::Stage stage,
        omi::Transform* baseTransform );

/** Vends a wall tile
@param stage the stage to vend a wall tile for
@param baseTransform the base transformation to use for the tile
@param direction the direction the wall is on the tile
@return the mesh for the wall tile */
omi::Mesh* vendWallTile(
        global::environment::Stage stage,
        omi::Transform* baseTransform,
        global::environment::Direction direction );

/** Vends a straight skiting board for floor and ceiling
@param stage the stage to vend skirting for
@param baseTransform the base transformation to use for the skirting
@param direction the direction the skirting is on the tile
@return the mesh for the skirting */
omi::Mesh* vendSkirting(
        global::environment::Stage stage,
        omi::Transform* baseTransform,
        global::environment::Direction direction );

/** Vends a collider for a wall tile */
omi::CollisionDetector* vendWallCollider(
        void* entity,
        omi::Transform* baseTransform,
        global::environment::Direction baseDirection,
        global::environment::Direction colliderDirection );


} // namespace vendor

#endif
