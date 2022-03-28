
/*!
*  @file       game_main_scene.cpp
*  @brief      �Q�[�����C���V�[��
*  @author     Kazuya Maruyama
*  @date       2021/02/13
*  @version    1.0
*
*  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
*/

#include "game_main_scene.h"
#include "..\..\..\stage\stage.h"
#include "..\..\..\goki_manager\goki_manager.h"
#include "..\..\..\effect_manager\effect_manager.h"
#include "..\..\..\data_manager\data_manager.h"
#include "..\..\..\sound_manager\sound_manager.h"
#include "..\..\..\ui_manager\ui_manager.h"
#include "..\..\..\ui_manager\ui_component\game_timer\game_timer.h"
#include "..\..\..\ui_manager\ui_component\game_score\game_score.h"
#include "message\start_message\start_message.h"
#include "message\finish_message\finish_message.h"

/*
 *  �R���X�g���N�^
 */
CGameMainScene::
CGameMainScene( aqua::IGameObject* parent )
    : IScene( parent, "GameMainScene" )
{
}

/*
 *  �f�X�g���N�^
 */
CGameMainScene::
~CGameMainScene( void )
{
}

/*
 *  ������
 */
void
CGameMainScene::
Initialize( void )
{
    // �X�e�[�W����
    aqua::CreateGameObject<CStage>( this );

    // �S�L�u���}�l�[�W���[����
    CGokiManager* gm = aqua::CreateGameObject<CGokiManager>( this );

    // �ҋ@��Ԃɐݒ�
    gm->SetGameObjectState( aqua::GAME_OBJECT_STATE::WAIT );

    // �G�t�F�N�g�}�l�[�W���[����
    aqua::CreateGameObject<CEffectManager>( this );

    // UI�}�l�[�W���[����
    CUIManager* ui = aqua::CreateGameObject<CUIManager>( this );

    // �ҋ@��Ԃɐݒ�
    ui->SetGameObjectState( aqua::GAME_OBJECT_STATE::WAIT );

    // �Q�[���X�^�[�g���b�Z�[�W
    aqua::CreateGameObject<CStartMessage>( this );

    // ��Ԑݒ�
    m_State = STATE_GAME_START;

    IGameObject::Initialize( );
}

/*
 *  �X�V
 */
void
CGameMainScene::
Update( void )
{
    switch( m_State )
    {
    case STATE_GAME_START:  GameStart( );   break;
    case STATE_GAME_PLAY:   GamePlay( );    break;
    case STATE_GAME_FINISH: GameFinish( );  break;
    case STATE_GAME_SAVE:   GameSave( );    break;
    }

    IGameObject::Update( );
}

/*
 *  �Q�[���J�n
 */
void
CGameMainScene::
GameStart( void )
{
    // �X�^�[�g���b�Z�[�W�̕\�����I�����
    if( !FindChild( "StartMessage" ) )
    {
        // �S�L�u���}�l�[�W���[����
        CGokiManager* gm = (CGokiManager*)FindChild("GokiManager");

        // �A�N�e�B�u��Ԃɐݒ�
        if (gm) gm->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);

        // UI�}�l�[�W���[������
        CUIManager* ui = (CUIManager*)FindChild("UIManager");

        // �A�N�e�B�u��Ԃɐݒ�
        if (ui) ui->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);

        m_State = STATE_GAME_PLAY;
    }
}

/*
 *  �Q�[����
 */
void
CGameMainScene::
GamePlay( void )
{
    // ���N���b�N�Ń��j���[���J��
    if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::MIDDLE))
    {
        Push(SCENE_ID::MENU);

        CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

        if (sound) sound->Play( SOUND_ID::DECISION );
    }

    // �Q�[���^�C�}�[�擾
    CGameTimer* gt = (CGameTimer*)aqua::FindGameObject( "GameTimer" );

    // �Q�[�����ԏI��
    if( gt && gt->Finished( ) )
    {
        // �S�L�u���}�l�[�W���[����
        CGokiManager* gm = (CGokiManager*)FindChild("GokiManager");

        // �ҋ@��Ԃɐݒ�
        if (gm) gm->SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

        // �Q�[���t�B�j�b�V�����b�Z�[�W�����E������
        aqua::CreateGameObject<CFinishMessage>(this)->Initialize( );

        m_State = STATE_GAME_FINISH;
    }
}

/*
 *  �Q�[���I��
 */
void
CGameMainScene::
GameFinish( void )
{
    if (!FindChild("FinishMessage"))
    {
        m_State = STATE_GAME_SAVE;
    }
}

/*
 *  �Q�[���I��
 */
void
CGameMainScene::
GameSave(void)
{
    CGameScore* gs = (CGameScore*)aqua::FindGameObject("GameScore");

    if (gs)
    {
        CDataManager* dm = (CDataManager*)aqua::FindGameObject("DataManager");

        if (dm)
        {
            // ����̃X�R�A���擾
            int score = gs->GetScore();

            // ���݂̃n�C�X�R�A�擾
            int hi_score = dm->GetSaveData()->hi_score;

            // �n�C�X�R�A���X�V
            if (score > hi_score)
            {
                dm->GetSaveData()->hi_score = score;

                // �Z�[�u����
                dm->Save();
            }
        }
    }

    // ���U���g�V�[�����v�b�V������
    Push(SCENE_ID::RESULT);
}
