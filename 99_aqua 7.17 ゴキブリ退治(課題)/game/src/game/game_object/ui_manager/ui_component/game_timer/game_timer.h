
/*!
 *  @file       game_timer.h
 *  @brief      ゲームタイマー
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
 *  @class      CGameTimer
 *
 *  @brief      ゲームタイマークラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGameTimer
    : public IUIComponent
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CGameTimer( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CGameTimer( void ) = default;

    /*!
     *  @brief      初期化
     *
     *  @param[in]  position    位置
     */
    void    Initialize( const aqua::CVector2& position ) override;

   /*!
    *  @brief      更新
    */
    void    Update( void ) override;

    /*!
    *  @brief      描画
    */
    void    Draw( void ) override;

   /*!
    *  @brief      解放
    */
    void    Finalize( void ) override;

    /*!
     *  @brief      終了検知
     *
     *  @retval     true    ゲーム終了
     *  @retval     false   ゲーム中
     */
    bool    Finished( void );

private:
    static const float  m_one_second;   //! 1秒
    static const int    m_time_limit;   //! 制限時間
    aqua::CLabel        m_TimerLabel;   //! タイマー描画用ラベル
    aqua::CTimer        m_SecondTimer;  //! 1秒タイマー
    int                 m_TimeLimit;    //! 制限時間
};
