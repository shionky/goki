
/*!
 *  @file       game.cpp
 *  @brief      �Q�[���Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "game.h"
#include "game_object\game_object.h"

const unsigned int CGame::m_clear_color = 0xff000000;

/*
 *  �R���X�g���N�^
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  ������
 */
void
CGame::
Initialize( void )
{
    // �f�[�^�}�l�W���[����
    CDataManager* dm = aqua::CreateGameObject<CDataManager>( this );

    // ���[�h����
    dm->Load( );

    // �T�E���h�}�l�[�W���[����
    CSoundManager* sound = aqua::CreateGameObject<CSoundManager>( this );

    // �J�����}�l�[�W���[����
    aqua::CreateGameObject<CCameraManager>( this );

    // �V�[���}�l�[�W���[����
    aqua::CreateGameObject<CSceneManager>( this );

    // �q�N���X�̏�����
    IGameObject::Initialize( );

    // BGM�Đ�
    sound->Play( SOUND_ID::BGM );

    // �}�E�X�J�[�\���̕\��
    SetMouseDispFlag(TRUE);
}

/*
 *  �X�V
 */
void
CGame::
Update( void )
{
    // �q�N���X�̍X�V
    IGameObject::Update( );
}

/*
 *  �`��
 */
void
CGame::
Draw( void )
{
    // ��ʂ̃N���A
    aqua::Clear( m_clear_color );

    // �q�N���X�̕`��
    IGameObject::Draw( );
}

/*
 *  ���
 */
void
CGame::
Finalize( void )
{
    CDataManager* dm = (CDataManager*)FindChild( "DataManager" );

    // �Z�[�u����
    if( dm ) dm->Save( );

    // �q�N���X�̉��
    IGameObject::Finalize( );
}
