
/*!
 *  @file       effekseer.inl
 *  @brief      Effekseerインライン処理
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

/*
 *  Effekseerのリソースハンドル取得
 */
inline
int
CEffekseer::
GetResourceHandle( void ) const
{
    if( !m_EffekseerResource ) return AQUA_UNUSED_HANDLE;

    return m_EffekseerResource->GetResourceHandle( );
}

/*
 *  Effekseer読み込みチェック
 */
inline
bool
CEffekseer::
IsEnable( void ) const
{
    // リソースがない
    if( !m_EffekseerResource ) return false;

    // 読み込まれていない
    return m_EffekseerResource->IsEnable( );
}
