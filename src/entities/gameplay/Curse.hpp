#ifndef REVERIE_ENTITIES_GAMEPLAY_CURSE_HPP_
    #define REVERIE_ENTITIES_GAMEPLAY_CURSE_HPP_

#include <string>
#include <vector>

namespace curse
{

enum Type
{
    LOST,
    DARKNESS,
    HUNTED,
    MADNESS
};

} // namespace curse

class Curse
{
public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    size_t level;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Curse();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void addLevel( const std::string& title, const std::string& description );

    size_t getCount() const;

    const std::string& getTitle( size_t index ) const;

    const std::string& getDescription( size_t index ) const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    std::vector< std::string > m_titles;
    std::vector< std::string > m_descriptions;
};

#endif
