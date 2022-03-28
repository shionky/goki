
/*!
 *  @file       effect.h
 *  @brief      エフェクト
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      IEffect
 *
 *  @brief      エフェクトクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class IEffect
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     *  @param[in]  object_name     オブジェクト名
     */
    IEffect( aqua::IGameObject* parent, const std::string& object_name );

    /*!
     *  @brief      初期化
     *
     *  @param[in]  position    位置
     */
    virtual void    Initialize( const aqua::CVector2& position );

private:
    /*!
     *  @brief      初期化<br>
     *              使用禁止
     */
    void    Initialize( void ) override;

    static const std::string    m_effect_category;  //! エフェクトカテゴリー
};
