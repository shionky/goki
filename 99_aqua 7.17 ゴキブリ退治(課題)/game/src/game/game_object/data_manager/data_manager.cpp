
/*!
 *  @file       data_manager.cpp
 *  @brief      �f�[�^�Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "data_manager.h"

const std::string   CDataManager::m_save_file_name = "save.dat";

/*
 *  �R���X�g���N�^
 */
CDataManager::
CDataManager( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "DataManager" )
{
    ZeroMemory( &m_SaveData, sizeof( SAVE_DATA ) );
}

/*
 *  �Z�[�u����
 */
void
CDataManager::
Save( void )
{
    FILE * fp = nullptr;

    fopen_s( &fp, m_save_file_name.c_str( ), "wb" );

    if( fp )
    {
        // �����o��
        fwrite( &m_SaveData, sizeof( SAVE_DATA ), 1, fp );
    }

    fclose( fp );
}

/*
 *  ���[�h����
 */
void
CDataManager::
Load( void )
{
    FILE * fp = nullptr;

    fopen_s( &fp, m_save_file_name.c_str( ), "rb" );

    // �t�@�C�����J���Ȃ��������͂Ȃ�
    if( !fp )
    {
        // �V�����t�@�C�����쐬
        fopen_s( &fp, m_save_file_name.c_str( ), "wb" );

        // �f�[�^�����Z�b�g����
        Reset( );

        // �����l�̃Z�[�u�f�[�^�������o��
        fwrite( &m_SaveData, sizeof( SAVE_DATA ), 1, fp );

        fclose( fp );

        return;
    }

    // �t�@�C����ǂݍ���
    fread( &m_SaveData, sizeof( SAVE_DATA ), 1, fp );

    fclose( fp );
}

/*
 *  ���Z�b�g
 */
void
CDataManager::
Reset( void )
{
    // �Z�[�u�f�[�^���Z�b�g
    ZeroMemory( &m_SaveData, sizeof( SAVE_DATA ) );
}
