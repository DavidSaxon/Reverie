#include "Curse.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Curse::Curse()
{
    level = 0;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Curse::addLevel(
        const std::string& title,
        const std::string& description )
{
    m_titles.push_back      ( title );
    m_descriptions.push_back( description );
}

size_t Curse::getCount() const
{
    return m_titles.size();
}

const std::string& Curse::getTitle( size_t index ) const
{
    return m_titles[ index ];
}

const std::string& Curse::getDescription( size_t index ) const
{
    return m_descriptions[ index ];
}
