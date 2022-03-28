
/*!
 *  @file       mask_texture.cpp
 *  @brief      �}�X�N�e�N�X�`���N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include <windows.h>
#include "mask_texture.h"
#include "mask_texture_manager\mask_texture_manager.h"

/*
 *  �R���X�g���N�^
 */
aqua::CMaskTexture::
CMaskTexture( void )
    : m_MaskTextureResource( nullptr )
{
}

/*
 *  �R�s�[�R���X�g���N�^
 */
aqua::CMaskTexture::
CMaskTexture( const aqua::CMaskTexture& texture )
    : m_MaskTextureResource( nullptr )
{
    if( m_MaskTextureResource )
        m_MaskTextureResource->RemoveReference( );

    m_MaskTextureResource = texture.m_MaskTextureResource;

    // �Q�ƃJ�E���^���Z
    m_MaskTextureResource->AddReference( );
}

/*
 *  �e�N�X�`���ǂݍ���
 */
void
aqua::CMaskTexture::
Load( const std::string& file_name )
{
    // �e�N�X�`�����\�[�X�ޔ�
    core::CMaskTextureResource* texture = m_MaskTextureResource;

    // �e�N�X�`���}�l�[�W������e�N�X�`���擾
    m_MaskTextureResource = core::CMaskTextureManager::GetInstance( ).Load( file_name );

    if( texture )
    {
        int count = texture->RemoveReference( );

        // �O�̃e�N�X�`���̎Q�ƃJ�E���^���Ȃ��Ȃ�������
        if( count <= 0 )
            core::CMaskTextureManager::GetInstance( ).Unload( texture );
    }
}

/*
 *  �e�N�X�`�����
 */
void
aqua::CMaskTexture::
Unload( void )
{
    // �e�N�X�`�����
    if( m_MaskTextureResource )
        core::CMaskTextureManager::GetInstance( ).Unload( m_MaskTextureResource );

    m_MaskTextureResource = nullptr;
}

/*
 *  ������Z�q�̃I�[�o�[���[�h
 */
aqua::CMaskTexture&
aqua::CMaskTexture::
operator=( const aqua::CMaskTexture& texture )
{
    // �e�N�X�`���������Ă�����Q�Ƃ����Z
    if( m_MaskTextureResource )
        m_MaskTextureResource->RemoveReference( );

    m_MaskTextureResource = texture.m_MaskTextureResource;

    // �Q�ƃJ�E���^���Z
    m_MaskTextureResource->AddReference( );

    return *this;
}
