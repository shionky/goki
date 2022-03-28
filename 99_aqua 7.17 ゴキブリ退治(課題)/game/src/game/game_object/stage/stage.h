
/*!
 *  @file       stage.h
 *  @brief      ステージ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CStage
 *
 *  @brief      ステージクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CStage
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CStage( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CStage( void ) = default;

    /*!
     *  @brief      初期化
     */
    void    Initialize( void ) override;

    /*!
     *  @brief      描画
     */
    void    Draw( void ) override;

    /*!
     *  @brief      解放
     */
    void    Finalize( void ) override;

private:
    aqua::CSprite   m_Sprite;       //! スプライトクラス
};
