
/*!
 *  @file       game_timer.cpp
 *  @brief      �Q�[���^�C�}�[
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
 *  �R���X�g���N�^
 */
CGameTimer::
CGameTimer( aqua::IGameObject* parent )
    : IUIComponent( parent, "GameTimer" )
{
}

/*
 *  ������
 */
void
CGameTimer::
Initialize( const aqua::CVector2& position )
{
    IUIComponent::Initialize( position );

    // ���x������
    m_TimerLabel.Create( 36, 2 );

    m_SecondTimer.Setup( m_one_second );

    m_TimeLimit = m_time_limit;
}
/*
 *  �X�V
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
 *  �`��
 */
void
CGameTimer::
Draw( void )
{
    m_TimerLabel.text = "�c��" + std::to_string( m_TimeLimit ) + "�b";

    m_TimerLabel.position = m_Position;

    m_TimerLabel.Draw( );
}

/*
 *  ���
 */
void
CGameTimer::
Finalize( void )
{
    m_TimerLabel.Delete( );
}

/*
 *  �I�����m
 */
bool
CGameTimer::
Finished( void )
{
    return ( m_TimeLimit <= 0 );
}
