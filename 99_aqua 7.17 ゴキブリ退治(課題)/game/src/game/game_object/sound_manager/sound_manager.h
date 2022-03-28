
/*!
 *  @file       sound_manager.h
 *  @brief      �T�E���h�Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @brief      �T�E���hID
 */
enum class SOUND_ID
{
    BGM,            //! BGM
    DECISION,       //! ���艹
    HIT,            //! �q�b�g
    CREATE,         //! ������
    START,          //! �Q�[���X�^�[�g
    FINISH,         //! �Q�[���I��
    FANFARE,        //! �t�@���t�@�[��

    MAX             //! �T�E���hID�̐�
};

/*!
 *  @class      CSoundManager
 *
 *  @brief      �T�E���h�Ǘ��N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CSoundManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CSoundManager( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CSoundManager( void ) = default;

    /*!
     *  @brief      ������
     */
    void        Initialize( void ) override;

    /*!
     *  @brief      ���
     */
    void        Finalize( void ) override;

    /*!
     *  @brief      �T�E���h�Đ�
     *
     *  @param[in]  id      �T�E���hID
     */
    void        Play( SOUND_ID id );

private:
    static const std::string    m_sound_file_names[];   //! �T�E���h�t�@�C���p�X
    aqua::CSoundPlayer*         m_SoundPlayer;          //! �T�E���h�v���C���[
};
