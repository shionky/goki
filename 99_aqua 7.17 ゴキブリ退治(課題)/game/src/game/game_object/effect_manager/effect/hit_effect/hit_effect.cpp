
/*!
 *  @file       hit_effect.cpp
 *  @brief      �q�b�g�G�t�F�N�g
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "hit_effect.h"
#include "..\..\..\camera_manager\camera_manager.h"

const int    CHitEffect::m_width        = 128;
const int    CHitEffect::m_height       = 128;
const float  CHitEffect::m_alive_time   = 0.5f;

/*
 *  �R���X�g���N�^
 */
CHitEffect::
CHitEffect( aqua::IGameObject* parent )
    : IEffect( parent, "HitEffect" )
{
}

/*
 *  ������
 */
void
CHitEffect::
Initialize( const aqua::CVector2& position )
{
 //   m_Sprite.Create( "data\\hit_effect.png" );
 
    // �G�t�F�N�g����
    m_Effect.Create("data/effect/gokihit.efkefc");

    m_Sprite.anchor.x = (float)m_width  / 2.0f;
    m_Sprite.anchor.y = (float)m_height / 2.0f;
    m_Sprite.scale    = aqua::CVector2::ZERO;

    m_Position = position - m_Sprite.anchor;

    m_AliveTimer.Setup( m_alive_time );

    m_ScaleTime = 0.0f;

}

/*
 *  �X�V
 */
void
CHitEffect::
Update( void )
{
    m_AliveTimer.Update( );

    if( m_AliveTimer.Finished( ) )
        DeleteObject();

    m_ScaleTime += aqua::PI * 2.0f * aqua::GetDeltaTime( );

    m_Sprite.scale.x = m_Sprite.scale.y = abs( sin( m_ScaleTime ) );

    CCameraManager* camera = (CCameraManager*)aqua::FindGameObject( "CameraManager" );

    m_Sprite.position = m_Position - camera->GetPosition( );

    // �G�t�F�N�g�X�V
    m_Effect.Update();
}

/*
 *  �`��
 */
void
CHitEffect::
Draw( void )
{
    // �G�t�F�N�g�`��
    m_Effect.Draw();

   // m_Sprite.Draw();

}

/*
 *  ���
 */
void
CHitEffect::
Finalize( void )
{
    m_Effect.Delete();

    m_Sprite.Delete();
}
