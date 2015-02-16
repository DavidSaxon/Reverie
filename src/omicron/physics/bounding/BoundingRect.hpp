#ifndef OMICRON_PHYSICS_BOUNDING_BOUNDINGRECT_HPP_
#   define OMICRON_PHYSICS_BOUNDING_BOUNDINGRECT_HPP_

#include "BoundingShape.hpp"

namespace omi {

/*********************************************\
| A two dimensional rectangle shaped bounding |
\*********************************************/
class BoundingRect : public BoundingShape {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a new bounding rectangle with no offset
    @param size the width and height of the rectangle
    @param transform the transform to use for the rectangle's location */
    BoundingRect( const glm::vec2& size, Transform* transform ) :
        BoundingShape( bounding::RECTANGLE, transform ),
        m_size( size )
    {
    }

    /** Creates a new bounding rectangle
    @param size the width and height of the rectangle
    @param transform the transform to use for the rectangle's location
    @param offset the offset to use for the rectangle's location */
    BoundingRect(
            const glm::vec2& size,
            Transform* transform,
            const glm::vec3& offset ) :
        BoundingShape( bounding::RECTANGLE, transform, offset ),
        m_size( size )
    {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** @return the size of the rectangle */
    const glm::vec2& getSize() const
    {
        return m_size;
    }

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the size of the rectangle
    glm::vec2 m_size;

};

} // namespace omi

#endif
