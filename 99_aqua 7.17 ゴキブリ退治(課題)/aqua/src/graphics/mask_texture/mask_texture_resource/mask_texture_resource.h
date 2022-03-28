
/*!
 *  @file       mask_texture_resource.h
 *  @brief      �}�X�N�e�N�X�`�����\�[�X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "..\..\..\resources\resources.h"

/*!
 *  @brief      aqua���O���
 */
namespace aqua
{
    /*!
     *  @brief      aqua::core���O���
     */
    namespace core
    {
        /*!
         *  @class      CMaskTextureResource
         *
         *  @brief      �}�X�N�e�N�X�`�����\�[�X�N���X
         *
         *  @author     Kazuya Maruyama
         *
         *  @date       2021/03/03
         *
         *  @version    7.15
         */
        class CMaskTextureResource
            : public core::IResourceObject
        {
        public:
            /*!
             *  @brief      �R���X�g���N�^
             */
            CMaskTextureResource( void );

            /*!
             *  @brief      �f�X�g���N�^
             */
            ~CMaskTextureResource( void ) = default;

            /*!
             *  @brief      �}�X�N�e�N�X�`���̓ǂݍ���
             *
             *  @param[in]  file_name   �t�@�C����
             */
            void        Load( const std::string& file_name );

            /*!
             *  @brief      �}�X�N�e�N�X�`���̉��
             */
            void        Unload( void );

            /*!
             *  @brief      �}�X�N�e�N�X�`���̉����擾
             *
             *  @return     �}�X�N�e�N�X�`���̉���
             */
            int         GetWidth(void) const { return m_Width; }

            /*!
             *  @brief      �}�X�N�e�N�X�`���̏c���擾
             *
             *  @return     �}�X�N�e�N�X�`���̏c��
             */
            int         GetHeight(void) const { return m_Height; }

        private:
            /*!
             *  @brief      �N���X���t�����h�o�^
             */
            friend class CMaskTexture;
            friend class CMaskTextureManager;

            //! �}�X�N�e�N�X�`���̕�
            int     m_Width;
            //! �}�X�N�e�N�X�`���̍���
            int     m_Height;
        };
    }
}
