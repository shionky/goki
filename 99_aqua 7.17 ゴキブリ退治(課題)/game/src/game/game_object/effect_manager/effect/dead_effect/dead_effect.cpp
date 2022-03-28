
/*!
 *  @file       dead_effect.cpp
 *  @brief      デッドエフェクト
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "dead_effect.h"
#include "..\..\..\camera_manager\camera_manager.h"

const int   CDeadEffect::m_width            = 128;
const int   CDeadEffect::m_height           = 128;
const float CDeadEffect::m_speed            = 400.0f;
const int   CDeadEffect::m_min_direction    = 225;
const int   CDeadEffect::m_max_direction    = 315;

/*
 *  コンストラクタ
 */
CDeadEffect::
CDeadEffect( aqua::IGameObject* parent )
    : IEffect( parent, "DeadEffect" )
{
}

/*
 *  初期化
 */
void
CDeadEffect::
Initialize( const aqua::CVector2& position )
{
    m_AnimationSprite.Create( "data\\dead_effect.ass" );

    m_AnimationSprite.anchor.x = (float)m_width  / 2.0f;
    m_AnimationSprite.anchor.y = (float)m_height / 2.0f;
    m_AnimationSprite.color.alpha = aqua::CColor::MAX_COLOR / 2;

    m_Position = position - m_AnimationSprite.anchor;

    float dir = aqua::DegToRad( (float)aqua::Rand( m_max_direction, m_min_direction ) );

    m_Velocity.x = cos( dir ) * m_speed;
    m_Velocity.y = sin( dir ) * m_speed;

    m_AnimationSprite.rotation = dir + aqua::DegToRad( 90.0f );
}

/*
 *  更新
 */
void
CDeadEffect::
Update( void )
{
    m_AnimationSprite.Update( );

    m_Position += m_Velocity * aqua::GetDeltaTime( );

    CCameraManager* camera = (CCameraManager*)aqua::FindGameObject( "CameraManager" );

    m_AnimationSprite.position = m_Position - camera->GetPosition( );

    if( m_AnimationSprite.position.y < -m_height )
        DeleteObject( );
}

/*
 *  描画
 */
void
CDeadEffect::
Draw( void )
{
    m_AnimationSprite.Draw( );
}

/*
 *  解放
 */
void
CDeadEffect::
Finalize( void )
{
    m_AnimationSprite.Delete( );
}
