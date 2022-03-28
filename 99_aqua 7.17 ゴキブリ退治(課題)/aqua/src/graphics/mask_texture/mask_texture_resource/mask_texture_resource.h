
/*!
 *  @file       mask_texture_resource.h
 *  @brief      マスクテクスチャリソース
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "..\..\..\resources\resources.h"

/*!
 *  @brief      aqua名前空間
 */
namespace aqua
{
    /*!
     *  @brief      aqua::core名前空間
     */
    namespace core
    {
        /*!
         *  @class      CMaskTextureResource
         *
         *  @brief      マスクテクスチャリソースクラス
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
             *  @brief      コンストラクタ
             */
            CMaskTextureResource( void );

            /*!
             *  @brief      デストラクタ
             */
            ~CMaskTextureResource( void ) = default;

            /*!
             *  @brief      マスクテクスチャの読み込み
             *
             *  @param[in]  file_name   ファイル名
             */
            void        Load( const std::string& file_name );

            /*!
             *  @brief      マスクテクスチャの解放
             */
            void        Unload( void );

            /*!
             *  @brief      マスクテクスチャの横幅取得
             *
             *  @return     マスクテクスチャの横幅
             */
            int         GetWidth(void) const { return m_Width; }

            /*!
             *  @brief      マスクテクスチャの縦幅取得
             *
             *  @return     マスクテクスチャの縦幅
             */
            int         GetHeight(void) const { return m_Height; }

        private:
            /*!
             *  @brief      クラスをフレンド登録
             */
            friend class CMaskTexture;
            friend class CMaskTextureManager;

            //! マスクテクスチャの幅
            int     m_Width;
            //! マスクテクスチャの高さ
            int     m_Height;
        };
    }
}
