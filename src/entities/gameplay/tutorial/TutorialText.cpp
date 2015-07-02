#include "src/entities/gameplay/tutorial/TutorialText.hpp"

#include "lib/Utilitron/MathUtil.hpp"

#include "src/entities/gameplay/Player.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TutorialText::TutorialText(
        const glm::vec3 basePos,
        float baseRot,
        const std::string& str,
        Player* player,
        bool isTitle )
    :
    m_basePos( basePos ),
    m_baseRot( baseRot ),
    m_str    ( str ),
    m_player ( player ),
    m_isTitle( isTitle )
{
}

//------------------------------------------------------------------------------
//                             PUBLIC MEMBER FUNCTION
//------------------------------------------------------------------------------

void TutorialText::init()
{
    // text position
    m_pos = new omi::Transform(
            "",
            glm::vec3( 0.0f, 1.7f, 0.0f ) + m_basePos,
            glm::vec3( 0.0f, m_baseRot, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( m_pos );

    // text
    m_text = omi::ResourceManager::getText(
            "intro_tutorial_text", "", m_pos );
    m_text->setString( m_str );
    m_text->setHorCentred ( true );
    m_text->setVertCentred( true );
    m_textComp.push_back( m_text );
    m_components.add( m_text );

    // title text
    if ( m_isTitle )
    {
        omi::Transform* m_titlePos = new omi::Transform(
                "",
                m_pos,
                glm::vec3( 0.0f, 0.4f, 0.0f ),
                glm::vec3(),
                glm::vec3( 2.0f, 2.0f, 2.0f )
        );
        m_components.add( m_titlePos );

        m_titleText = omi::ResourceManager::getText(
                "intro_title_text", "", m_titlePos );
        m_titleText->setHorCentred ( true );
        m_titleText->setVertCentred( true );
        m_textComp.push_back( m_titleText );
        m_components.add( m_titleText );

    }
}

void TutorialText::update()
{
    // calculate the distance from the player
    float distance = glm::distance(
            m_pos->translation.xz(),
            m_player->getTransform()->translation.xz()
    );

    // clamp distance to alpha
    if ( distance > 6.0 )
    {
        distance -= 6.0f;
        distance = util::math::clamp<float>( distance, 0.0f, 1.0f );
        distance = 1.0f - distance;
    }
    else
    {
        distance -= 1.0f;
        distance = util::math::clamp<float>( distance, 0.0f, 1.0f );
    }

    // fade out based on distance
    m_text->getMaterial().colour.a = distance;
    if ( m_isTitle )
    {
        m_titleText->getMaterial().colour.a = distance;
    }
}
