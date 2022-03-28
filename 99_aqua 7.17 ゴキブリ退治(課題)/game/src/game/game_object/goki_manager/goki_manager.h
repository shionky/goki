
/*!
 *  @file       goki_manager.h
 *  @brief      ゴキブリ管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "goki\goki_id.h"

/*!
 *  @class      CGokiManager
 *
 *  @brief      ゴキブリ管理クラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGokiManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CGokiManager( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CGokiManager( void ) = default;

    //初期化
    void Initialize(void);
    //更新
    void Update(void);
    //描画
    void Draw (void);
    //解放
    void Finalize(void);

    void Create(GOKI_ID id);

private:
    void CheckHitGoki(void);

    static const float m_create_interval;
    static const float m_acceleration_time;
    aqua::CTimer        m_CreateTimer;


};
