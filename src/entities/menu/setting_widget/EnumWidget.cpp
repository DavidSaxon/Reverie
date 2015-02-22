#include "EnumWidget.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

EnumWidget::EnumWidget( const glm::vec3& position )
    :
    SettingWidget( position )
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
    m_text->setString( "1920x1080" );
    m_text->setHorCentred( true );
    m_text->setVertCentred( true );
    m_components.add( m_text );
}

void EnumWidget::update()
{
}

void EnumWidget::setActive( bool state )
{
    // super call
    SettingWidget::setActive( state );
}

void EnumWidget::setVisible( bool state )
{
    m_text->visible = state;
}
