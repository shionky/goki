
/*!
 *  @file       ui_manager.h
 *  @brief      UI�Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CUIManager
 *
 *  @brief      UI�Ǘ��N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CUIManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CUIManager( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CUIManager( void ) = default;

    /*!
     *  @brief      ������
     */
    void    Initialize( void ) override;

private:
    static const aqua::CVector2     m_ui_score_position;    //! �X�R�A�̕\���ʒu
    static const aqua::CVector2     m_ui_timer_position;    //! �^�C�}�[�̕\���ʒu
};
