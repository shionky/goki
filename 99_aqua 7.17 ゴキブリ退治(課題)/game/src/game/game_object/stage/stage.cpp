
/*!
 *  @file       stage.cpp
 *  @brief      ステージ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "stage.h"
#include "..\camera_manager\camera_manager.h"

/*
 *  コンストラクタ
 */
CStage::
CStage( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Stage" )
{
}

/*
 *  初期化
 */
void
CStage::
Initialize( void )
{
    m_Sprite.Create("data\\floor.png");
}

/*
 *  描画
 */
void
CStage::
Draw( void )
{
    CCameraManager* camera = (CCameraManager*)aqua::FindGameObject( "CameraManager" );

    m_Sprite.position = -camera->GetPosition( );

    m_Sprite.Draw( );
}

/*
 *  解放
 */
void
CStage::
Finalize( void )
{
    m_Sprite.Delete( );
}
