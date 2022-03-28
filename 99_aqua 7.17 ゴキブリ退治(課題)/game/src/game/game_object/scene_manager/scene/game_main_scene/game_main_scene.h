
/*!
 *  @file       game_main_scene.h
 *  @brief      �Q�[�����C���V�[��
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
 *  @class      CGameMainScene
 *
 *  @brief      �Q�[�����C���V�[���N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGameMainScene
    : public IScene
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent  �e�̃I�u�W�F�N�g
     */
    CGameMainScene( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CGameMainScene( void );

    /*!
     *  @brief      ������
     */
    void            Initialize( void );

    /*!
     *  @brief      �X�V
     */
    void            Update( void );

private:
    /*!
     *  @brief      �Q�[���J�n
     */
    void            GameStart( void );

    /*!
     *  @brief      �Q�[����
     */
    void            GamePlay( void );

   /*!
    *  @brief      �Q�[���I��
    */
    void            GameFinish( void );

    /*!
    *  @brief      �X�R�A�̃Z�[�u
    */
    void            GameSave( void );

    /*!
     *  @brief      ���ID
     */
    enum STATE
    {
        STATE_GAME_START,       //! �Q�[���J�n
        STATE_GAME_PLAY,        //! �Q�[����
        STATE_GAME_FINISH,      //! �Q�[���I��
        STATE_GAME_SAVE,        //! �X�R�A�̃Z�[�u
    };

    STATE               m_State;        //! ���ID
};
