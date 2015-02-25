#ifndef REVERIE_ENTITIES_MENU_SETTING_WIDGET_ENUMWIDGET_HPP_
#   define REVERIE_ENTITIES_MENU_SETTING_WIDGET_ENUMWIDGET_HPP_

#include "SettingWidget.hpp"

#include "src/omicron/Omicron.hpp"

namespace setting_function {

/** Changes resolution */
inline void resolution( const std::string& value )
{
    std::cout << "value: " << value << std::endl;

    // parse the value
    unsigned p = value.find( 'x' );
    std::cout << "side a: " << value.substr( 0, p ) << std::endl;
    std::cout << "side b: " << value.substr( p, value.length() ) << std::endl;

    omi::renderSettings.setResolution( glm::vec2(
            atoi( value.substr( 0, p ).c_str() ),
            atoi( value.substr( p + 1, value.length() ).c_str() )
    ) );
}

} // namespace setting_function


/*******************************************************\
| A widget that can be used to change a discreet value. |
\*******************************************************/
class EnumWidget : public SettingWidget {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new enumerator setting widget
    @param position the position to display the widget at
    @param values the possible values of the widget
    @param defaultValue the index of the value to first display on the widget */
    EnumWidget(
            const glm::vec3& position,
            std::vector<std::string> values,
            unsigned defaultValue );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** Override */
    void update();

    /** #Override */
    void setActive( bool state );

    /** #Override */
    void setVisible( bool state );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of possible values of the widget
    std::vector<std::string> m_values;
    // the index of the default value to show
    unsigned m_defaultValue;
    // the current index
    int m_currentIndex;

    // the text of the widget
    omi::Text* m_text;

    // TODO: arrows?? maybe should be in base class
};

#endif
