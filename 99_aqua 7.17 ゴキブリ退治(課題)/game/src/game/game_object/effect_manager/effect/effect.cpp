
/*!
 *  @file       effect.cpp
 *  @brief      エフェクト
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "effect.h"

const std::string IEffect::m_effect_category = "Effect";

/*
 *  コンストラクタ
 */
IEffect::
IEffect( aqua::IGameObject* parent, const std::string& object_name )
    : aqua::IGameObject( parent, object_name, m_effect_category )
{
}

/*
 *  初期化
 */
void
IEffect::
Initialize( const aqua::CVector2& position )
{
    (void)position;
}

/*
 *  初期化
 *  使用禁止
 */
void
IEffect::
Initialize( void )
{
}
