
/*!
 *  @file       menu_scene.h
 *  @brief      メニューシーン
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\..\scene.h"

/*!
 *  @class      CMenuScene
 *
 *  @brief      メニューシーンクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CMenuScene
    : public IScene
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CMenuScene( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CMenuScene( void ) = default;

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
    aqua::CSprite       m_BackgroundSprite; //! 背景スプライト
    aqua::CSprite       m_PauseSprite;      //! ポーズスプライト
    aqua::CSprite       m_MessageSprite;    //! メッセージスプライト
};
