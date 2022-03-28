
/*!
 *  @file       mask_sprite.h
 *  @brief      マスクテクスチャ描画クラス
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
 *  @brief      aqua名前空間
 */
namespace aqua
{
    /*!
     *  @class      CMaskSprite
     *
     *  @brief      マスクテクスチャ描画クラス
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
        //! 位置
        aqua::CVector2  position;

        /*!
         *  @brief      コンストラクタ
         */
        CMaskSprite( void );

        /*!
         *  @brief      デストラクタ
         */
        ~CMaskSprite( void ) = default;

        /*!
         *  @brief      生成
         *
         *  @param[in]  file_name   テクスチャファイル名
         */
        void    Create( const std::string& file_name );

        /*!
         *  @brief      解放
         */
        void    Delete( void );

        /*!
         *  @brief      描画
         */
        void    Draw( void );

        /*!
         *  @brief      テクスチャの幅取得
         *
         *  @return     テクスチャの幅
         */
        int     GetTextureWidth(void) const { return m_MaskTexture.GetWidth(); }

        /*!
         *  @brief      テクスチャの高さ取得
         *
         *  @return     テクスチャの高さ
         */
        int     GetTextureHeight(void) const { return m_MaskTexture.GetHeight(); }

        /*!
         *  @brief      リソースハンドル取得
         *
         *  @return     リソースハンドル
         */
        int     GetResourceHandle(void) const { return m_MaskTexture.GetResourceHandle(); }

    private:
        //! マスクテクスチャ
        aqua::CMaskTexture      m_MaskTexture;
    };
}
