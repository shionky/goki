
/*!
 *  @file       sound_manager.cpp
 *  @brief      サウンド管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "sound_manager.h"

const std::string CSoundManager::m_sound_file_names[] =
{
    "data\\bgm.wav",
    "data\\decision.wav",
    "data\\hit.wav",
    "data\\goki_create.wav",
    "data\\start.wav",
    "data\\finish.wav",
    "data\\fanfare.wav",
};

/*
 *  コンストラクタ
 */
CSoundManager::
CSoundManager( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "SoundManager" )
    , m_SoundPlayer( nullptr )
{
}

/*
 *  初期化
 */
void
CSoundManager::
Initialize( void )
{
    if( !m_SoundPlayer ) m_SoundPlayer = AQUA_NEW aqua::CSoundPlayer[(int)SOUND_ID::MAX];

    // BGMはループ再生設定
    m_SoundPlayer[(int)SOUND_ID::BGM].Create( m_sound_file_names[(int)SOUND_ID::BGM], true );

    // SEは単発
    for (int i = (int)SOUND_ID::DECISION; i < (int)SOUND_ID::MAX; ++i)
        m_SoundPlayer[i].Create( m_sound_file_names[i], false, 100 );
}

/*
 *  解放
 */
void
CSoundManager::
Finalize( void )
{
    for (int i = 0; i < (int)SOUND_ID::MAX; ++i)
        m_SoundPlayer[i].Delete();

    AQUA_SAFE_DELETE_ARRAY( m_SoundPlayer );
}

/*
 *  サウンド再生
 */
void
CSoundManager::
Play( SOUND_ID id )
{
    if( !m_SoundPlayer ) return;

    m_SoundPlayer[(int)id].Play( );
}
