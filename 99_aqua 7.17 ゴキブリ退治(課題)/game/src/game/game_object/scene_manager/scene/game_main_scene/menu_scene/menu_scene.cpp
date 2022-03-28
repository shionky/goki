
/*!
 *  @file       menu_scene.cpp
 *  @brief      メニューシーン
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "menu_scene.h"
#include "..\..\..\..\sound_manager\sound_manager.h"

/*
 *  コンストラクタ
 */
CMenuScene::
CMenuScene( aqua::IGameObject* parent )
    : IScene( parent, "MenuScene" )
{
}

/*
 *  初期化
 */
void
CMenuScene::
Initialize( void )
{
    m_BackgroundSprite.Create( "data\\white.png" );
    m_BackgroundSprite.color = 0x40000000;

    m_PauseSprite.Create("data\\pause.png");
    m_PauseSprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_PauseSprite.GetTextureWidth() / 2.0f;
    m_PauseSprite.position.y = (float)aqua::GetWindowHeight() * 0.3f;

    m_MessageSprite.Create("data\\message.png");
    m_MessageSprite.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_MessageSprite.GetTextureWidth() / 2.0f;
    m_MessageSprite.position.y = (float)aqua::GetWindowHeight() * 0.7f;
}

/*
 *  更新
 */
void
CMenuScene::
Update( void )
{
    CSoundManager* sound = (CSoundManager*)aqua::FindGameObject( "SoundManager" );

    if( aqua::mouse::Trigger( aqua::mouse::BUTTON_ID::LEFT ) || aqua::mouse::Trigger( aqua::mouse::BUTTON_ID::MIDDLE ) )
    {
        Pop( );

        if( sound ) sound->Play( SOUND_ID::DECISION );
    }

    if( aqua::mouse::Trigger( aqua::mouse::BUTTON_ID::RIGHT ) )
    {
        Reset( );

        if( sound ) sound->Play( SOUND_ID::DECISION );
    }
}

/*
 *  描画
 */
void
CMenuScene::
Draw( void )
{
    m_BackgroundSprite.Draw( );
    m_PauseSprite.Draw( );
    m_MessageSprite.Draw( );
}

/*
 *  解放
 */
void
CMenuScene::
Finalize( void )
{
    m_BackgroundSprite.Delete( );
    m_PauseSprite.Delete( );
    m_MessageSprite.Delete( );
}
