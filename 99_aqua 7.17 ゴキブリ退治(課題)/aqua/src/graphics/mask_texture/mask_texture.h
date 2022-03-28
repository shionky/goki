
/*!
 *  @file       mask_texture.h
 *  @brief      マスクテクスチャクラス
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "mask_texture_resource\mask_texture_resource.h"

/*!
 *  @brief      aqua名前空間
 */
namespace aqua
{
    /*!
     *  @class      CMaskTexture
     *
     *  @brief      マスクテクスチャクラス
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
         *  @brief      コンストラクタ
         */
        CMaskTexture( void );

        /*!
         *  @brief      コピーコンストラクタ
         *
         *  @param[in]  texture     マスクテクスチャクラス
         */
        CMaskTexture( const CMaskTexture& texture );

        /*!
         *  @brief      デストラクタ
         */
        ~CMaskTexture( void ) = default;

        /*!
         *  @brief      マスクテクスチャの読み込み
         *
         *  @param[in]  file_name   ファイル名
         */
        void    Load( const std::string& file_name );

        /*!
         *  @brief      マスクテクスチャの解放
         */
        void    Unload( void );

        /*!
         *  @brief      マスクテクスチャのリソースハンドル取得
         *
         *  @return     マスクテクスチャのリソースハンドル取得
         */
        int     GetResourceHandle( void ) const
        {
            if (!m_MaskTextureResource) return AQUA_UNUSED_HANDLE;

            return m_MaskTextureResource->GetResourceHandle();
        }

        /*!
         *  @brief      マスクテクスチャの横幅取得
         *
         *  @return     マスクテクスチャの横幅
         */
        int     GetWidth( void ) const
        {
            if (!m_MaskTextureResource) return 0;

            return m_MaskTextureResource->GetWidth();
        }

        /*!
         *  @brief      マスクテクスチャの縦幅取得
         *
         *  @return     マスクテクスチャの縦幅
         */
        int     GetHeight( void ) const
        {
            if (!m_MaskTextureResource) return 0;

            return m_MaskTextureResource->GetHeight();
        }

        /*!
         *  @brief      マスクテクスチャの読み込みチェック
         *
         *  @retval     true    読み込み済み
         *  @retval     false   読み込まれていない
         */
        bool    IsEnable( void ) const
        {
            if (!m_MaskTextureResource) return false;

            return m_MaskTextureResource->IsEnable();
        }

        /*!
         *  @brief      代入演算子のオーバーロード
         *
         *  @param[in]  texture     マスクテクスチャクラス
         */
        CMaskTexture&   operator=( const CMaskTexture& texture );

    private:
        //! マスクテクスチャリソースクラス
        core::CMaskTextureResource*     m_MaskTextureResource;
    };
}
