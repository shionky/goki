
/*!
 *  @file       splash_scene.h
 *  @brief      �X�v���b�V���V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\scene.h"

/*!
 *  @class      CSplashScene
 *
 *  @brief      �X�v���b�V���V�[���N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CSplashScene
    : public IScene
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CSplashScene( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CSplashScene( void ) = default;

    /*!
     *  @brief      ������
     */
    void        Initialize( void ) override;

    /*!
     *  @brief      �X�V
     */
    void        Update( void ) override;

    /*!
     *  @brief      �`��
     */
    void        Draw( void ) override;

    /*!
     *  @brief      ���
     */
    void        Finalize( void ) override;

private:
    static const float  m_wait_time;            //! �ҋ@����
    aqua::CTimer        m_WaitTimer;            //! �ҋ@�p�^�C�}�[
    aqua::CLabel        m_MaouLabel;            //! �������p���x��
    aqua::CLabel        m_NoahLabel;            //! �̂��p���x��
    aqua::CSprite       m_BackgroundSprite;     //! �w�i�X�v���C�g
};
