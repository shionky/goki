
/*!
 *  @file       effect_manager.h
 *  @brief      �G�t�F�N�g�Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "effect\effect.h"
#include "effect\effect_id.h"

/*!
 *  @class      CEffectManager
 *
 *  @brief      �G�t�F�N�g�Ǘ��N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CEffectManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CEffectManager( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CEffectManager( void ) = default;

    /*!
     *  @brief      �G�t�F�N�g����
     *
     *  @param[in]  id          �G�t�F�N�gID
     *  @param[in]  position    �ʒu
     */
    void        Create( EFFECT_ID id, const aqua::CVector2& position );
};
