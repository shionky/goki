
/*!
 *  @file       stage.cpp
 *  @brief      �X�e�[�W
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "stage.h"
#include "..\camera_manager\camera_manager.h"

/*
 *  �R���X�g���N�^
 */
CStage::
CStage( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Stage" )
{
}

/*
 *  ������
 */
void
CStage::
Initialize( void )
{
    m_Sprite.Create("data\\floor.png");
}

/*
 *  �`��
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
 *  ���
 */
void
CStage::
Finalize( void )
{
    m_Sprite.Delete( );
}
