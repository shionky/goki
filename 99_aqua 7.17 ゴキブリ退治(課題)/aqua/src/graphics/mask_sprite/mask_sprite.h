
/*!
 *  @file       mask_sprite.h
 *  @brief      �}�X�N�e�N�X�`���`��N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include <DxLib.h>
#include <string>
#include "..\graphic_filter\graphic_filter.h"
#include "..\mask_texture\mask_texture.h"
#include "..\draw_object\draw_object.h"
#include "..\..\mathematics\mathematics.h"
#include "..\..\utility\utility.h"

/*!
 *  @brief      aqua���O���
 */
namespace aqua
{
    /*!
     *  @class      CMaskSprite
     *
     *  @brief      �}�X�N�e�N�X�`���`��N���X
     *
     *  @author     Kazuya Maruyama
     *
     *  @date       2021/03/03
     *
     *  @version    7.15
     */
    class CMaskSprite
        : public aqua::core::IDrawObject
    {
    public:
        //! �ʒu
        aqua::CVector2  position;

        /*!
         *  @brief      �R���X�g���N�^
         */
        CMaskSprite( void );

        /*!
         *  @brief      �f�X�g���N�^
         */
        ~CMaskSprite( void ) = default;

        /*!
         *  @brief      ����
         *
         *  @param[in]  file_name   �e�N�X�`���t�@�C����
         */
        void    Create( const std::string& file_name );

        /*!
         *  @brief      ���
         */
        void    Delete( void );

        /*!
         *  @brief      �`��
         */
        void    Draw( void );

        /*!
         *  @brief      �e�N�X�`���̕��擾
         *
         *  @return     �e�N�X�`���̕�
         */
        int     GetTextureWidth(void) const { return m_MaskTexture.GetWidth(); }

        /*!
         *  @brief      �e�N�X�`���̍����擾
         *
         *  @return     �e�N�X�`���̍���
         */
        int     GetTextureHeight(void) const { return m_MaskTexture.GetHeight(); }

        /*!
         *  @brief      ���\�[�X�n���h���擾
         *
         *  @return     ���\�[�X�n���h��
         */
        int     GetResourceHandle(void) const { return m_MaskTexture.GetResourceHandle(); }

    private:
        //! �}�X�N�e�N�X�`��
        aqua::CMaskTexture      m_MaskTexture;
    };
}
