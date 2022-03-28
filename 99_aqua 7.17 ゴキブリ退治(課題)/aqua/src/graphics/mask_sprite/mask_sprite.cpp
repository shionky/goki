
/*!
 *  @file       mask_sprite.cpp
 *  @brief      マスクテクスチャ描画クラス
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "mask_sprite.h"
#include "..\..\debug\debug.h"

/*
 *  コンストラクタ
 */
aqua::CMaskSprite::
CMaskSprite( void )
    : position( CVector2::ZERO )
{
}

/*
 *  生成
 */
void
aqua::CMaskSprite::
Create( const std::string& file_name )
{
    Delete();

    m_MaskTexture.Load( file_name );
}

/*
 *  解放
 */
void
aqua::CMaskSprite::
Delete( void )
{
    m_MaskTexture.Unload( );
}

/*
 *  描画
 */
void
aqua::CMaskSprite::
Draw( void )
{
    // テクスチャが読み込まれていなければ描画しない
    if( !m_MaskTexture.IsEnable( ) ) return;

    // 非表示の時は描画しない
    if( !visible ) return;

    // テクスチャリソースハンドル取得
    int handle = m_MaskTexture.GetResourceHandle( );

    // マスクの描画
    DrawMask((int)position.x, (int)position.y, handle, DX_MASKTRANS_NONE);
}
