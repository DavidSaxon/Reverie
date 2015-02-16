#ifndef OMICRON_PHSYICS_BOUNDING_BOUNDINGSHAPE_H_
#   define OMICRON_PHSYICS_BOUNDING_BOUNDINGSHAPE_H_

#define GLM_FORCE_RADIANS
#define GLM_SWIZZLE

#include "lib/glm/glm.hpp"

#include "src/omicron/component/Transform.hpp"

namespace omi {

namespace bounding {

//! the bounding shape types
enum Type {
    CIRCLE,
    RECTANGLE,
    SPHERE
};

} // namespace bounding

/******************************************************************************\
| Abstract base class that defines a shape that used determining the bounds of |
| an object.                                                                   |
\******************************************************************************/
class BoundingShape {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    BoundingShape( bounding::Type type, Transform* transform ) :
        m_type     ( type ),
        m_transform( transform )
    {
    }

    BoundingShape( bounding::Type type,
            Transform* transform, const glm::vec3& offset ) :
        m_type     ( type ),
        m_transform( transform ),
        m_offset   ( offset )
    {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~BoundingShape()
    {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** @return the type of this */
    bounding::Type getType() const
    {
        return m_type;
    }

    /** @return the transform defining the location of the bounding */
    Transform* getTransform()
    {
        return m_transform;
    }

    /** @return the offset of the position of the bounding shape */
    const glm::vec3& getOffset() const
    {
        return m_offset;
    }

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the type of bounding this is
    bounding::Type m_type;
    // the transform defining the position of this bounding
    Transform* m_transform;
    // the offset of this bounding from the position of the transform
    glm::vec3 m_offset;
};

} // namespace omi

#endif
