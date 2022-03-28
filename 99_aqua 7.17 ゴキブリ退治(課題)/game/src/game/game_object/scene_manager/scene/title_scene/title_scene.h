
/*!
 *  @file       title_scene.h
 *  @brief      タイトルシーン
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
 *  @class      CTitleScene
 *
 *  @brief      タイトルシーンクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CTitleScene
    : public IScene
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CTitleScene( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CTitleScene( void ) = default;

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
    static const float  m_rotation_speed;       //! 回転速度
    static const float  m_rotation_width;       //! 回転の幅
    static const float  m_fade_speed;           //! フェード速度
    aqua::CSprite       m_BackgroundSprite;     //! 背景用スプライト
    aqua::CSprite       m_TitleSprite;          //! タイトルロゴ用スプライト
    aqua::CSprite       m_ClickSprite;          //! クリックメッセージ用スプライト
    float               m_RotationSpeed;        //! 回転速度
    float               m_FadeSpeed;            //! フェード速度
};
