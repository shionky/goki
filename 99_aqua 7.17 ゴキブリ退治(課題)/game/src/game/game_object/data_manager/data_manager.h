
/*!
 *  @file       data_manager.h
 *  @brief      �f�[�^�Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include <string>

/*!
 *  @brief      �Z�[�u�f�[�^�\����
 */
struct SAVE_DATA
{
    int hi_score;   //! �n�C�X�R�A
};

/*!
 *  @class      CDataManager
 *
 *  @brief      �f�[�^�Ǘ��N���X
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CDataManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      �R���X�g���N�^
     *
     *  @param[in]  parent          �e�I�u�W�F�N�g
     */
    CDataManager( aqua::IGameObject* parent );

    /*!
     *  @brief      �f�X�g���N�^
     */
    ~CDataManager( void ) = default;

    /*!
     *  @brief      �Z�[�u����
     */
    void    Save( void );

    /*!
     *  @brief      ���[�h����
     */
    void    Load( void );

    /*!
     *  @brief      ���Z�b�g
     */
    void    Reset( void );

    /*!
     *  @brief      �Z�[�u�f�[�^�擾
     *
     *  @return     �Z�[�u�f�[�^
     */
    SAVE_DATA* GetSaveData( void ) { return &m_SaveData; }

private:
    static const std::string    m_save_file_name;   //! �Z�[�u�f�[�^�t�@�C����
    SAVE_DATA                   m_SaveData;         //! �Z�[�u�f�[�^
};
