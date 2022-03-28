
/*!
 *  @file       game.cpp
 *  @brief      ゲーム管理
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
 *  コンストラクタ
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  初期化
 */
void
CGame::
Initialize( void )
{
    // データマネジャー生成
    CDataManager* dm = aqua::CreateGameObject<CDataManager>( this );

    // ロードする
    dm->Load( );

    // サウンドマネージャー生成
    CSoundManager* sound = aqua::CreateGameObject<CSoundManager>( this );

    // カメラマネージャー生成
    aqua::CreateGameObject<CCameraManager>( this );

    // シーンマネージャー生成
    aqua::CreateGameObject<CSceneManager>( this );

    // 子クラスの初期化
    IGameObject::Initialize( );

    // BGM再生
    sound->Play( SOUND_ID::BGM );

    // マウスカーソルの表示
    SetMouseDispFlag(TRUE);
}

/*
 *  更新
 */
void
CGame::
Update( void )
{
    // 子クラスの更新
    IGameObject::Update( );
}

/*
 *  描画
 */
void
CGame::
Draw( void )
{
    // 画面のクリア
    aqua::Clear( m_clear_color );

    // 子クラスの描画
    IGameObject::Draw( );
}

/*
 *  解放
 */
void
CGame::
Finalize( void )
{
    CDataManager* dm = (CDataManager*)FindChild( "DataManager" );

    // セーブする
    if( dm ) dm->Save( );

    // 子クラスの解放
    IGameObject::Finalize( );
}
