
/*!
 *  @file       mask_texture.cpp
 *  @brief      マスクテクスチャクラス
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include <windows.h>
#include "mask_texture.h"
#include "mask_texture_manager\mask_texture_manager.h"

/*
 *  コンストラクタ
 */
aqua::CMaskTexture::
CMaskTexture( void )
    : m_MaskTextureResource( nullptr )
{
}

/*
 *  コピーコンストラクタ
 */
aqua::CMaskTexture::
CMaskTexture( const aqua::CMaskTexture& texture )
    : m_MaskTextureResource( nullptr )
{
    if( m_MaskTextureResource )
        m_MaskTextureResource->RemoveReference( );

    m_MaskTextureResource = texture.m_MaskTextureResource;

    // 参照カウンタ加算
    m_MaskTextureResource->AddReference( );
}

/*
 *  テクスチャ読み込み
 */
void
aqua::CMaskTexture::
Load( const std::string& file_name )
{
    // テクスチャリソース退避
    core::CMaskTextureResource* texture = m_MaskTextureResource;

    // テクスチャマネージャからテクスチャ取得
    m_MaskTextureResource = core::CMaskTextureManager::GetInstance( ).Load( file_name );

    if( texture )
    {
        int count = texture->RemoveReference( );

        // 前のテクスチャの参照カウンタがなくなったら解放
        if( count <= 0 )
            core::CMaskTextureManager::GetInstance( ).Unload( texture );
    }
}

/*
 *  テクスチャ解放
 */
void
aqua::CMaskTexture::
Unload( void )
{
    // テクスチャ解放
    if( m_MaskTextureResource )
        core::CMaskTextureManager::GetInstance( ).Unload( m_MaskTextureResource );

    m_MaskTextureResource = nullptr;
}

/*
 *  代入演算子のオーバーロード
 */
aqua::CMaskTexture&
aqua::CMaskTexture::
operator=( const aqua::CMaskTexture& texture )
{
    // テクスチャを持っていたら参照を減算
    if( m_MaskTextureResource )
        m_MaskTextureResource->RemoveReference( );

    m_MaskTextureResource = texture.m_MaskTextureResource;

    // 参照カウンタ加算
    m_MaskTextureResource->AddReference( );

    return *this;
}
