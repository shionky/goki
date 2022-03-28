
/*!
 *  @file       camera_manager.h
 *  @brief      カメラ管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CCameraManager
 *
 *  @brief      カメラ管理クラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CCameraManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CCameraManager( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CCameraManager( void ) = default;

    /*!
     *  @brief      初期化
     */
    void    Initialize( void ) override;

    /*!
     *  @brief      更新
     */
    void    Update( void ) override;

    /*!
     *  @brief      振動開始
     */
    void    Shake( void );

    /*!
     *  @brief      カメラ位置の取得
     *
     *  @return     カメラの位置
     */
    aqua::CVector2  GetPosition( void ) const { return m_Position; };

private:
    static const float  m_shake_time;   //! 振動する時間
    aqua::CVector2      m_Position;     //! 位置
    aqua::CTimer        m_ShakeTimer;   //! 振動する時間
    bool                m_ShakeFlag;    //! 振動フラグ
};
