
/*!
 *  @file       game_score.h
 *  @brief      スコア
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\ui_component.h"

/*!
 *  @class      CGameScore
 *
 *  @brief      スコアクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGameScore
    : public IUIComponent
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CGameScore( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CGameScore( void ) = default;

    /*!
     *  @brief      初期化
     *
     *  @param[in]  position    位置
     */
    void    Initialize( const aqua::CVector2& position ) override;

   /*!
    *  @brief      描画
    */
    void    Draw( void ) override;

   /*!
    *  @brief      解放
    */
    void    Finalize( void ) override;

   /*!
    *  @brief      スコアの加算
    *
    *   @param[in]  score   加算する値
    */
    void    Add( int socre );

   /*!
    *  @brief      スコアのクリア
    */
    void    Clear( void );

   /*!
    *  @brief       スコアの取得
    *
    *   @return     現在のスコア
    */
    int     GetScore( void ) const;

private:
    static const int    m_min_score;    //! スコアの最小値
    static const int    m_max_score;    //! スコアの最大値
    int                 m_Score;        //! スコア
    aqua::CLabel        m_HiScoreLabel; //! ハイスコア描画用ラベル
    aqua::CLabel        m_ScoreLabel;   //! スコア描画用ラベル
};
