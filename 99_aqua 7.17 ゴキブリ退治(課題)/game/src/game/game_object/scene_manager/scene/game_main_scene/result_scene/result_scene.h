
/*!
 *  @file       result_scene.h
 *  @brief      ���U���g�V�[��
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
 *  @class      CResultScene
 *
 *  @brief      ���U���g�V�[���N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CResultScene
    : public IScene
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CResultScene( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CResultScene( void ) = default;

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
    aqua::CSprite       m_ResultSprite;     //! ���U���g�X�v���C�g
    aqua::CSprite       m_MessageSprite;    //! ���b�Z�[�W�X�v���C�g
    aqua::CLabel        m_ScoreLabel;       //! �X�R�A�\���p���x��
};
