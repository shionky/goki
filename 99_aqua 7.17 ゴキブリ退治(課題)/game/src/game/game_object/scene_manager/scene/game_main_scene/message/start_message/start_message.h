
/*!
 *  @file       start_message.h
 *  @brief      �X�^�[�g���b�Z�[�W
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CStartMessage
 *
 *  @brief      �X�^�[�g���b�Z�[�W�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CStartMessage
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent      �e�I�u�W�F�N�g
     */
    CStartMessage( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CStartMessage( void ) = default;

    /*!
     *  @brief      ������
     */
    void    Initialize( void ) override;

    /*!
     *  @brief      �X�V
     */
    void    Update( void ) override;

    /*!
     *  @brief      �`��
     */
    void    Draw( void ) override;

    /*!
     *  @brief      ���
     */
    void    Finalize( void ) override;

private:
    static const float  m_easing_limit;     //! �C�[�W���O�̐�������
    static const float  m_view_limit;       //! ���b�Z�[�W�\���̐�������
    static const float  m_min_scale;        //! �ŏ��g�嗦
    static const float  m_max_scale;        //! �ő�g�嗦
    aqua::CSprite       m_StartSprite;      //! �X�v���C�g
    float               m_ElapsedTime;      //! �o�ߎ���
};
