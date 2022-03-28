
/*!
 *  @file       mask_texture_resource.cpp
 *  @brief      �}�X�N�e�N�X�`�����\�[�X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include <DxLib.h>
#include <ctime>
#include "mask_texture_resource.h"
#include "..\..\..\debug\debug.h"
#include "..\..\..\utility\memory\memory.h"
#include "..\mask_texture_manager\mask_texture_manager.h"

/*
 *  �R���X�g���N�^
 */
aqua::core::CMaskTextureResource::
CMaskTextureResource( void )
    : IResourceObject( aqua::core::RESOURCE_TYPE::LOAD_MASK_TEXTURE )
    , m_Width( 0 )
    , m_Height( 0 )
{
}

/*
 *  �}�X�N�e�N�X�`���ǂݍ���
 */
void
aqua::core::CMaskTextureResource::
Load( const std::string& file_name )
{
    if( m_Enabel ) return;

    // �}�X�N�e�N�X�`���ǂݍ���
    m_ResourceHandle = LoadMask( file_name.c_str( ) );

    AQUA_DX_ASSERT( m_ResourceHandle, file_name + "�̓ǂݍ��݂Ɏ��s���܂����B" );

    // �O���t�B�b�N�T�C�Y�擾
    GetMaskSize( &m_Width, &m_Height, m_ResourceHandle);

    // �t�@�C���p�X��ۑ�
    m_ResourceName = file_name;

    // �ǂݍ��ݍς�
    m_Enabel = true;
}

/*
 *  �}�X�N�e�N�X�`�����
 */
void
aqua::core::CMaskTextureResource::
Unload( void )
{
    DeleteMask( m_ResourceHandle );

    m_ResourceHandle = AQUA_UNUSED_HANDLE;

    m_ResourceName.clear( );

    m_ReferenceCount = 0;

    m_ResourceType = RESOURCE_TYPE::DUMMY;

    m_Enabel = false;

    m_Width = m_Height = 0;
}
