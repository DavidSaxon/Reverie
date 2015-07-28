#ifndef REVERIE_ENTITIES_GAMEPLAY_PLAYER_HPP_
#   define REVERIE_ENTITIES_GAMEPLAY_PLAYER_HPP_

#include "src/omicron/entity/Entity.hpp"

namespace player
{

// enumerators for move priorities
enum ZMove
{
    Z_NONE = 0,
    Z_FORWARD,
    Z_BACKWARD
};
enum XMove
{
    Y_NONE = 0,
    Y_LEFT,
    Y_RIGHT
};

// enumerators for music
enum Music
{
    INTRO = 0
};

} // namespace player

class Player : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Player();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    /** Return's the player's transform */
    omi::Transform* getTransform();

    /** Sets the current music */
    void setMusic( player::Music music );

    void playMusic();

    void pauseMusic();

    void setCamShake( float camShake );

    void setRunDisabled( bool state );

    void setFootStepsDisabled( bool state );

    void playHeartBeatSlow();

    void stopHeartBeatSlow();

    void autoMoveToPosition( const glm::vec3& position );

    void disableAutoMove();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the main transformation of the player
    omi::Transform* m_transform;
    // the transformation of the camera associated with the player
    omi::Transform* m_camT;

    // the player's collision checker
    omi::CollisionChecker* m_collisionChecker;

    // the current music being played
    player::Music m_music;
    // the music components
    omi::Music* m_currentMusic;
    omi::Music* m_introMusic;

    // move priorities
    player::ZMove m_zPriority;
    player::XMove m_yPriority;

    // walk animation variables
    float m_stepAnimation;

    // walk accelerations
    float m_upAccel;
    float m_downAccel;
    float m_leftAccel;
    float m_rightAccel;

    float m_stepSoundAni;

    // the id of the heartbeat sound
    unsigned m_heartBeatSlowId;

    // the camera shake amount
    float m_camShake;
    bool m_shakeUp;
    float m_shakeUpTimer;

    // if running is disabled
    bool m_runDisabled;
    // if foot step sounds are disabled
    bool m_footstepsDisabled;

    // whether the player has a position to move to automatically
    bool m_autoMove;
    glm::vec3 m_autoMovePos;
    float m_autoMoveAngle;

    // TODO: REMOVE ME
    // the right arm of the player which shows active curses
    omi::Mesh* m_rightArm;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Performs player looking (camera rotation with the mouse) */
    void look();

    /** Performs player movement (camera translation with keys) */
    void move();

    /** Initialise music components */
    void initMusic();
};

#endif
