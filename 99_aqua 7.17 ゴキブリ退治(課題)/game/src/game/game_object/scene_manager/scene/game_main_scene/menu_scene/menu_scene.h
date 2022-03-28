
/*!
 *  @file       menu_scene.h
 *  @brief      ���j���[�V�[��
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\..\scene.h"

/*!
 *  @class      CMenuScene
 *
 *  @brief      ���j���[�V�[���N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CMenuScene
    : public IScene
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CMenuScene( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CMenuScene( void ) = default;

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
    aqua::CSprite       m_BackgroundSprite; //! �w�i�X�v���C�g
    aqua::CSprite       m_PauseSprite;      //! �|�[�Y�X�v���C�g
    aqua::CSprite       m_MessageSprite;    //! ���b�Z�[�W�X�v���C�g
};
