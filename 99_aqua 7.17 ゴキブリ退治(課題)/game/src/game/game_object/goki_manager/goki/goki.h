
/*!
 *  @file       goki.h
 *  @brief      �S�L�u��
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      IGoki
 *
 *  @brief      �S�L�u���N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class IGoki
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent      �e�I�u�W�F�N�g
     *  @param[in]  name        �Q�[���I�u�W�F�N�g��
     */
    IGoki( aqua::IGameObject* parent, const std::string& name );

    /*!
     *  @brief      �f�X�g���N�^
     */
    virtual ~IGoki( void ) = default;

    /*!
     *  @brief      ������
     */
    virtual void    Initialize(void);

    /*!
     *  @brief      �X�V
     */
    virtual void    Update(void);

    /*!
     *  @brief      �`��
     */
    virtual void    Draw(void);
    
    /*!
     *  @brief      ���
     */
    virtual void    Finalize(void);

    /*!
 *  @brief          �_���[�W����
     */
    virtual void    Damege(void);

    /*!
    *@brief     ���擾
    *
    *@rerturn   ��
    */
    int         GetWidth(void);

    /*!
    *@brief     �����擾
    *
    *@rerturn   ����
    */
    int         GetHeight(void);

    /*!
    *@brief     ���a�擾
    *
    *@rerturn   ���a
    */
    float       GetRadius(void);

    /*!
    *@brief     �����ʒu�擾
    *
    *@rerturn   �����ʒu
    */
    aqua::CVector2  GetCenterPosition(void);

    /*!
    *@brief     ���C�t�擾
    *
    *@rerturn   ���C�t
    */
    int         GetLife(void);

protected:
    /*!
    *@brief     �ǔ���
    */
    void        CheckHitWall(void);

int                      m_Width;       //!<��
int                      m_Height;      //!<����
float                    m_Radius;      //!<�����蔼�a
aqua::CAnimationSprite   m_AnimeSprite; //!<�A�j���[�V�����t���X�v���C�g
aqua::CVector2           m_Position;    //!<�ʒu
aqua::CVector2           m_Velocity;    //!<���x
int                      m_Life;        //!<���C�t
int                      m_Score;       //!<�|�������̃X�R�A

private:
    static const int          m_default_life;     //!<�����̃��C�t
    static const int          m_default_score;    //!<�����̃X�R�A
    static const std::string  m_goki_category;    //!<�S�L�u���̃J�e�S��


};
