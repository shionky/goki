
/*!
 *  @file       mask_texture.h
 *  @brief      �}�X�N�e�N�X�`���N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "mask_texture_resource\mask_texture_resource.h"

/*!
 *  @brief      aqua���O���
 */
namespace aqua
{
    /*!
     *  @class      CMaskTexture
     *
     *  @brief      �}�X�N�e�N�X�`���N���X
     *
     *  @author     Kazuya Maruyama
     *
     *  @date       2021/03/03
     *
     *  @version    7.15
     */
    class CMaskTexture
    {
    public:
        /*!
         *  @brief      �R���X�g���N�^
         */
        CMaskTexture( void );

        /*!
         *  @brief      �R�s�[�R���X�g���N�^
         *
         *  @param[in]  texture     �}�X�N�e�N�X�`���N���X
         */
        CMaskTexture( const CMaskTexture& texture );

        /*!
         *  @brief      �f�X�g���N�^
         */
        ~CMaskTexture( void ) = default;

        /*!
         *  @brief      �}�X�N�e�N�X�`���̓ǂݍ���
         *
         *  @param[in]  file_name   �t�@�C����
         */
        void    Load( const std::string& file_name );

        /*!
         *  @brief      �}�X�N�e�N�X�`���̉��
         */
        void    Unload( void );

        /*!
         *  @brief      �}�X�N�e�N�X�`���̃��\�[�X�n���h���擾
         *
         *  @return     �}�X�N�e�N�X�`���̃��\�[�X�n���h���擾
         */
        int     GetResourceHandle( void ) const
        {
            if (!m_MaskTextureResource) return AQUA_UNUSED_HANDLE;

            return m_MaskTextureResource->GetResourceHandle();
        }

        /*!
         *  @brief      �}�X�N�e�N�X�`���̉����擾
         *
         *  @return     �}�X�N�e�N�X�`���̉���
         */
        int     GetWidth( void ) const
        {
            if (!m_MaskTextureResource) return 0;

            return m_MaskTextureResource->GetWidth();
        }

        /*!
         *  @brief      �}�X�N�e�N�X�`���̏c���擾
         *
         *  @return     �}�X�N�e�N�X�`���̏c��
         */
        int     GetHeight( void ) const
        {
            if (!m_MaskTextureResource) return 0;

            return m_MaskTextureResource->GetHeight();
        }

        /*!
         *  @brief      �}�X�N�e�N�X�`���̓ǂݍ��݃`�F�b�N
         *
         *  @retval     true    �ǂݍ��ݍς�
         *  @retval     false   �ǂݍ��܂�Ă��Ȃ�
         */
        bool    IsEnable( void ) const
        {
            if (!m_MaskTextureResource) return false;

            return m_MaskTextureResource->IsEnable();
        }

        /*!
         *  @brief      ������Z�q�̃I�[�o�[���[�h
         *
         *  @param[in]  texture     �}�X�N�e�N�X�`���N���X
         */
        CMaskTexture&   operator=( const CMaskTexture& texture );

    private:
        //! �}�X�N�e�N�X�`�����\�[�X�N���X
        core::CMaskTextureResource*     m_MaskTextureResource;
    };
}
