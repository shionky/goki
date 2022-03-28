
/*!
 *  @file       effect.h
 *  @brief      �G�t�F�N�g
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      IEffect
 *
 *  @brief      �G�t�F�N�g�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class IEffect
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     *  @param[in]  object_name     �I�u�W�F�N�g��
     */
    IEffect( aqua::IGameObject* parent, const std::string& object_name );

    /*!
     *  @brief      ������
     *
     *  @param[in]  position    �ʒu
     */
    virtual void    Initialize( const aqua::CVector2& position );

private:
    /*!
     *  @brief      ������<br>
     *              �g�p�֎~
     */
    void    Initialize( void ) override;

    static const std::string    m_effect_category;  //! �G�t�F�N�g�J�e�S���[
};
