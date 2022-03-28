
/*!
 *  @file       ui_component.h
 *  @brief      UI�R���|�[�l���g
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      IUIComponent
 *
 *  @brief      UI�R���|�[�l���g�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class IUIComponent
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     *  @param[in]  object_name     �I�u�W�F�N�g��
     */
    IUIComponent( aqua::IGameObject* parent, const std::string& object_name );

    /*!
     *  @brief      �f�X�g���N�^
     */
    virtual ~IUIComponent( void ) = default;

    /*!
     *  @brief      ������
     *
     *  @param[in]  position    �ʒu
     */
    virtual void    Initialize( const aqua::CVector2& position );

    /*!
     *  @brief      �ʒu�̎擾
     *
     *  @return     �ʒu
     */
    aqua::CVector2  GetPosition( void ) const { return m_Position; }

    /*!
     *  @brief      �ʒu�̐ݒ�
     *
     *  @param[in]  position    �ʒu
     */
    void            SetPosition(const aqua::CVector2& position) { m_Position = position; }

protected:
    aqua::CVector2              m_Position;     //! �\���ʒu

private:
    /*!
     *  @brief      ������<br>
     *              �g�p�֎~
     */
    void    Initialize( void );

    static const std::string    m_ui_category;  //! UI�J�e�S���[
};
