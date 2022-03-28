
/*!
 *  @file       game_main_scene.h
 *  @brief      ゲームメインシーン
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include "..\scene.h"

/*!
 *  @class      CGameMainScene
 *
 *  @brief      ゲームメインシーンクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CGameMainScene
    : public IScene
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent  親のオブジェクト
     */
    CGameMainScene( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CGameMainScene( void );

    /*!
     *  @brief      初期化
     */
    void            Initialize( void );

    /*!
     *  @brief      更新
     */
    void            Update( void );

private:
    /*!
     *  @brief      ゲーム開始
     */
    void            GameStart( void );

    /*!
     *  @brief      ゲーム中
     */
    void            GamePlay( void );

   /*!
    *  @brief      ゲーム終了
    */
    void            GameFinish( void );

    /*!
    *  @brief      スコアのセーブ
    */
    void            GameSave( void );

    /*!
     *  @brief      状態ID
     */
    enum STATE
    {
        STATE_GAME_START,       //! ゲーム開始
        STATE_GAME_PLAY,        //! ゲーム中
        STATE_GAME_FINISH,      //! ゲーム終了
        STATE_GAME_SAVE,        //! スコアのセーブ
    };

    STATE               m_State;        //! 状態ID
};
