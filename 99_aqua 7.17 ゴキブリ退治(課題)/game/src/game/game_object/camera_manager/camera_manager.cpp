
/*!
 *  @file       camera_manager.cpp
 *  @brief      カメラ管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "camera_manager.h"

const float CCameraManager::m_shake_time = 0.25f;

/*
 *  コンストラクタ
 */
CCameraManager::
CCameraManager( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "CameraManager" )
    , m_ShakeFlag( false )
{
}

/*
 *  初期化
 */
void
CCameraManager::
Initialize( void )
{
    m_Position = aqua::CVector2::ZERO;

    m_ShakeTimer.Setup( m_shake_time );

    m_ShakeFlag = false;
}

/*
 *  更新
 */
void
CCameraManager::
Update( void )
{
    if( !m_ShakeFlag ) return;

    m_Position.x = (float)aqua::Rand( 10, 1 ) * ( aqua::Rand( 2 ) ? 1.0f : -1.0f );
    m_Position.y = (float)aqua::Rand( 10, 1 ) * ( aqua::Rand( 2 ) ? 1.0f : -1.0f );

    m_ShakeTimer.Update( );

    if( m_ShakeTimer.Finished( ) )
    {
        m_ShakeTimer.Reset( );

        m_Position = aqua::CVector2::ZERO;

        m_ShakeFlag = false;
    }
}

/*
 *  振動開始
 */
void
CCameraManager::
Shake( void )
{
    m_ShakeFlag = true;
}
