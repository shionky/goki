
/*!
 *  @file       game_score.h
 *  @brief      �X�R�A
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\ui_component.h"

/*!
 *  @class      CGameScore
 *
 *  @brief      �X�R�A�N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGameScore
    : public IUIComponent
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CGameScore( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CGameScore( void ) = default;

    /*!
     *  @brief      ������
     *
     *  @param[in]  position    �ʒu
     */
    void    Initialize( const aqua::CVector2& position ) override;

   /*!
    *  @brief      �`��
    */
    void    Draw( void ) override;

   /*!
    *  @brief      ���
    */
    void    Finalize( void ) override;

   /*!
    *  @brief      �X�R�A�̉��Z
    *
    *   @param[in]  score   ���Z����l
    */
    void    Add( int socre );

   /*!
    *  @brief      �X�R�A�̃N���A
    */
    void    Clear( void );

   /*!
    *  @brief       �X�R�A�̎擾
    *
    *   @return     ���݂̃X�R�A
    */
    int     GetScore( void ) const;

private:
    static const int    m_min_score;    //! �X�R�A�̍ŏ��l
    static const int    m_max_score;    //! �X�R�A�̍ő�l
    int                 m_Score;        //! �X�R�A
    aqua::CLabel        m_HiScoreLabel; //! �n�C�X�R�A�`��p���x��
    aqua::CLabel        m_ScoreLabel;   //! �X�R�A�`��p���x��
};
