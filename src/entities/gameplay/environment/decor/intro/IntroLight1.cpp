#include "src/entities/gameplay/environment/decor/intro/IntroLight1.hpp"

#include "src/data/Globals.hpp"

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace
{

static const float    LIGHT_POWER     = 0.5f;
static const float    GLOW_BRIGHTNESS = 0.1f;
static const unsigned FLICKER_SPEED   = 10;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntroLight1::IntroLight1( omi::Transform* baseTransform, bool flicker )
    :
    Decor    ( baseTransform ),
    m_flicker( flicker ),
    m_lightOn( true )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void IntroLight1::init()
{
    // transform
    omi::Transform* transform = new omi::Transform(
            "",
            m_baseTransform,
            glm::vec3( 0.0f, 2.7f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( transform );

    // light
    m_lightSource = new omi::PointLight(
            "",
            transform,
            LIGHT_POWER,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            0.0f,
            0.1f,
            0.02f
    );
    m_components.add( m_lightSource );

    // light pane
    m_paneMesh = omi::ResourceManager::getMesh(
            "intro_light_1_pane", "", m_baseTransform );
    m_paneMesh->getMaterial().glow =
            new omi::Glow( glm::vec3( 1.0f, 1.0f, 1.0f ), GLOW_BRIGHTNESS );
    m_components.add( m_paneMesh );

    // light fitting
    omi::Mesh* fittingMesh = omi::ResourceManager::getMesh(
            "intro_light_1_fitting", "", m_baseTransform );
    fittingMesh->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_components.add( fittingMesh );

    // TESTING
    omi::Transform* textPos = new omi::Transform(
            "",
            glm::vec3( 0.0f, 1.7f, -3.5f ),
            glm::vec3( 0.0f, 0.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( textPos );
    omi::Text* text = omi::ResourceManager::getText(
            "intro_tutorial_text", "", textPos );
    text->setHorCentred( true );
    m_components.add( text );
}

void IntroLight1::update()
{
    if ( !m_flicker || global::pause )
    {
        return;
    }

    // flicker the light
    if ( rand() % FLICKER_SPEED == 0 )
    {
        // switch state
        m_lightOn = !m_lightOn;
        // apply state
        if ( m_lightOn )
        {
            m_lightSource->setPower( LIGHT_POWER );
            m_paneMesh->getMaterial().glow->setBrightness( GLOW_BRIGHTNESS );
        }
        else
        {
            m_lightSource->setPower( 0.0f );
            m_paneMesh->getMaterial().glow->setBrightness( 0.0f );
        }
    }
}
