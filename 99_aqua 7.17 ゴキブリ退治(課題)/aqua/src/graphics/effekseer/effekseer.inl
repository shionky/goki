
/*!
 *  @file       effekseer.inl
 *  @brief      Effekseer�C�����C������
 *  @author     Kazuya Maruyama
 *  @date       2021/03/03
 *  @version    7.15
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

/*
 *  Effekseer�̃��\�[�X�n���h���擾
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
 *  Effekseer�ǂݍ��݃`�F�b�N
 */
inline
bool
CEffekseer::
IsEnable( void ) const
{
    // ���\�[�X���Ȃ�
    if( !m_EffekseerResource ) return false;

    // �ǂݍ��܂�Ă��Ȃ�
    return m_EffekseerResource->IsEnable( );
}
