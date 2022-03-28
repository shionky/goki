
/*!
 *  @file       title_scene.cpp
 *  @brief      タイトルシーン
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "title_scene.h"
#include "..\..\..\sound_manager\sound_manager.h"

const float CTitleScene::m_rotation_speed   = 90.0f;
const float CTitleScene::m_rotation_width   = 5.0f;
const float CTitleScene::m_fade_speed       = 180.0f;

/*
 *  コンストラクタ
 */
CTitleScene::
CTitleScene( aqua::IGameObject* parent )
    : IScene( parent, "TitleScene" )
{
}

/*
 *  初期化
 */
void
CTitleScene::
Initialize( void )
{
    m_BackgroundSprite.Create( "data\\floor.png" );

    m_TitleSprite.Create( "data\\title.png" );
    m_TitleSprite.position.x    = (float)aqua::GetWindowWidth( ) / 2.0f - (float)m_TitleSprite.GetTextureWidth( ) / 2.0f;
    m_TitleSprite.position.y    = (float)aqua::GetWindowHeight( ) * 0.2f;
    m_TitleSprite.anchor.x      = (float)m_TitleSprite.GetTextureWidth( ) / 2.0f;
    m_TitleSprite.anchor.y      = (float)m_TitleSprite.GetTextureHeight( ) / 2.0f;
    m_TitleSprite.scale         = aqua::CVector2( 2.0f, 2.0f );

    m_ClickSprite.Create( "data\\message.png" );
    m_ClickSprite.position.x = (float)aqua::GetWindowWidth( ) / 2.0f - (float)m_ClickSprite.GetTextureWidth( ) / 2.0f;
    m_ClickSprite.position.y = (float)aqua::GetWindowHeight( ) * 0.8f;

    m_RotationSpeed     = 0.0f;
    m_FadeSpeed         = 0.0f;
}

/*
 *  更新
 */
void
CTitleScene::
Update( void )
{
    m_RotationSpeed += aqua::DegToRad( m_rotation_speed ) * aqua::GetDeltaTime( );

    m_TitleSprite.rotation = aqua::DegToRad( sin( m_RotationSpeed ) * m_rotation_width );

    // クリック用メッセージのフェード処理
    int alpha = m_ClickSprite.color.alpha;

    m_FadeSpeed += aqua::DegToRad( m_fade_speed ) * aqua::GetDeltaTime( );

    alpha = (int)( abs( sin( m_FadeSpeed ) ) * (float)aqua::CColor::MAX_COLOR );

    m_ClickSprite.color.alpha = (unsigned char)alpha;

    // クリックされたらゲームメインシーンへ移行
    if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
    {
        Change(SCENE_ID::GAMEMAIN);

        CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

        if( sound ) sound->Play( SOUND_ID::DECISION );
    }
}

/*
 *  描画
 */
void
CTitleScene::
Draw( void )
{
    m_BackgroundSprite.Draw( );
    m_TitleSprite.Draw( );
    m_ClickSprite.Draw( );
}

/*
 *  解放
 */
void
CTitleScene::
Finalize( void )
{
    m_BackgroundSprite.Delete( );
    m_TitleSprite.Delete( );
    m_ClickSprite.Delete( );
}
