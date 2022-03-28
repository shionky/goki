
/*!
 *  @file       mask_sprite.cpp
 *  @brief      �}�X�N�e�N�X�`���`��N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "mask_sprite.h"
#include "..\..\debug\debug.h"

/*
 *  �R���X�g���N�^
 */
aqua::CMaskSprite::
CMaskSprite( void )
    : position( CVector2::ZERO )
{
}

/*
 *  ����
 */
void
aqua::CMaskSprite::
Create( const std::string& file_name )
{
    Delete();

    m_MaskTexture.Load( file_name );
}

/*
 *  ���
 */
void
aqua::CMaskSprite::
Delete( void )
{
    m_MaskTexture.Unload( );
}

/*
 *  �`��
 */
void
aqua::CMaskSprite::
Draw( void )
{
    // �e�N�X�`�����ǂݍ��܂�Ă��Ȃ���Ε`�悵�Ȃ�
    if( !m_MaskTexture.IsEnable( ) ) return;

    // ��\���̎��͕`�悵�Ȃ�
    if( !visible ) return;

    // �e�N�X�`�����\�[�X�n���h���擾
    int handle = m_MaskTexture.GetResourceHandle( );

    // �}�X�N�̕`��
    DrawMask((int)position.x, (int)position.y, handle, DX_MASKTRANS_NONE);
}
