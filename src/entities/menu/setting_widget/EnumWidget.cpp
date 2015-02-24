#include "EnumWidget.hpp"

#include "src/data/Globals.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

EnumWidget::EnumWidget(
        const glm::vec3& position,
        std::vector<std::string> values,
        unsigned defaultValue )
    :
    SettingWidget ( position ),
    m_values      ( values ),
    m_defaultValue( defaultValue )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void EnumWidget::init()
{
    // create the text label
    omi::Transform* t = new omi::Transform(
            "",
            m_position,
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( t );
    m_text = omi::ResourceManager::getText(
            "pause_secondary_item_text", "", t
    );
    m_text->gui = true;
    // TODO: set to current enum
    m_text->setString( m_values[ m_defaultValue ] );
    m_text->setHorCentred( true );
    m_text->setVertCentred( true );
    m_text->visible = false;
    m_components.add( m_text );
}

void EnumWidget::update()
{
    // do nothing if the widget is not active
    if ( !m_active )
    {
        return;
    }
}

void EnumWidget::setActive( bool state )
{
    // super call
    SettingWidget::setActive( state );

    // colour the widget
    if ( state )
    {
        m_text->getMaterial().colour = global::MENU_ITEM_SELECTED_COLOUR;
    }
    else
    {
        m_text->getMaterial().colour = global::MENU_ITEM_NON_SELECTED_COLOUR;
    }
}

void EnumWidget::setVisible( bool state )
{
    m_text->visible = state;
}
