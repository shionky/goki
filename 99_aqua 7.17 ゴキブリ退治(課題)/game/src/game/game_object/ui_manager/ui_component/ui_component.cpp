
/*!
 *  @file       ui_component.cpp
 *  @brief      UI�R���|�[�l���g
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "ui_component.h"

const std::string IUIComponent::m_ui_category = "UIComponent";

/*
 *  �R���X�g���N�^
 */
IUIComponent::
IUIComponent( aqua::IGameObject* parent, const std::string& object_name )
    : aqua::IGameObject( parent, object_name, m_ui_category )
{
}

/*
 *  ������
 */
void
IUIComponent::
Initialize( const aqua::CVector2& position )
{
    m_Position = position;
}

/*
 *  ������
 *  �g�p�֎~
 */
void
IUIComponent::
Initialize( void )
{
}
