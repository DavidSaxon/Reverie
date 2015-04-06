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
    std::vector<BoundingShape*> collisionBoundings;
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
            std::cout << "colliding with: "  << b.size() << std::endl;

            colliderBounding = bounding;
            collisionBoundings = b;
            // reset position
            bounding->getTransform()->translation = orginalPos;
            break;
        }

        // reset position
        bounding->getTransform()->translation = orginalPos;
    }

    if ( colliderBounding != NULL && !collisionBoundings.empty() )
    {
        // make a copy of the movement vector
        glm::vec3 new_move( move );

        BoundingRect* playerRect =
                static_cast<BoundingRect*>( colliderBounding );

        // sort the boundings based on distance
        std::vector<BoundingRect*> sorted;
        while ( !collisionBoundings.empty() )
        {
            float minDistance = 99999.0f;
            unsigned nearest = 0;

            for ( unsigned i = 0; i < collisionBoundings.size(); ++i )
            {
                BoundingRect* obRect =
                        static_cast<BoundingRect*>( collisionBoundings[ i ] );
                // calculate distance
                float distance = glm::distance(
                        obRect->getTransform()->translation,
                        playerRect->getTransform()->translation
                );
                // check if we've found the nearest
                if ( distance < minDistance )
                {
                    minDistance = distance;
                    nearest = i;
                }
            }

            // add the nearest into the next spot in the sorted list
            sorted.push_back( static_cast<BoundingRect*>(
                    collisionBoundings[ nearest ] ) );
            collisionBoundings.erase( collisionBoundings.begin() + nearest );
        }

        for ( std::vector<BoundingRect*>::iterator it = sorted.begin();
              it != sorted.end(); ++it )
        {
            // TODO: should support other shapes
            // cast to rectangle
            BoundingRect* rect1 =
                    static_cast<BoundingRect*>( colliderBounding );
            BoundingRect* rect2 = *it;


            // calculate the best position
            glm::vec3 temp_move( new_move );

            // calculate the angle
            float angle = vecutil::angleBetween(
                    rect1->getTransform()->translation.xz(),
                    rect2->getTransform()->translation.xz() );

            // apply shift movement
            if ( angle > 50.0f && angle <= 130.0f )
            {
                temp_move.z =
                    ( rect2->getTransform()->translation.z +
                    ( rect2->getSize().y / 2.0f ) ) -
                    ( rect1->getTransform()->translation.z -
                    ( rect1->getSize().y / 2.0f ) );
                if ( temp_move.z > new_move.z )
                {
                    new_move.z = temp_move.z;
                }
            }
            else if ( angle > 140.0f && angle <= 220.0f )
            {
                temp_move.x =
                    ( rect2->getTransform()->translation.x -
                    ( rect2->getSize().x / 2.0f ) ) -
                    ( rect1->getTransform()->translation.x +
                    ( rect1->getSize().x / 2.0f ) );
                std::cout << "std x" << std::endl;
                if ( temp_move.x < new_move.x )
                {
                    new_move.x = temp_move.x;
                }
            }
            else if ( angle > 230.0f && angle <= 310.0f )
            {
                temp_move.z =
                    ( rect2->getTransform()->translation.z -
                    ( rect2->getSize().y / 2.0f ) ) -
                    ( rect1->getTransform()->translation.z +
                    ( rect1->getSize().y / 2.0f ) );
                if ( temp_move.z < new_move.z )
                {
                    new_move.z = temp_move.z;
                }
            }
            else if ( ( angle > 320.0f && angle <= 360.0f ) ||
                      ( angle >= 0.0f && angle <= 40.0f )      )
            {
                temp_move.x =
                    ( rect2->getTransform()->translation.x +
                    ( rect2->getSize().x / 2.0f ) ) -
                    ( rect1->getTransform()->translation.x -
                    ( rect1->getSize().x / 2.0f ) );
                std::cout << "final x" << std::endl;
                if ( temp_move.x > new_move.x )
                {
                    new_move.x = temp_move.x;
                }
            }
        }

        // TODO: apply friction if new move is less than last move

        return new_move;
    }

    return move;
}

} // namespace omi
