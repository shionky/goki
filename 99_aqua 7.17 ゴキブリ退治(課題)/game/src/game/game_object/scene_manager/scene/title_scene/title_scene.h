
/*!
 *  @file       title_scene.h
 *  @brief      �^�C�g���V�[��
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
 *  @class      CTitleScene
 *
 *  @brief      �^�C�g���V�[���N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CTitleScene
    : public IScene
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CTitleScene( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CTitleScene( void ) = default;

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
    static const float  m_rotation_speed;       //! ��]���x
    static const float  m_rotation_width;       //! ��]�̕�
    static const float  m_fade_speed;           //! �t�F�[�h���x
    aqua::CSprite       m_BackgroundSprite;     //! �w�i�p�X�v���C�g
    aqua::CSprite       m_TitleSprite;          //! �^�C�g�����S�p�X�v���C�g
    aqua::CSprite       m_ClickSprite;          //! �N���b�N���b�Z�[�W�p�X�v���C�g
    float               m_RotationSpeed;        //! ��]���x
    float               m_FadeSpeed;            //! �t�F�[�h���x
};
