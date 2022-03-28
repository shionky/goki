
/*!
 *  @file       mask_texture_manager.h
 *  @brief      マスクテクスチャ管理クラス
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
 *  @brief      aqua名前空間
 */
namespace aqua
{
    /*!
     *  @brief      aqua::core名前空間
     */
    namespace core
    {
        class CMaskTextureResource;

        /*!
         *  @class      CMaskTextureManager
         *
         *  @brief      マスクテクスチャ管理クラス
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
             *  @brief      インスタンスの取得
             *
             *  @return     インスタンスへの参照
             */
            static CMaskTextureManager& GetInstance( void );

            /*!
             *  @brief      マスクテクスチャの読み込み
             *
             *  @param[in]  file_name   ファイル名
             *
             *  @return     マスクテクスチャリソースクラス
             */
            CMaskTextureResource*   Load( const std::string& file_name );

            /*!
             *  @brief      マスクテクスチャの解放
             *
             *  @param[in]  texture     マスクテクスチャリソースクラス
             */
            void                    Unload( CMaskTextureResource* texture );

            /*!
             *  @brief      マスクテクスチャの検索
             *
             *  @param[in]  file_name   ファイル名
             *
             *  @return     マスクテクスチャリソースクラス
             */
            CMaskTextureResource*   Find( const std::string& file_name );

            /*!
             *  @brief      マスクテクスチャリストのクリア
             */
            void                    Clear( void );

        private:
            /*!
             *  @brief      コンストラクタ
             */
            CMaskTextureManager( void );

            /*!
             *  @brief      コピーコンストラクタ
             *
             *  @param[in]  rhs コピーオブジェクト
             */
            CMaskTextureManager( const CMaskTextureManager& rhs );

            /*!
             *  @brief      デストラクタ
             */
            ~CMaskTextureManager( void ) = default;

            /*!
             *  @brief      代入演算子
             *
             *  @param[in]  rhs 代入オブジェクト
             *
             *  @return     自身のオブジェクト
             */
            CMaskTextureManager&    operator=( const CMaskTextureManager& rhs );

            /*!
             *  @brief      マスクテクスチャリソースリスト
             */
            typedef std::list<CMaskTextureResource*> MASK_TEXTURE_LIST;

            //! マスクテクスチャリソースリスト
            MASK_TEXTURE_LIST   m_MaskTextureList;
        };
    }
}
