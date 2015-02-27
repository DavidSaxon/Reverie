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
    m_defaultValue( defaultValue ),
    m_currentIndex( static_cast<int>( defaultValue ) )
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
        m_arrowDown = false;
        return;
    }

    bool changed = false;
    if ( omi::input::isKeyPressed( omi::input::key::RIGHT ) &&
         !m_arrowDown                                          )
    {
        m_arrowDown = true;
        changed = true;
        ++m_currentIndex;
    }
    else if (
        omi::input::isKeyPressed( omi::input::key::LEFT ) &&
        !m_arrowDown                                         )
    {
        m_arrowDown = true;
        changed = true;
        --m_currentIndex;
    }
    else if ( !omi::input::isKeyPressed( omi::input::key::RIGHT ) &&
              !omi::input::isKeyPressed( omi::input::key::LEFT )  &&
               m_arrowDown                                           )
    {
        m_arrowDown = false;
    }

    // clamp the index
    if ( m_currentIndex < 0 )
    {
        m_currentIndex = m_values.size() - 1;
    }
    else if ( m_currentIndex >= static_cast<int>( m_values.size() ) )
    {
        m_currentIndex = 0;
    }

    // the value has changed
    if ( changed )
    {
        // call change function
        // setting_function::resolution( m_values[ m_currentIndex ] );
        // update the text
        m_text->setString( m_values[ m_currentIndex ] );
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
