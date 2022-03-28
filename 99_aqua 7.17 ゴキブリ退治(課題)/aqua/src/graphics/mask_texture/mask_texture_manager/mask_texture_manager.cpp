
/*!
 *  @file       mask_texture_manager.cpp
 *  @brief      マスクテクスチャ管理クラス
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
 *  インスタンスの取得
 */
aqua::core::CMaskTextureManager&
aqua::core::CMaskTextureManager::
GetInstance( void )
{
    static CMaskTextureManager instance;

    return instance;
}

/*
 *  マスクテクスチャクラスの読み込み
 */
aqua::core::CMaskTextureResource*
aqua::core::CMaskTextureManager::
Load( const std::string& file_name )
{
    // マスクテクスチャ検索
    CMaskTextureResource* texture = Find( file_name );

    // テクスチャが見つからなかった
    if( !texture )
    {
        // 新しくマスクテクスチャ生成
        texture = AQUA_NEW CMaskTextureResource( );

        // 読み込み
        texture->Load( file_name );

        // テクスチャリストに追加
        m_MaskTextureList.push_back( texture );
    }

    // 参照カウンタ加算
    texture->AddReference( );

    return texture;
}

/*
 *  マスクテクスチャクラスの解放
 */
void
aqua::core::CMaskTextureManager::
Unload( core::CMaskTextureResource* texture )
{
    if( !texture ) return;

    if( m_MaskTextureList.empty( ) ) return;

    // 参照カウンタ減算
    // 参照がなくなったら解放
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
 *  マスクテクスチャクラスの検索
 */
aqua::core::CMaskTextureResource*
aqua::core::CMaskTextureManager::
Find( const std::string& file_name )
{
    if( m_MaskTextureList.empty( ) ) return nullptr;

    MASK_TEXTURE_LIST::iterator it  = m_MaskTextureList.begin( );
    MASK_TEXTURE_LIST::iterator end = m_MaskTextureList.end( );

    // ファイル名が一致したマスクテクスチャクラスを返す
    while( it != end )
    {
        if( ( *it )->GetResourceName( ) == file_name )
            return ( *it );

        ++it;
    }

    return nullptr;
}

/*
 *  マスクテクスチャリストのクリア
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
            // テクスチャ解放
            (*it)->Unload( );

            AQUA_SAFE_DELETE( (*it) );
        }

        ++it;
    }

    // マスクテクスチャリスト解放
    m_MaskTextureList.clear( );
}

/*
 *  コンストラクタ
 */
aqua::core::CMaskTextureManager::
CMaskTextureManager( void )
{
    m_MaskTextureList.clear( );
}

/*
 *  コピーコンストラクタ
 */
aqua::core::CMaskTextureManager::
CMaskTextureManager( const aqua::core::CMaskTextureManager& rhs )
{
    (void)rhs;
}

/*
 *  代入演算子
 */
aqua::core::CMaskTextureManager&
aqua::core::CMaskTextureManager::
operator=( const aqua::core::CMaskTextureManager& rhs )
{
    (void)rhs;

    return *this;
}
