
/*!
 *  @file       goki.h
 *  @brief      ゴキブリ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      IGoki
 *
 *  @brief      ゴキブリクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class IGoki
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent      親オブジェクト
     *  @param[in]  name        ゲームオブジェクト名
     */
    IGoki( aqua::IGameObject* parent, const std::string& name );

    /*!
     *  @brief      デストラクタ
     */
    virtual ~IGoki( void ) = default;

    /*!
     *  @brief      初期化
     */
    virtual void    Initialize(void);

    /*!
     *  @brief      更新
     */
    virtual void    Update(void);

    /*!
     *  @brief      描画
     */
    virtual void    Draw(void);
    
    /*!
     *  @brief      解放
     */
    virtual void    Finalize(void);

    /*!
 *  @brief          ダメージ処理
     */
    virtual void    Damege(void);

    /*!
    *@brief     幅取得
    *
    *@rerturn   幅
    */
    int         GetWidth(void);

    /*!
    *@brief     高さ取得
    *
    *@rerturn   高さ
    */
    int         GetHeight(void);

    /*!
    *@brief     半径取得
    *
    *@rerturn   半径
    */
    float       GetRadius(void);

    /*!
    *@brief     中央位置取得
    *
    *@rerturn   中央位置
    */
    aqua::CVector2  GetCenterPosition(void);

    /*!
    *@brief     ライフ取得
    *
    *@rerturn   ライフ
    */
    int         GetLife(void);

protected:
    /*!
    *@brief     壁判定
    */
    void        CheckHitWall(void);

int                      m_Width;       //!<幅
int                      m_Height;      //!<高さ
float                    m_Radius;      //!<当たり半径
aqua::CAnimationSprite   m_AnimeSprite; //!<アニメーション付きスプライト
aqua::CVector2           m_Position;    //!<位置
aqua::CVector2           m_Velocity;    //!<速度
int                      m_Life;        //!<ライフ
int                      m_Score;       //!<倒した時のスコア

private:
    static const int          m_default_life;     //!<初期のライフ
    static const int          m_default_score;    //!<初期のスコア
    static const std::string  m_goki_category;    //!<ゴキブリのカテゴリ


};
