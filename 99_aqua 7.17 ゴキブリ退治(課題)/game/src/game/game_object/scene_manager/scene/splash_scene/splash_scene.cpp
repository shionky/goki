
/*!
 *  @file       splash_scene.cpp
 *  @brief      �X�v���b�V���V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "splash_scene.h"

const float CSplashScene::m_wait_time = 3.0f;

/*
 *  �R���X�g���N�^
 */
CSplashScene::
CSplashScene( aqua::IGameObject* parent )
    : IScene( parent, "SplashScene" )
{
}

/*
 *  ������
 */
void
CSplashScene::
Initialize( void )
{
    // �^�C�}�[�ݒ�
    m_WaitTimer.Setup( m_wait_time );

    // ���x������
    m_MaouLabel.Create( 36, 1 );

    m_MaouLabel.text        = "[�T�E���h]������";
    m_MaouLabel.color       = aqua::CColor::WHITE;
    m_MaouLabel.position.x  = (float)aqua::GetWindowWidth( ) / 2.0f - (float)m_MaouLabel.GetTextWidth( ) / 2.0f;
    m_MaouLabel.position.y  = (float)aqua::GetWindowHeight( ) * 0.4f;

    // ���x������
    m_NoahLabel.Create( 36, 1 );

    m_NoahLabel.text        = "[�C���X�g]�̂�";
    m_NoahLabel.color       = aqua::CColor::WHITE;
    m_NoahLabel.position.x  = (float)aqua::GetWindowWidth( ) / 2.0f - (float)m_NoahLabel.GetTextWidth( ) / 2.0f;
    m_NoahLabel.position.y  = (float)aqua::GetWindowHeight( ) * 0.5f;

    // �X�v���C�g����
    m_BackgroundSprite.Create( "data\\floor.png" );
}

/*
 *  �X�V
 */
void
CSplashScene::
Update( void )
{
    // �^�C�}�[�X�V
    m_WaitTimer.Update( );

    // �ݒ肵�����ԂɂȂ�����
    if( m_WaitTimer.Finished( ) )
    {
        // �^�C�g���V�[���ɕύX
        Change( SCENE_ID::TITLE );
    }
}

/*
 *  �`��
 */
void
CSplashScene::
Draw( void )
{
    // �w�i�`��
    m_BackgroundSprite.Draw( );

    // ���x���̕`��
    m_MaouLabel.Draw( );
    m_NoahLabel.Draw( );
}

/*
 *  ���
 */
void
CSplashScene::
Finalize( void )
{
    // �X�v���C�g���
    m_BackgroundSprite.Delete( );

    // ���x���̉��
    m_MaouLabel.Delete( );
    m_NoahLabel.Delete( );
}
