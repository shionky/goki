
/*!
 *  @file       ui_manager.cpp
 *  @brief      UI管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "ui_manager.h"
#include "ui_component\game_score\game_score.h"
#include "ui_component\game_timer\game_timer.h"

const aqua::CVector2     CUIManager::m_ui_score_position = aqua::CVector2( 0.0f, 0.0f );
const aqua::CVector2     CUIManager::m_ui_timer_position = aqua::CVector2( 560.0f, 0.0f );

/*
 *  コンストラクタ
 */
CUIManager::
CUIManager( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "UIManager" )
{
}

/*
 *  初期化
 */
void
CUIManager::
Initialize( void )
{
    // スコアのUIを生成
    CGameScore* score = aqua::CreateGameObject<CGameScore>( this );

    score->Initialize( m_ui_score_position );

    // タイマーのUIを生成
    CGameTimer* timer = aqua::CreateGameObject<CGameTimer>( this );

    timer->Initialize( m_ui_timer_position );
}
