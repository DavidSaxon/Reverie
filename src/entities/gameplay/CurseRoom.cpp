#include "src/entities/gameplay/CurseRoom.hpp"

#include "src/entities/gameplay/Player.hpp"
#include "src/functions/Direction.hpp"
#include "src/functions/EnvironmentVendor.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

CurseRoom::CurseRoom( const glm::vec3& pos,
                      global::environment::Direction direction,
                      Player* player )
    :
    m_position ( pos ),
    m_direction( direction ),
    m_player   ( player ),
    m_triggered( false )
{
    const float xAutoLook = -17.0F;

    switch( m_direction )
    {
        case global::environment::NORTH:
        {
            m_autoMovePos = glm::vec3(
                    m_position + glm::vec3( 0.0F, 0.0F, 1.0F ) );
            m_autoLookAngle = glm::vec2( xAutoLook, 0.0F );
            break;
        }
        case global::environment::SOUTH:
        {
            m_autoMovePos = glm::vec3(
                    m_position + glm::vec3( 0.0F, 0.0F, -1.0F ) );
            m_autoLookAngle = glm::vec2( xAutoLook, 180.0F );
            break;
        }
        case global::environment::EAST:
        {
            m_autoMovePos = glm::vec3(
                    m_position + glm::vec3( -1.0F, 0.0F, 0.0F ) );
            m_autoLookAngle = glm::vec2( xAutoLook, 270.0F );
            break;
        }
        case global::environment::WEST:
        {
            m_autoMovePos = glm::vec3(
                    m_position + glm::vec3( 1.0F, 0.0F, 0.0F ) );
            m_autoLookAngle = glm::vec2( xAutoLook, 90.0F );
            break;
        }

    }
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CurseRoom::init()
{
    initComponents();
}

void CurseRoom::update()
{
    // check trigger
    if ( !m_triggered && m_trigger->getCollisionData().size() > 0 )
    {
        m_triggered = true;
        // Request that the player look and move
        m_player->autoMoveToPosition( m_autoMovePos );
        m_player->autoLookAtAngle( m_autoLookAngle );
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CurseRoom::initComponents()
{
    // base transform
    omi::Transform* baseT = new omi::Transform(
            "",
            m_position,
            glm::vec3( 0.0F, dir::toAngle( m_direction ), 0.0F ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( baseT );

    //----------------------------------WALLS-----------------------------------

    // floor
    omi::Mesh* floorMesh =
            omi::ResourceManager::getMesh( "curse_room_floor", "", baseT );
    floorMesh->getMaterial().specular = new omi::Specular(
            8.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_floor_spec" )
    );
    m_components.add( floorMesh );

    // ceiling
    omi::Mesh* ceilingMesh =
            omi::ResourceManager::getMesh( "curse_room_ceiling", "", baseT );
    ceilingMesh->getMaterial().specular = new omi::Specular(
            8.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_ceiling_spec" )
    );
    m_components.add( ceilingMesh );

    // back wall
    omi::Mesh* wallBackMesh =
            omi::ResourceManager::getMesh( "curse_room_wall", "", baseT );
    wallBackMesh->getMaterial().specular = new omi::Specular(
            8.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_wall_spec" )
    );
    m_components.add( wallBackMesh );

    // TODO: front wall

    // left wall
    omi::Transform* wallLeftT = new omi::Transform(
            "",
            baseT,
            glm::vec3(),
            glm::vec3( 0.0f, 90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( wallLeftT );
    omi::Mesh* wallLeftMesh =
            omi::ResourceManager::getMesh( "curse_room_wall", "", wallLeftT );
    wallLeftMesh->getMaterial().specular = new omi::Specular(
            8.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_wall_spec" )
    );
    m_components.add( wallLeftMesh );

    // right wall
    omi::Transform* wallRightT = new omi::Transform(
            "",
            baseT,
            glm::vec3(),
            glm::vec3( 0.0f, -90.0f, 0.0f ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( wallRightT );
    omi::Mesh* wallRightMesh =
            omi::ResourceManager::getMesh( "curse_room_wall", "", wallRightT );
    wallRightMesh->getMaterial().specular = new omi::Specular(
            8.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_wall_spec" )
    );
    m_components.add( wallRightMesh );


    //-------------------------WALL COLLISION DETECTORS-------------------------

    m_components.add( vendor::vendWallCollider(
            this, baseT, m_direction, global::environment::WEST
    ) );
    m_components.add( vendor::vendWallCollider(
            this, baseT, m_direction, global::environment::EAST
    ) );
    m_components.add( vendor::vendWallCollider(
            this, baseT, m_direction, global::environment::SOUTH
    ) );

    //----------------------------------LIGHTS----------------------------------

    omi::Transform* lowLightT = new omi::Transform(
            "",
            baseT,
            glm::vec3( 0.0f, 1.0f, 1.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( lowLightT );
    omi::PointLight* lowLight = new omi::PointLight(
            "",
            lowLightT,
            0.15F,
            glm::vec3( 1.0f, 0.8f, 0.8f ),
            0.0f,
            0.1f,
            0.02f
    );
    m_components.add( lowLight );

    omi::Transform* highLightT = new omi::Transform(
            "",
            baseT,
            glm::vec3( 0.0f, 2.2f, 0.0f ),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( highLightT );
    omi::PointLight* highLight = new omi::PointLight(
            "",
            highLightT,
            0.1F,
            glm::vec3( 0.7f, 0.7f, 1.0f ),
            0.0f,
            0.1f,
            0.02f
    );
    m_components.add( highLight );

    //---------------------------------TRIGGER----------------------------------

    m_trigger = new omi::CollisionDetector( "", "curse_room_trigger", this );
    m_trigger->addBounding( new omi::BoundingRect(
            glm::vec2( global::TILE_SIZE, global::TILE_SIZE ),
            baseT
    ) );
    m_components.add( m_trigger );

    //-------------------------------CURSE GIVER--------------------------------

    m_curseGiverBody = omi::ResourceManager::getKeyFrameMesh(
            "curse_giver_body", "", baseT );
    m_curseGiverBody->castShadow = true;
    m_curseGiverBody->receiveShadows = false;
    m_curseGiverBody->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 2.0f, 2.0f, 2.0f ),
            omi::ResourceManager::getTexture( "curse_giver_skin_spec" )
    );
    m_components.add( m_curseGiverBody );

    m_curseGiverPants =
            omi::ResourceManager::getMesh( "curse_giver_pants", "", baseT );
    m_curseGiverPants->castShadow = true;
    m_curseGiverPants->receiveShadows = false;
    m_components.add( m_curseGiverPants );

    //----------------------------------HOOKS-----------------------------------

    omi::KeyFrameMesh* hook0Mesh = omi::ResourceManager::getKeyFrameMesh(
            "curse_room_hook", "", baseT );
    hook0Mesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_hook_spec" )
    );
    hook0Mesh->setSpeed( 0.8F );
    m_components.add( hook0Mesh );

    omi::Transform* hook1T = new omi::Transform(
            "",
            baseT,
            glm::vec3( 0.75f, 0.0f, 0.75f ),
            glm::vec3( 0.0F, 180.0F, 0.0F ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( hook1T );
    omi::KeyFrameMesh* hook1Mesh = omi::ResourceManager::getKeyFrameMesh(
            "curse_room_hook", "", hook1T );
    hook1Mesh->setSpeed( 0.7F );
    hook1Mesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_hook_spec" )
    );
    m_components.add( hook1Mesh );

    omi::Transform* hook2T = new omi::Transform(
            "",
            baseT,
            glm::vec3( -0.75f, 0.0f, 0.75f ),
            glm::vec3( 0.0F, 90.0F, 0.0F ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( hook2T );
    omi::KeyFrameMesh* hook2Mesh = omi::ResourceManager::getKeyFrameMesh(
            "curse_room_hook", "", hook2T );
    hook2Mesh->setSpeed( 0.85F );
    hook2Mesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_hook_spec" )
    );
    m_components.add( hook2Mesh );

    omi::Transform* hook3T = new omi::Transform(
            "",
            baseT,
            glm::vec3( 0.75f, 0.0f, -0.75f ),
            glm::vec3( 0.0F, -90.0F, 0.0F ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( hook3T );
    omi::KeyFrameMesh* hook3Mesh = omi::ResourceManager::getKeyFrameMesh(
            "curse_room_hook", "", hook3T );
    hook3Mesh->setSpeed( 0.65F );
    hook3Mesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_hook_spec" )
    );
    m_components.add( hook3Mesh );

    omi::Transform* hook4T = new omi::Transform(
            "",
            baseT,
            glm::vec3( -0.75f, 0.0f, -0.75f ),
            glm::vec3( 0.0F, 0.0F, 0.0F ),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( hook4T );
    omi::KeyFrameMesh* hook4Mesh = omi::ResourceManager::getKeyFrameMesh(
            "curse_room_hook", "", hook4T );
    hook4Mesh->setSpeed( 0.75F );
    hook4Mesh->getMaterial().specular = new omi::Specular(
            256.0f,
            glm::vec3( 1.0f, 1.0f, 1.0f ),
            omi::ResourceManager::getTexture( "curse_room_hook_spec" )
    );
    m_components.add( hook4Mesh );

    //--------------------------------CURSE TEXT--------------------------------

    // curse 1 title
    omi::Transform* curse1TitleT = new omi::Transform(
            "",
            baseT,
            glm::vec3( 0.0F, 1.8F, 0.5F ),
            glm::vec3(),
            glm::vec3( 0.6F, 0.6F, 0.6F )
    );
    m_curse1Title = omi::ResourceManager::getText(
            "curse_text_title", "", curse1TitleT );
    // m_curse1Title->setString( m_str );
    m_curse1Title->setHorCentred ( true );
    m_curse1Title->setVertCentred( true );
    m_components.add( m_curse1Title );

    // curse 1 description
    omi::Transform* curse1DescT = new omi::Transform(
            "",
            curse1TitleT,
            glm::vec3( 0.0F, -0.075F, 0.0F ),
            glm::vec3(),
            glm::vec3( 1.0F, 1.0F, 1.0F )
    );
    m_curse1Description = omi::ResourceManager::getText(
            "curse_text_description", "", curse1DescT );
    // m_curse1Description->setString( m_str );
    m_curse1Description->setHorCentred ( true );
    m_curse1Description->setVertCentred( true );
    m_components.add( m_curse1Description );

    // curse 2 title
    omi::Transform* curse2TitleT = new omi::Transform(
            "",
            curse1TitleT,
            glm::vec3( 0.0F, -0.2F, 0.0F ),
            glm::vec3(),
            glm::vec3( 1.0F, 1.0F, 1.0F )
    );

    m_curse2Title = omi::ResourceManager::getText(
            "curse_text_title", "", curse2TitleT );
    m_curse2Title->setString( "Curse of Darkness" );
    m_curse2Title->setHorCentred ( true );
    m_curse2Title->setVertCentred( true );
    m_components.add( m_curse2Title );

    // curse 2 description
    omi::Transform* curse2DescT = new omi::Transform(
            "",
            curse2TitleT,
            glm::vec3( 0.0F, -0.075F, 0.0F ),
            glm::vec3(),
            glm::vec3( 1.0F, 1.0F, 1.0F )
    );
    m_curse2Description = omi::ResourceManager::getText(
            "curse_text_description", "", curse2DescT );
    m_curse2Description->setString( "May the light fail you" );
    m_curse2Description->setHorCentred ( true );
    m_curse2Description->setVertCentred( true );
    m_components.add( m_curse2Description );

    // curse 3 title
    omi::Transform* curse3TitleT = new omi::Transform(
            "",
            curse2TitleT,
            glm::vec3( 0.0F, -0.2F, 0.0F ),
            glm::vec3(),
            glm::vec3( 1.0F, 1.0F, 1.0F )
    );

    m_curse3Title = omi::ResourceManager::getText(
            "curse_text_title", "", curse3TitleT );
    m_curse3Title->setString( "Curse of the Hunted" );
    m_curse3Title->setHorCentred ( true );
    m_curse3Title->setVertCentred( true );
    m_components.add( m_curse3Title );

    // curse 3 description
    omi::Transform* curse3DescT = new omi::Transform(
            "",
            curse3TitleT,
            glm::vec3( 0.0F, -0.075F, 0.0F ),
            glm::vec3(),
            glm::vec3( 1.0F, 1.0F, 1.0F )
    );
    m_curse3Description = omi::ResourceManager::getText(
            "curse_text_description", "", curse3DescT );
    m_curse3Description->setString( "May you never rest" );
    m_curse3Description->setHorCentred ( true );
    m_curse3Description->setVertCentred( true );
    m_components.add( m_curse3Description );
}