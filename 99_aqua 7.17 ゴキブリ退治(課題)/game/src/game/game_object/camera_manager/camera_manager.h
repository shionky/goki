
/*!
 *  @file       camera_manager.h
 *  @brief      �J�����Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CCameraManager
 *
 *  @brief      �J�����Ǘ��N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CCameraManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CCameraManager( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CCameraManager( void ) = default;

    /*!
     *  @brief      ������
     */
    void    Initialize( void ) override;

    /*!
     *  @brief      �X�V
     */
    void    Update( void ) override;

    /*!
     *  @brief      �U���J�n
     */
    void    Shake( void );

    /*!
     *  @brief      �J�����ʒu�̎擾
     *
     *  @return     �J�����̈ʒu
     */
    aqua::CVector2  GetPosition( void ) const { return m_Position; };

private:
    static const float  m_shake_time;   //! �U�����鎞��
    aqua::CVector2      m_Position;     //! �ʒu
    aqua::CTimer        m_ShakeTimer;   //! �U�����鎞��
    bool                m_ShakeFlag;    //! �U���t���O
};
