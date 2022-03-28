
/*!
 *  @file       game_timer.h
 *  @brief      �Q�[���^�C�}�[
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\ui_component.h"

/*!
 *  @class      CGameTimer
 *
 *  @brief      �Q�[���^�C�}�[�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGameTimer
    : public IUIComponent
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CGameTimer( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CGameTimer( void ) = default;

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

    /*!
     *  @brief      �I�����m
     *
     *  @retval     true    �Q�[���I��
     *  @retval     false   �Q�[����
     */
    bool    Finished( void );

private:
    static const float  m_one_second;   //! 1�b
    static const int    m_time_limit;   //! ��������
    aqua::CLabel        m_TimerLabel;   //! �^�C�}�[�`��p���x��
    aqua::CTimer        m_SecondTimer;  //! 1�b�^�C�}�[
    int                 m_TimeLimit;    //! ��������
};
