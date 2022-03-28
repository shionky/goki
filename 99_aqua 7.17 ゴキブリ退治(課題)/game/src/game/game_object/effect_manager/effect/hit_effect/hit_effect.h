
/*!
 *  @file       hit_effect.h
 *  @brief      ヒットエフェクト
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "..\effect.h"

/*!
 *  @class      CHitEffect
 *
 *  @brief      ヒットエフェクトクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CHitEffect
    : public IEffect
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CHitEffect( IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CHitEffect( void ) = default;

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
    static const int    m_width;        //! 幅
    static const int    m_height;       //! 高さ
    static const float  m_alive_time;   //! 生存時間
    aqua::CSprite       m_Sprite;       //! スプライトクラス
    aqua::CTimer        m_AliveTimer;   //! 生存時間
    float               m_ScaleTime;    //! 拡大する時間
    aqua::CVector2      m_Position;     //! 位置
};
