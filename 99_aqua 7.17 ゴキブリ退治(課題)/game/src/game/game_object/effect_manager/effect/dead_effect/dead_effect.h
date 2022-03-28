
/*!
 *  @file       dead_effect.h
 *  @brief      �f�b�h�G�t�F�N�g
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "..\effect.h"

/*!
 *  @class      CDeadEffect
 *
 *  @brief      �f�b�h�G�t�F�N�g�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CDeadEffect
    : public IEffect
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CDeadEffect( IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CDeadEffect( void ) = default;

    /*!
     *  @brief      ������
     *
     *  @param[in]  position    �ʒu
     */
    void    Initialize( const aqua::CVector2& position ) override;

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
    static const int            m_width;            //! ��
    static const int            m_height;           //! ����
    static const float          m_speed;            //! ����
    static const int            m_min_direction;    //! �����̍ŏ��l
    static const int            m_max_direction;    //! �����̍ő�l
    aqua::CAnimationSprite      m_AnimationSprite;  //! �A�j���[�V�����X�v���C�g
    aqua::CVector2              m_Position;         //! �ʒu
    aqua::CVector2              m_Velocity;         //! �ړ����x
};
