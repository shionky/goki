
/*!
 *  @file       start_message.cpp
 *  @brief      スタートメッセージ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "start_message.h"
#include "..\..\..\..\..\sound_manager\sound_manager.h"

const float CStartMessage::m_easing_limit   = 0.5f;
const float CStartMessage::m_view_limit     = 1.0f;
const float CStartMessage::m_min_scale      = 0.0f;
const float CStartMessage::m_max_scale      = 2.0f;

/*
 *  コンストラクタ
 */
CStartMessage::
CStartMessage( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "StartMessage" )
    , m_ElapsedTime( 0.0f )
{
}

/*
 *  初期化
 */
void
CStartMessage::
Initialize( void )
{
    m_StartSprite.Create( "data\\start.png" );
    m_StartSprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_StartSprite.GetTextureWidth() / 2.0f;
    m_StartSprite.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_StartSprite.GetTextureHeight() / 2.0f;
    m_StartSprite.anchor.x   = (float)m_StartSprite.GetTextureWidth( ) / 2.0f;
    m_StartSprite.anchor.y   = (float)m_StartSprite.GetTextureHeight( ) / 2.0f;
    m_StartSprite.scale      = aqua::CVector2::ZERO;

    m_ElapsedTime = 0.0f;
}

/*
 *  更新
 */
void
CStartMessage::
Update( void )
{
    // 時間を計測
    m_ElapsedTime += aqua::GetDeltaTime();

    if (m_ElapsedTime > m_view_limit)
    {
        DeleteObject();

        CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

        if( sound ) sound->Play( SOUND_ID::START );
    }

    float time = m_ElapsedTime > m_easing_limit ? m_easing_limit : m_ElapsedTime;

    float scale = abs( aqua::easing::OutBack(time, m_easing_limit, m_min_scale, m_max_scale) );

    m_StartSprite.scale = aqua::CVector2(scale, scale);
}

/*
 *  描画
 */
void
CStartMessage::
Draw( void )
{
    m_StartSprite.Draw();
}

/*
 *  解放
 */
void
CStartMessage::
Finalize( void )
{
    m_StartSprite.Delete();
}
