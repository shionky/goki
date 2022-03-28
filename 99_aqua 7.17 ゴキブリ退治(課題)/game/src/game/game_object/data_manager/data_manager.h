
/*!
 *  @file       data_manager.h
 *  @brief      データ管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"
#include <string>

/*!
 *  @brief      セーブデータ構造体
 */
struct SAVE_DATA
{
    int hi_score;   //! ハイスコア
};

/*!
 *  @class      CDataManager
 *
 *  @brief      データ管理クラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class CDataManager
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     */
    CDataManager( aqua::IGameObject* parent );

    /*!
     *  @brief      デストラクタ
     */
    ~CDataManager( void ) = default;

    /*!
     *  @brief      セーブ処理
     */
    void    Save( void );

    /*!
     *  @brief      ロード処理
     */
    void    Load( void );

    /*!
     *  @brief      リセット
     */
    void    Reset( void );

    /*!
     *  @brief      セーブデータ取得
     *
     *  @return     セーブデータ
     */
    SAVE_DATA* GetSaveData( void ) { return &m_SaveData; }

private:
    static const std::string    m_save_file_name;   //! セーブデータファイル名
    SAVE_DATA                   m_SaveData;         //! セーブデータ
};
