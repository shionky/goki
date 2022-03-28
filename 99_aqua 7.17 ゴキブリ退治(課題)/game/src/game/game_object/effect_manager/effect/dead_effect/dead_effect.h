
/*!
 *  @file       dead_effect.h
 *  @brief      デッドエフェクト
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "..\effect.h"

/*!
 *  @class      CDeadEffect
 *
 *  @brief      デッドエフェクトクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CDeadEffect
    : public IEffect
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CDeadEffect( IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CDeadEffect( void ) = default;

    /*!
     *  @brief      初期化
     *
     *  @param[in]  position    位置
     */
    void    Initialize( const aqua::CVector2& position ) override;

    /*!
     *  @brief      更新
     */
    void    Update( void ) override;

   /*!
    *  @brief      描画
    */
    void    Draw( void ) override;

   /*!
    *  @brief      解放
    */
    void    Finalize( void ) override;

private:
    static const int            m_width;            //! 幅
    static const int            m_height;           //! 高さ
    static const float          m_speed;            //! 速さ
    static const int            m_min_direction;    //! 向きの最小値
    static const int            m_max_direction;    //! 向きの最大値
    aqua::CAnimationSprite      m_AnimationSprite;  //! アニメーションスプライト
    aqua::CVector2              m_Position;         //! 位置
    aqua::CVector2              m_Velocity;         //! 移動速度
};
