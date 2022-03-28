
/*!
 *  @file       finish_message.h
 *  @brief      フィニッシュメッセージ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CFinishMessage
 *
 *  @brief      フィニッシュメッセージクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CFinishMessage
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent      親オブジェクト
     */
    CFinishMessage( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CFinishMessage( void ) = default;

    /*!
     *  @brief      初期化
     */
    void    Initialize( void ) override;

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

private:
    static const float  m_easing_limit;     //! イージングの制限時間
    static const float  m_view_limit;       //! メッセージ表示の制限時間
    static const float  m_min_scale;        //! 最小拡大率
    static const float  m_max_scale;        //! 最大拡大率
    aqua::CSprite       m_FinishSprite;     //! スプライト
    float               m_ElapsedTime;      //! 経過時間
};
