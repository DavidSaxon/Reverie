#include "CollisionChecker.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

CollisionChecker::CollisionChecker( const std::string& id ) :
    Physics( id )
{
}

CollisionChecker::CollisionChecker(
        const std::string& id,
        const std::vector<BoundingShape*>& boundings )
    :
    Physics( id ),
    m_boundings( boundings )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

const std::vector<BoundingShape*> CollisionChecker::getBoundings() const
{
    return m_boundings;
}

void CollisionChecker::addBounding( BoundingShape* bounding )
{
    m_boundings.push_back( bounding );
}

bool CollisionChecker::forwardCheck(
        const glm::vec3& move,
        const std::string& group )
{
    bool collision = false;
    // check each bounding
    for ( std::vector<BoundingShape*>::iterator it = m_boundings.begin();
          it != m_boundings.end(); ++it )
    {
        BoundingShape* bounding = *it;

        // change the position of the transform of the bounding
        glm::vec3 orginalPos = bounding->getTransform()->translation;
        glm::vec3 newPos = orginalPos + move;
        bounding->getTransform()->translation = newPos;

        if ( !CollisionDetect::checkAgainstGroup( bounding, group ).empty() )
        {
            collision = true;
            // reset position
            bounding->getTransform()->translation = orginalPos;
            break;
        }

        // reset position
        bounding->getTransform()->translation = orginalPos;
    }

    return collision;
}

glm::vec3 CollisionChecker::forwardBestCheck(
            const glm::vec3& move,
            const std::string& group )
{
    BoundingShape* colliderBounding = NULL;
    BoundingShape* collisionBounding = NULL;
    // check each bounding
    for ( std::vector<BoundingShape*>::iterator it = m_boundings.begin();
          it != m_boundings.end(); ++it )
    {
        BoundingShape* bounding = *it;

        // change the position of the transform of the bounding
        glm::vec3 orginalPos = bounding->getTransform()->translation;
        glm::vec3 newPos = orginalPos + move;
        bounding->getTransform()->translation = newPos;

        const std::vector<BoundingShape*> b =
                CollisionDetect::checkAgainstGroup( bounding, group );
        if ( !b.empty() )
        {
            colliderBounding = bounding;
            collisionBounding = b.front();
            // reset position
            bounding->getTransform()->translation = orginalPos;
            break;
        }

        // reset position
        bounding->getTransform()->translation = orginalPos;
    }

    if ( colliderBounding != NULL && collisionBounding != NULL )
    {
        // TODO: should support other shapes
        // cast to rectangle
        BoundingRect* rect1 = static_cast<BoundingRect*>( colliderBounding );
        BoundingRect* rect2 = static_cast<BoundingRect*>( collisionBounding );

        // calculate the best position
        glm::vec3 new_move( move );

        // calculate the angle
        float angle = vecutil::angleBetween(
                rect1->getTransform()->translation.xz(),
                rect2->getTransform()->translation.xz() );

        // apply shift movement
        if ( angle > 45.0f && angle <= 135.0f )
        {
            new_move.z =
                ( rect2->getTransform()->translation.z +
                ( rect2->getSize().y / 2.0f ) ) -
                ( rect1->getTransform()->translation.z -
                ( rect1->getSize().y / 2.0f ) );
        }
        else if ( angle > 135.0f && angle <= 225.0f )
        {
            new_move.x =
                ( rect2->getTransform()->translation.x -
                ( rect2->getSize().x / 2.0f ) ) -
                ( rect1->getTransform()->translation.x +
                ( rect1->getSize().x / 2.0f ) );
        }
        else if ( angle > 225.0f && angle <= 315.0f )
        {
            new_move.z =
                ( rect2->getTransform()->translation.z -
                ( rect2->getSize().y / 2.0f ) ) -
                ( rect1->getTransform()->translation.z +
                ( rect1->getSize().y / 2.0f ) );
        }
        else
        {
            new_move.x =
                ( rect2->getTransform()->translation.x +
                ( rect2->getSize().x / 2.0f ) ) -
                ( rect1->getTransform()->translation.x -
                ( rect1->getSize().x / 2.0f ) );
        }


        // TODO: second iteration

        return new_move;
    }

    return move;
}

} // namespace omi
