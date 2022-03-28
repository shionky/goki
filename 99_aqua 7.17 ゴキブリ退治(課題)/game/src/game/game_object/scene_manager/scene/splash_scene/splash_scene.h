
/*!
 *  @file       splash_scene.h
 *  @brief      スプラッシュシーン
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\scene.h"

/*!
 *  @class      CSplashScene
 *
 *  @brief      スプラッシュシーンクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CSplashScene
    : public IScene
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CSplashScene( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CSplashScene( void ) = default;

    /*!
     *  @brief      初期化
     */
    void        Initialize( void ) override;

    /*!
     *  @brief      更新
     */
    void        Update( void ) override;

    /*!
     *  @brief      描画
     */
    void        Draw( void ) override;

    /*!
     *  @brief      解放
     */
    void        Finalize( void ) override;

private:
    static const float  m_wait_time;            //! 待機時間
    aqua::CTimer        m_WaitTimer;            //! 待機用タイマー
    aqua::CLabel        m_MaouLabel;            //! 魔王魂用ラベル
    aqua::CLabel        m_NoahLabel;            //! のあ用ラベル
    aqua::CSprite       m_BackgroundSprite;     //! 背景スプライト
};
