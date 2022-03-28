
/*!
 *  @file       ui_component.cpp
 *  @brief      UIコンポーネント
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "ui_component.h"

const std::string IUIComponent::m_ui_category = "UIComponent";

/*
 *  コンストラクタ
 */
IUIComponent::
IUIComponent( aqua::IGameObject* parent, const std::string& object_name )
    : aqua::IGameObject( parent, object_name, m_ui_category )
{
}

/*
 *  初期化
 */
void
IUIComponent::
Initialize( const aqua::CVector2& position )
{
    m_Position = position;
}

/*
 *  初期化
 *  使用禁止
 */
void
IUIComponent::
Initialize( void )
{
}
