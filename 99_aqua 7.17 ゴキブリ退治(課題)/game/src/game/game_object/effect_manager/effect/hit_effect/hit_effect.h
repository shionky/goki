
/*!
 *  @file       hit_effect.h
 *  @brief      �q�b�g�G�t�F�N�g
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "..\effect.h"

/*!
 *  @class      CHitEffect
 *
 *  @brief      �q�b�g�G�t�F�N�g�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CHitEffect
    : public IEffect
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CHitEffect( IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CHitEffect( void ) = default;

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
    static const int    m_width;        //! ��
    static const int    m_height;       //! ����
    static const float  m_alive_time;   //! ��������
    aqua::CSprite       m_Sprite;       //! �X�v���C�g�N���X
    aqua::CTimer        m_AliveTimer;   //! ��������
    float               m_ScaleTime;    //! �g�傷�鎞��
    aqua::CVector2      m_Position;     //! �ʒu
};
