
/*!
 *  @file       sound_manager.h
 *  @brief      サウンド管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @brief      サウンドID
 */
enum class SOUND_ID
{
    BGM,            //! BGM
    DECISION,       //! 決定音
    HIT,            //! ヒット
    CREATE,         //! 生成音
    START,          //! ゲームスタート
    FINISH,         //! ゲーム終了
    FANFARE,        //! ファンファーレ

    MAX             //! サウンドIDの数
};

/*!
 *  @class      CSoundManager
 *
 *  @brief      サウンド管理クラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CSoundManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CSoundManager( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CSoundManager( void ) = default;

    /*!
     *  @brief      初期化
     */
    void        Initialize( void ) override;

    /*!
     *  @brief      解放
     */
    void        Finalize( void ) override;

    /*!
     *  @brief      サウンド再生
     *
     *  @param[in]  id      サウンドID
     */
    void        Play( SOUND_ID id );

private:
    static const std::string    m_sound_file_names[];   //! サウンドファイルパス
    aqua::CSoundPlayer*         m_SoundPlayer;          //! サウンドプレイヤー
};
