
/*!
 *  @file       start_message.h
 *  @brief      スタートメッセージ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CStartMessage
 *
 *  @brief      スタートメッセージクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CStartMessage
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent      親オブジェクト
     */
    CStartMessage( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CStartMessage( void ) = default;

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
    aqua::CSprite       m_StartSprite;      //! スプライト
    float               m_ElapsedTime;      //! 経過時間
};
