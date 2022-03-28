
/*!
 *  @file       mask_texture_manager.h
 *  @brief      �}�X�N�e�N�X�`���Ǘ��N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include <list>
#include <string>

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
        class CMaskTextureResource;

        /*!
         *  @class      CMaskTextureManager
         *
         *  @brief      �}�X�N�e�N�X�`���Ǘ��N���X
         *
         *  @author     Kazuya Maruyama
         *
         *  @date       2021/03/03
         *
         *  @version    7.15
         */
        class CMaskTextureManager
        {
        public:
            /*!
             *  @brief      �C���X�^���X�̎擾
             *
             *  @return     �C���X�^���X�ւ̎Q��
             */
            static CMaskTextureManager& GetInstance( void );

            /*!
             *  @brief      �}�X�N�e�N�X�`���̓ǂݍ���
             *
             *  @param[in]  file_name   �t�@�C����
             *
             *  @return     �}�X�N�e�N�X�`�����\�[�X�N���X
             */
            CMaskTextureResource*   Load( const std::string& file_name );

            /*!
             *  @brief      �}�X�N�e�N�X�`���̉��
             *
             *  @param[in]  texture     �}�X�N�e�N�X�`�����\�[�X�N���X
             */
            void                    Unload( CMaskTextureResource* texture );

            /*!
             *  @brief      �}�X�N�e�N�X�`���̌���
             *
             *  @param[in]  file_name   �t�@�C����
             *
             *  @return     �}�X�N�e�N�X�`�����\�[�X�N���X
             */
            CMaskTextureResource*   Find( const std::string& file_name );

            /*!
             *  @brief      �}�X�N�e�N�X�`�����X�g�̃N���A
             */
            void                    Clear( void );

        private:
            /*!
             *  @brief      �R���X�g���N�^
             */
            CMaskTextureManager( void );

            /*!
             *  @brief      �R�s�[�R���X�g���N�^
             *
             *  @param[in]  rhs �R�s�[�I�u�W�F�N�g
             */
            CMaskTextureManager( const CMaskTextureManager& rhs );

            /*!
             *  @brief      �f�X�g���N�^
             */
            ~CMaskTextureManager( void ) = default;

            /*!
             *  @brief      ������Z�q
             *
             *  @param[in]  rhs ����I�u�W�F�N�g
             *
             *  @return     ���g�̃I�u�W�F�N�g
             */
            CMaskTextureManager&    operator=( const CMaskTextureManager& rhs );

            /*!
             *  @brief      �}�X�N�e�N�X�`�����\�[�X���X�g
             */
            typedef std::list<CMaskTextureResource*> MASK_TEXTURE_LIST;

            //! �}�X�N�e�N�X�`�����\�[�X���X�g
            MASK_TEXTURE_LIST   m_MaskTextureList;
        };
    }
}
