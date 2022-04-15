
/*!
 *  @file       game_score.cpp
 *  @brief      スコア
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "game_score.h"
#include "..\..\..\data_manager\data_manager.h"

const int   CGameScore::m_min_score = 0;
const int   CGameScore::m_max_score = 999;

/*
 *  コンストラクタ
 */
CGameScore::
CGameScore( aqua::IGameObject* parent )
    : IUIComponent( parent, "GameScore" )
    , m_Score( 0 )
{
}

/*
 *  初期化
 */
void
CGameScore::
Initialize( const aqua::CVector2& position )
{
    IUIComponent::Initialize( position );

    // ラベル生成
    m_HiScoreLabel.Create( 36, 2 );
    m_ScoreLabel.Create( 36, 2 );
}

/*
 *  描画
 */
void
CGameScore::
Draw( void )
{
    CDataManager* dm = (CDataManager*)aqua::FindGameObject( "DataManager" );

    int hi_score = 0;

    if( dm ) hi_score = dm->GetSaveData( )->hi_score;

    // ハイスコア表示
    // 現在のスコアがハイスコアを上回った
    if( m_Score > hi_score )
        m_HiScoreLabel.text = "ハイスコア：" + std::to_string( m_Score );
    else
        m_HiScoreLabel.text = "ハイスコア：" + std::to_string( hi_score );

    m_HiScoreLabel.position = m_Position;

    m_HiScoreLabel.Draw( );

    // スコア表示
    m_ScoreLabel.text = "ス　コ　ア：" + std::to_string( m_Score );

    m_ScoreLabel.position = m_Position + aqua::CVector2( 0.0f, (float)m_HiScoreLabel.GetFontHeight( ) );

    m_ScoreLabel.Draw( );
}

/*
 *  解放
 */
void
CGameScore::
Finalize( void )
{
    m_HiScoreLabel.Delete( );
    m_ScoreLabel.Delete( );
}

/*
 *  スコアの加算
 */
void
CGameScore::
Add( int score )
{
    m_Score += score;

    // 上下限チェック
    if( m_Score < m_min_score )
        m_Score = m_min_score;
    else if( m_Score > m_max_score )
        m_Score = m_max_score;
}




/*
 *  スコアのクリア
 */
void
CGameScore::
Clear( void )
{
    m_Score = 0;
}

/*
 *  スコアの取得
 */
int
CGameScore::
GetScore( void ) const
{
    return m_Score;
}
