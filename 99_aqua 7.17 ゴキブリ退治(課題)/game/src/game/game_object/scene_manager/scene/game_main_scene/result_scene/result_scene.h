
/*!
 *  @file       result_scene.h
 *  @brief      リザルトシーン
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
 *  @class      CResultScene
 *
 *  @brief      リザルトシーンクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CResultScene
    : public IScene
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CResultScene( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CResultScene( void ) = default;

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
    aqua::CSprite       m_ResultSprite;     //! リザルトスプライト
    aqua::CSprite       m_MessageSprite;    //! メッセージスプライト
    aqua::CLabel        m_ScoreLabel;       //! スコア表示用ラベル
};
