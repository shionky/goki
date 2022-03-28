
/*!
 *  @file       ui_manager.h
 *  @brief      UI管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CUIManager
 *
 *  @brief      UI管理クラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CUIManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CUIManager( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CUIManager( void ) = default;

    /*!
     *  @brief      初期化
     */
    void    Initialize( void ) override;

private:
    static const aqua::CVector2     m_ui_score_position;    //! スコアの表示位置
    static const aqua::CVector2     m_ui_timer_position;    //! タイマーの表示位置
};
