#ifndef REVERIE_ENTITIES_MENU_SETTING_WIDGET_ENUMWIDGET_HPP_
#   define REVERIE_ENTITIES_MENU_SETTING_WIDGET_ENUMWIDGET_HPP_

#include "SettingWidget.hpp"

class EnumWidget : public SettingWidget {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    EnumWidget( const glm::vec3& position );

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

    // the text of the widget
    omi::Text* m_text;

    // TODO: arrows?? maybe should be in base class
};

#endif
