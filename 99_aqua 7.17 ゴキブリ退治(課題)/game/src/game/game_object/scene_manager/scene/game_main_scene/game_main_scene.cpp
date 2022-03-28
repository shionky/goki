
/*!
*  @file       game_main_scene.cpp
*  @brief      ゲームメインシーン
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
 *  コンストラクタ
 */
CGameMainScene::
CGameMainScene( aqua::IGameObject* parent )
    : IScene( parent, "GameMainScene" )
{
}

/*
 *  デストラクタ
 */
CGameMainScene::
~CGameMainScene( void )
{
}

/*
 *  初期化
 */
void
CGameMainScene::
Initialize( void )
{
    // ステージ生成
    aqua::CreateGameObject<CStage>( this );

    // ゴキブリマネージャー生成
    CGokiManager* gm = aqua::CreateGameObject<CGokiManager>( this );

    // 待機状態に設定
    gm->SetGameObjectState( aqua::GAME_OBJECT_STATE::WAIT );

    // エフェクトマネージャー生成
    aqua::CreateGameObject<CEffectManager>( this );

    // UIマネージャー生成
    CUIManager* ui = aqua::CreateGameObject<CUIManager>( this );

    // 待機状態に設定
    ui->SetGameObjectState( aqua::GAME_OBJECT_STATE::WAIT );

    // ゲームスタートメッセージ
    aqua::CreateGameObject<CStartMessage>( this );

    // 状態設定
    m_State = STATE_GAME_START;

    IGameObject::Initialize( );
}

/*
 *  更新
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
 *  ゲーム開始
 */
void
CGameMainScene::
GameStart( void )
{
    // スタートメッセージの表示が終わった
    if( !FindChild( "StartMessage" ) )
    {
        // ゴキブリマネージャー検索
        CGokiManager* gm = (CGokiManager*)FindChild("GokiManager");

        // アクティブ状態に設定
        if (gm) gm->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);

        // UIマネージャーを検索
        CUIManager* ui = (CUIManager*)FindChild("UIManager");

        // アクティブ状態に設定
        if (ui) ui->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);

        m_State = STATE_GAME_PLAY;
    }
}

/*
 *  ゲーム中
 */
void
CGameMainScene::
GamePlay( void )
{
    // 中クリックでメニューを開く
    if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::MIDDLE))
    {
        Push(SCENE_ID::MENU);

        CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

        if (sound) sound->Play( SOUND_ID::DECISION );
    }

    // ゲームタイマー取得
    CGameTimer* gt = (CGameTimer*)aqua::FindGameObject( "GameTimer" );

    // ゲーム時間終了
    if( gt && gt->Finished( ) )
    {
        // ゴキブリマネージャー検索
        CGokiManager* gm = (CGokiManager*)FindChild("GokiManager");

        // 待機状態に設定
        if (gm) gm->SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

        // ゲームフィニッシュメッセージ生成・初期化
        aqua::CreateGameObject<CFinishMessage>(this)->Initialize( );

        m_State = STATE_GAME_FINISH;
    }
}

/*
 *  ゲーム終了
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
 *  ゲーム終了
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
            // 今回のスコアを取得
            int score = gs->GetScore();

            // 現在のハイスコア取得
            int hi_score = dm->GetSaveData()->hi_score;

            // ハイスコアを更新
            if (score > hi_score)
            {
                dm->GetSaveData()->hi_score = score;

                // セーブする
                dm->Save();
            }
        }
    }

    // リザルトシーンをプッシュする
    Push(SCENE_ID::RESULT);
}
