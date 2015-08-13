#include "src/entities/gameplay/environment/decor/intro/IntroLight1.hpp"

#include <cmath>

#include "src/data/Globals.hpp"

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace
{

static const float LIGHT_POWER       = 0.5f;
static const float GLOW_BRIGHTNESS   = 0.1f;
static const float FLICKER_SPEED     = 0.1f;
static const float FLICKER_THRESHOLD = 3.0f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

IntroLight1::IntroLight1(
        omi::Transform* baseTransform,
        bool flicker,
        bool phobetor )
    :
    Decor             ( baseTransform ),
    m_flicker         ( flicker ),
    m_phobetor        ( phobetor ),
    m_lightOn         ( true ),
    m_flickerCounter  ( 0.0f ),
    m_flickerThreshold( 3.0f )
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
    m_lightComp.push_back( m_lightSource );
    m_components.add( m_lightSource );

    // light pane
    m_paneMesh = omi::ResourceManager::getMesh(
            "intro_light_1_pane", "", m_baseTransform );
    m_paneMesh->getMaterial().glow =
            new omi::Glow( glm::vec3( 1.0f, 1.0f, 1.0f ), GLOW_BRIGHTNESS );
    m_meshComp.push_back( m_paneMesh );
    m_components.add( m_paneMesh );

    // light fitting
    omi::Mesh* fittingMesh = omi::ResourceManager::getMesh(
            "intro_light_1_fitting", "", m_baseTransform );
    fittingMesh->getMaterial().specular =
        new omi::Specular( 64.0f, glm::vec3( 1.0f, 1.0f, 1.0f ) );
    m_meshComp.push_back( fittingMesh );
    m_components.add( fittingMesh );
}

void IntroLight1::update()
{
    if ( !m_flicker || global::pause )
    {
        return;
    }

    // increase the flicker counter
    m_flickerCounter += FLICKER_SPEED * omi::fpsManager.getTimeScale();

    // flicker the light if we've reached the threshold
    if ( m_flickerCounter >= m_flickerThreshold )
    {
        // reset counter
        // m_flickerCounter = fmod( m_flickerCounter, m_flickerThreshold );
        m_flickerCounter = 0.0f;
        // recalculate random threshold
        m_flickerThreshold =
                ( static_cast<float>( rand() % 1000 ) / 1000.0f ) *
                FLICKER_THRESHOLD;

        // switch state
        m_lightOn = !m_lightOn;
        // apply state
        if ( m_lightOn && !m_phobetor )
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
