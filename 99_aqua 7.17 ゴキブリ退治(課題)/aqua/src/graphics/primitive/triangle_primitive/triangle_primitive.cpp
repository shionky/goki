
/*!
 *  @file       triangle_primitive.cpp
 *  @brief      三角形描画クラス
 *  @author     Kazuya Maruyama
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "triangle_primitive.h"
#include "..\..\..\debug\debug.h"

/*
 *  コンストラクタ
 */
aqua::CTrianglePrimitive::
CTrianglePrimitive( void )
    : pointA( CVector2::ZERO )
    , pointB( CVector2::ZERO )
    , pointC( CVector2::ZERO )
    , color( aqua::CColor::WHITE )
    , fill( TRUE )
    , thickness( 1.0f )
    , blend_mode( aqua::ALPHABLEND::ALPHA )
{
}

/*
 *  初期化
 */
void
aqua::CTrianglePrimitive::
Setup(const aqua::CVector2& pointA_, const aqua::CVector2& pointB_, const aqua::CVector2& pointC_, const aqua::CColor& color_, bool fill_, float thickness_, aqua::ALPHABLEND blend_mode_)
{
    pointA      = pointA_;
    pointB      = pointB_;
    pointC      = pointC_;
    color       = color_;
    fill        = fill_;
    thickness   = thickness_;
    blend_mode  = blend_mode_;
}

/*
 *  描画
 */
void
aqua::CTrianglePrimitive::
Draw( void )
{
    // 非表示の時は描画しない
    if( !visible ) return;

    // アルファブレンド設定
    SetDrawBlendMode((int)blend_mode, color.alpha );

    // 描画
    DrawTriangleAA( pointA.x, pointA.y, pointB.x, pointB.y, pointC.x, pointC.y, color.GetColor(), ( fill ? TRUE : FALSE ), thickness );

    // アルファブレンドモードをデフォルトに戻す
    SetDrawBlendMode((int)aqua::ALPHABLEND::ALPHA, aqua::CColor::MAX_COLOR );
}
