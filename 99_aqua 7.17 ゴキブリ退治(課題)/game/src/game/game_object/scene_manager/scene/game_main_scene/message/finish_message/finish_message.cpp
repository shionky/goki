
/*!
 *  @file       finish_message.cpp
 *  @brief      フィニッシュメッセージ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "finish_message.h"
#include "..\..\..\..\..\sound_manager\sound_manager.h"

const float CFinishMessage::m_easing_limit  = 1.0f;
const float CFinishMessage::m_view_limit    = 2.0f;
const float CFinishMessage::m_min_scale     = 0.0f;
const float CFinishMessage::m_max_scale     = 2.0f;

/*
 *  コンストラクタ
 */
CFinishMessage::
CFinishMessage( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "FinishMessage" )
{
}

/*
 *  初期化
 */
void
CFinishMessage::
Initialize( void )
{
    m_FinishSprite.Create("data\\finish.png");
    m_FinishSprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_FinishSprite.GetTextureWidth() / 2.0f;
    m_FinishSprite.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_FinishSprite.GetTextureHeight() / 2.0f;
    m_FinishSprite.anchor.x = (float)m_FinishSprite.GetTextureWidth() / 2.0f;
    m_FinishSprite.anchor.y = (float)m_FinishSprite.GetTextureHeight() / 2.0f;
    m_FinishSprite.scale = aqua::CVector2::ZERO;

    m_ElapsedTime = 0.0f;

    CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

    if( sound ) sound->Play( SOUND_ID::FINISH );
}

/*
 *  更新
 */
void
CFinishMessage::
Update( void )
{
    // 時間を計測
    m_ElapsedTime += aqua::GetDeltaTime();

    if (m_ElapsedTime > m_view_limit)
        DeleteObject();

    float time = m_ElapsedTime > m_easing_limit ? m_easing_limit : m_ElapsedTime;

    float scale = abs(aqua::easing::OutBack(time, m_easing_limit, m_min_scale, m_max_scale));

    m_FinishSprite.scale = aqua::CVector2(scale, scale);
}

/*
 *  描画
 */
void
CFinishMessage::
Draw( void )
{
    m_FinishSprite.Draw();
}

/*
 *  解放
 */
void
CFinishMessage::
Finalize( void )
{
    m_FinishSprite.Delete();
}
