
/*!
 *  @file       result_scene.cpp
 *  @brief      ���j���[�V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "result_scene.h"
#include "..\..\..\..\data_manager\data_manager.h"
#include "..\..\..\..\sound_manager\sound_manager.h"
#include "..\..\..\..\ui_manager\ui_component\game_score\game_score.h"

/*
 *  �R���X�g���N�^
 */
CResultScene::
CResultScene( aqua::IGameObject* parent )
    : IScene( parent, "ResultScene" )
{
}

/*
 *  ������
 */
void
CResultScene::
Initialize( void )
{
    m_BackgroundSprite.Create( "data\\white.png" );
    m_BackgroundSprite.color = 0x40000000;

    m_ResultSprite.Create("data\\result.png");
    m_ResultSprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_ResultSprite.GetTextureWidth() / 2.0f;
    m_ResultSprite.position.y = (float)aqua::GetWindowHeight() * 0.1f;

    m_MessageSprite.Create("data\\message.png");
    m_MessageSprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_MessageSprite.GetTextureWidth() / 2.0f;
    m_MessageSprite.position.y = (float)aqua::GetWindowHeight() * 0.7f;

    int score = 0;
    int hi_score = 0;

    CGameScore* gs = (CGameScore*)aqua::FindGameObject("GameScore");

    if( gs ) score = gs->GetScore();

    CDataManager* dm = (CDataManager*)aqua::FindGameObject("DataManager");

    if( dm ) hi_score = dm->GetSaveData()->hi_score;

    m_ScoreLabel.Create(84, 4);
    m_ScoreLabel.text = "[�X�@�R�@�A]" + std::to_string( score ) + "\n[�n�C�X�R�A]" + std::to_string( hi_score );
    m_ScoreLabel.color = aqua::CColor::WHITE;
    m_ScoreLabel.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_ScoreLabel.GetTextWidth() / 2.0f;
    m_ScoreLabel.position.y = (float)aqua::GetWindowHeight() * 0.4f;

    CSoundManager* sound = (CSoundManager*)aqua::FindGameObject( "SoundManager" );

    if( sound ) sound->Play( SOUND_ID::FANFARE );
}

/*
 *  �X�V
 */
void
CResultScene::
Update( void )
{
    if( aqua::mouse::Trigger( aqua::mouse::BUTTON_ID::LEFT ) )
    {
        Change( SCENE_ID::TITLE );

        CSoundManager* sound = (CSoundManager*)aqua::FindGameObject( "SoundManager" );

        if( sound ) sound->Play( SOUND_ID::DECISION );
    }
}

/*
 *  �`��
 */
void
CResultScene::
Draw( void )
{
    m_BackgroundSprite.Draw( );
    m_ResultSprite.Draw();
    m_MessageSprite.Draw();
    m_ScoreLabel.Draw();
}

/*
 *  ���
 */
void
CResultScene::
Finalize( void )
{
    m_BackgroundSprite.Delete( );
    m_ResultSprite.Delete();
    m_MessageSprite.Delete();
    m_ScoreLabel.Delete();
}
