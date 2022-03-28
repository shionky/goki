
/*!
 *  @file       effect_manager.h
 *  @brief      エフェクト管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "effect\effect.h"
#include "effect\effect_id.h"

/*!
 *  @class      CEffectManager
 *
 *  @brief      エフェクト管理クラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CEffectManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CEffectManager( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CEffectManager( void ) = default;

    /*!
     *  @brief      エフェクト生成
     *
     *  @param[in]  id          エフェクトID
     *  @param[in]  position    位置
     */
    void        Create( EFFECT_ID id, const aqua::CVector2& position );
};
