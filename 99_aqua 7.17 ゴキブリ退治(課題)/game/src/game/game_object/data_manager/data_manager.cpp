
/*!
 *  @file       data_manager.cpp
 *  @brief      データ管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "data_manager.h"

const std::string   CDataManager::m_save_file_name = "save.dat";

/*
 *  コンストラクタ
 */
CDataManager::
CDataManager( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "DataManager" )
{
    ZeroMemory( &m_SaveData, sizeof( SAVE_DATA ) );
}

/*
 *  セーブ処理
 */
void
CDataManager::
Save( void )
{
    FILE * fp = nullptr;

    fopen_s( &fp, m_save_file_name.c_str( ), "wb" );

    if( fp )
    {
        // 書き出し
        fwrite( &m_SaveData, sizeof( SAVE_DATA ), 1, fp );
    }

    fclose( fp );
}

/*
 *  ロード処理
 */
void
CDataManager::
Load( void )
{
    FILE * fp = nullptr;

    fopen_s( &fp, m_save_file_name.c_str( ), "rb" );

    // ファイルが開けないもしくはない
    if( !fp )
    {
        // 新しいファイルを作成
        fopen_s( &fp, m_save_file_name.c_str( ), "wb" );

        // データをリセットする
        Reset( );

        // 初期値のセーブデータを書き出す
        fwrite( &m_SaveData, sizeof( SAVE_DATA ), 1, fp );

        fclose( fp );

        return;
    }

    // ファイルを読み込む
    fread( &m_SaveData, sizeof( SAVE_DATA ), 1, fp );

    fclose( fp );
}

/*
 *  リセット
 */
void
CDataManager::
Reset( void )
{
    // セーブデータリセット
    ZeroMemory( &m_SaveData, sizeof( SAVE_DATA ) );
}
