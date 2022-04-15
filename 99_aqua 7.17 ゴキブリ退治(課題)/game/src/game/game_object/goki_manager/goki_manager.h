
/*!
 *  @file       goki_manager.h
 *  @brief      �S�L�u���Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "goki\goki_id.h"

/*!
 *  @class      CGokiManager
 *
 *  @brief      �S�L�u���Ǘ��N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGokiManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CGokiManager( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CGokiManager( void ) = default;

    //������
    void Initialize(void);
    //�X�V
    void Update(void);
    //�`��
    void Draw (void);
    //���
    void Finalize(void);
    //����
    void Create(GOKI_ID id);

private:
    //�����蔻��
    void CheckHitGoki(void);

    static const float m_create_interval;       //!<�����Ԋu
    static const float m_acceleration_time;     //!<���������x
    aqua::CTimer        m_CreateTimer;          //!<�����^�C�}�[


};
