
/*!
 *  @file       stage.h
 *  @brief      �X�e�[�W
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      CStage
 *
 *  @brief      �X�e�[�W�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CStage
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CStage( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CStage( void ) = default;

    /*!
     *  @brief      ������
     */
    void    Initialize( void ) override;

    /*!
     *  @brief      �`��
     */
    void    Draw( void ) override;

    /*!
     *  @brief      ���
     */
    void    Finalize( void ) override;

private:
    aqua::CSprite   m_Sprite;       //! �X�v���C�g�N���X
};
