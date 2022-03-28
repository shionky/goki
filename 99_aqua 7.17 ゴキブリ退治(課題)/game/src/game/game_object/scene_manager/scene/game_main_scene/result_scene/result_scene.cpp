
/*!
 *  @file       result_scene.cpp
 *  @brief      メニューシーン
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
 *  コンストラクタ
 */
CResultScene::
CResultScene( aqua::IGameObject* parent )
    : IScene( parent, "ResultScene" )
{
}

/*
 *  初期化
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
    m_ScoreLabel.text = "[ス　コ　ア]" + std::to_string( score ) + "\n[ハイスコア]" + std::to_string( hi_score );
    m_ScoreLabel.color = aqua::CColor::WHITE;
    m_ScoreLabel.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_ScoreLabel.GetTextWidth() / 2.0f;
    m_ScoreLabel.position.y = (float)aqua::GetWindowHeight() * 0.4f;

    CSoundManager* sound = (CSoundManager*)aqua::FindGameObject( "SoundManager" );

    if( sound ) sound->Play( SOUND_ID::FANFARE );
}

/*
 *  更新
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
 *  描画
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
 *  解放
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
