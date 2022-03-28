
/*!
 *  @file       game_timer.cpp
 *  @brief      ゲームタイマー
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "game_timer.h"

const float CGameTimer::m_one_second = 1.0f;
const int   CGameTimer::m_time_limit = 60;

/*
 *  コンストラクタ
 */
CGameTimer::
CGameTimer( aqua::IGameObject* parent )
    : IUIComponent( parent, "GameTimer" )
{
}

/*
 *  初期化
 */
void
CGameTimer::
Initialize( const aqua::CVector2& position )
{
    IUIComponent::Initialize( position );

    // ラベル生成
    m_TimerLabel.Create( 36, 2 );

    m_SecondTimer.Setup( m_one_second );

    m_TimeLimit = m_time_limit;
}
/*
 *  更新
 */
void
CGameTimer::
Update( void )
{
    if( Finished( ) )
        return;

    m_SecondTimer.Update( );

    if( m_SecondTimer.Finished( ) )
    {
        m_SecondTimer.Reset( );

        --m_TimeLimit;
    }
}

/*
 *  描画
 */
void
CGameTimer::
Draw( void )
{
    m_TimerLabel.text = "残り" + std::to_string( m_TimeLimit ) + "秒";

    m_TimerLabel.position = m_Position;

    m_TimerLabel.Draw( );
}

/*
 *  解放
 */
void
CGameTimer::
Finalize( void )
{
    m_TimerLabel.Delete( );
}

/*
 *  終了検知
 */
bool
CGameTimer::
Finished( void )
{
    return ( m_TimeLimit <= 0 );
}
