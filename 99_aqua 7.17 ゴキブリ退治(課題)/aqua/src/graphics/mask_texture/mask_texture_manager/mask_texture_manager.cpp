
/*!
 *  @file       mask_texture_manager.cpp
 *  @brief      �}�X�N�e�N�X�`���Ǘ��N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "mask_texture_manager.h"
#include "..\mask_texture_resource\mask_texture_resource.h"
#include "..\..\..\debug\debug.h"
#include "..\..\..\utility\memory\memory.h"

/*
 *  �C���X�^���X�̎擾
 */
aqua::core::CMaskTextureManager&
aqua::core::CMaskTextureManager::
GetInstance( void )
{
    static CMaskTextureManager instance;

    return instance;
}

/*
 *  �}�X�N�e�N�X�`���N���X�̓ǂݍ���
 */
aqua::core::CMaskTextureResource*
aqua::core::CMaskTextureManager::
Load( const std::string& file_name )
{
    // �}�X�N�e�N�X�`������
    CMaskTextureResource* texture = Find( file_name );

    // �e�N�X�`����������Ȃ�����
    if( !texture )
    {
        // �V�����}�X�N�e�N�X�`������
        texture = AQUA_NEW CMaskTextureResource( );

        // �ǂݍ���
        texture->Load( file_name );

        // �e�N�X�`�����X�g�ɒǉ�
        m_MaskTextureList.push_back( texture );
    }

    // �Q�ƃJ�E���^���Z
    texture->AddReference( );

    return texture;
}

/*
 *  �}�X�N�e�N�X�`���N���X�̉��
 */
void
aqua::core::CMaskTextureManager::
Unload( core::CMaskTextureResource* texture )
{
    if( !texture ) return;

    if( m_MaskTextureList.empty( ) ) return;

    // �Q�ƃJ�E���^���Z
    // �Q�Ƃ��Ȃ��Ȃ�������
    if( texture->RemoveReference( ) > 0 ) return;

    MASK_TEXTURE_LIST::iterator it  = m_MaskTextureList.begin( );
    MASK_TEXTURE_LIST::iterator end = m_MaskTextureList.end( );

    while( it != end )
    {
        if( (*it)->GetResourceName( ) == texture->GetResourceName( ) )
        {
            (*it)->Unload( );

            AQUA_SAFE_DELETE( (*it) );

            m_MaskTextureList.erase( it );

            break;
        }

        ++it;
    }
}

/*
 *  �}�X�N�e�N�X�`���N���X�̌���
 */
aqua::core::CMaskTextureResource*
aqua::core::CMaskTextureManager::
Find( const std::string& file_name )
{
    if( m_MaskTextureList.empty( ) ) return nullptr;

    MASK_TEXTURE_LIST::iterator it  = m_MaskTextureList.begin( );
    MASK_TEXTURE_LIST::iterator end = m_MaskTextureList.end( );

    // �t�@�C��������v�����}�X�N�e�N�X�`���N���X��Ԃ�
    while( it != end )
    {
        if( ( *it )->GetResourceName( ) == file_name )
            return ( *it );

        ++it;
    }

    return nullptr;
}

/*
 *  �}�X�N�e�N�X�`�����X�g�̃N���A
 */
void
aqua::core::CMaskTextureManager::
Clear( void )
{
    if( m_MaskTextureList.empty( ) ) return;

    MASK_TEXTURE_LIST::iterator it  = m_MaskTextureList.begin( );
    MASK_TEXTURE_LIST::iterator end = m_MaskTextureList.end( );

    while( it != end )
    {
        if( (*it) )
        {
            // �e�N�X�`�����
            (*it)->Unload( );

            AQUA_SAFE_DELETE( (*it) );
        }

        ++it;
    }

    // �}�X�N�e�N�X�`�����X�g���
    m_MaskTextureList.clear( );
}

/*
 *  �R���X�g���N�^
 */
aqua::core::CMaskTextureManager::
CMaskTextureManager( void )
{
    m_MaskTextureList.clear( );
}

/*
 *  �R�s�[�R���X�g���N�^
 */
aqua::core::CMaskTextureManager::
CMaskTextureManager( const aqua::core::CMaskTextureManager& rhs )
{
    (void)rhs;
}

/*
 *  ������Z�q
 */
aqua::core::CMaskTextureManager&
aqua::core::CMaskTextureManager::
operator=( const aqua::core::CMaskTextureManager& rhs )
{
    (void)rhs;

    return *this;
}
