#ifndef REVERIE_ENTITIES_MENU_SETTING_WIDGET_SLIDERWIDGET_HPP_
#   define REVERIE_ENTITIES_MENU_SETTING_WIDGET_SLIDERWIDGET_HPP_

#include "SettingWidget.hpp"

/*********************************************************\
| A widget that can be used to change a continuous value. |
\*********************************************************/
class SliderWidget : public SettingWidget {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new slider setting widget
    @param position the position to display the widget at
    @param low the lowest possible value on the slider
    @param high the highest possible value on the slider
    @param defaultValue the initial value of the slider widget */
    SliderWidget(
            const glm::vec3& position,
            float low,
            float high,
            float defaultValue );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    /** #Override */
    void setActive( bool state );

    /** #Override */
    void setVisible( bool state );

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the possible range of the slider
    float m_low;
    float m_high;
    // the current value of the slider
    float m_current;
    // the speed of the slider
    float m_speed;

    // the bar of the slider
    omi::Sprite* m_bar;
    // the arrow of the slider
    omi::Transform* m_arrowPos;
    omi::Sprite* m_arrow;
    // the text of the slider's value
    omi::Text* m_text;
};

#endif