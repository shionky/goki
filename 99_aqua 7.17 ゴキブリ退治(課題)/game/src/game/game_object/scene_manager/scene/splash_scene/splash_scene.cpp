
/*!
 *  @file       splash_scene.cpp
 *  @brief      スプラッシュシーン
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "splash_scene.h"

const float CSplashScene::m_wait_time = 3.0f;

/*
 *  コンストラクタ
 */
CSplashScene::
CSplashScene( aqua::IGameObject* parent )
    : IScene( parent, "SplashScene" )
{
}

/*
 *  初期化
 */
void
CSplashScene::
Initialize( void )
{
    // タイマー設定
    m_WaitTimer.Setup( m_wait_time );

    // ラベル生成
    m_MaouLabel.Create( 36, 1 );

    m_MaouLabel.text        = "[サウンド]魔王魂";
    m_MaouLabel.color       = aqua::CColor::WHITE;
    m_MaouLabel.position.x  = (float)aqua::GetWindowWidth( ) / 2.0f - (float)m_MaouLabel.GetTextWidth( ) / 2.0f;
    m_MaouLabel.position.y  = (float)aqua::GetWindowHeight( ) * 0.4f;

    // ラベル生成
    m_NoahLabel.Create( 36, 1 );

    m_NoahLabel.text        = "[イラスト]のあ";
    m_NoahLabel.color       = aqua::CColor::WHITE;
    m_NoahLabel.position.x  = (float)aqua::GetWindowWidth( ) / 2.0f - (float)m_NoahLabel.GetTextWidth( ) / 2.0f;
    m_NoahLabel.position.y  = (float)aqua::GetWindowHeight( ) * 0.5f;

    // スプライト生成
    m_BackgroundSprite.Create( "data\\floor.png" );
}

/*
 *  更新
 */
void
CSplashScene::
Update( void )
{
    // タイマー更新
    m_WaitTimer.Update( );

    // 設定した時間になったら
    if( m_WaitTimer.Finished( ) )
    {
        // タイトルシーンに変更
        Change( SCENE_ID::TITLE );
    }
}

/*
 *  描画
 */
void
CSplashScene::
Draw( void )
{
    // 背景描画
    m_BackgroundSprite.Draw( );

    // ラベルの描画
    m_MaouLabel.Draw( );
    m_NoahLabel.Draw( );
}

/*
 *  解放
 */
void
CSplashScene::
Finalize( void )
{
    // スプライト解放
    m_BackgroundSprite.Delete( );

    // ラベルの解放
    m_MaouLabel.Delete( );
    m_NoahLabel.Delete( );
}
