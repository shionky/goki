
/*!
 *  @file       finish_message.h
 *  @brief      �t�B�j�b�V�����b�Z�[�W
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CFinishMessage
 *
 *  @brief      �t�B�j�b�V�����b�Z�[�W�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CFinishMessage
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent      �e�I�u�W�F�N�g
     */
    CFinishMessage( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CFinishMessage( void ) = default;

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
    aqua::CSprite       m_FinishSprite;     //! �X�v���C�g
    float               m_ElapsedTime;      //! �o�ߎ���
};
