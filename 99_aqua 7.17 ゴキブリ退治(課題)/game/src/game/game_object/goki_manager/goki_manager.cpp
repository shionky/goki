
/*!
 *  @file       goki_manager.cpp
 *  @brief      �S�L�u���Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "goki_manager.h"
#include "goki\goki_brown\goki_brown.h"
#include "goki\goki_pink\goki_pink.h"
#include "goki\goki_gold\goki_gold.h"
#include "goki\goki_black\goki_black.h"
#include "goki\goki_blue\goki_blue.h"
#include "goki\goki_silver\goki_silver.h"
#include "..\ui_manager\ui_component\game_score\game_score.h"
#include "..\effect_manager\effect_manager.h"
#include "..\sound_manager\sound_manager.h"

const float CGokiManager::m_create_interval=1.0f;
const float CGokiManager::m_acceleration_time = 0.009f;



/*
 *  �R���X�g���N�^
 */
CGokiManager::
CGokiManager( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "GokiManager" )
{
}

//������
void CGokiManager::Initialize(void)
{
    //�����^�C�}�[������
    m_CreateTimer.Setup(m_create_interval);

    IGameObject::Initialize();
}

//�X�V
void CGokiManager::Update(void)
{
    //�����^�C�}�[�X�V
    m_CreateTimer.Update();

    if (m_CreateTimer.Finished())
    {
        //�����^�C�}�[�̐������Ԃ������ÂZ������
        m_CreateTimer.SetLimit(m_CreateTimer.GetLimit() - m_acceleration_time);

        m_CreateTimer.Reset();

        //�S�L�u���������_���ɐ���
        Create((GOKI_ID)(rand() % (int)GOKI_ID::MAX));
    }

IGameObject::Update();

if (!aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
        return;

CEffectManager* effect = (CEffectManager*)aqua::FindGameObject("EffectManager");
CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

aqua::CPoint t = aqua::mouse::GetCursorPos();

aqua::CVector2 mpos = aqua::CVector2((float)t.x,(float)t.y);

 for (auto it : m_ChildObjectList)
 {
     IGoki* goki = (IGoki*)it;

     aqua::CVector2 v = goki->GetCenterPosition() - mpos;

     //�}�E�X�J�[�\���ƃS�L�u���̓����蔻��
     if (v.Length() < goki->GetRadius())
     {
         //�S�L�u���ւ̃_���[�W����
         goki->Damege();

         //�q�b�g�G�t�F�N�g����
         if (effect)effect->Create(EFFECT_ID::HIT, mpos);

         //SE�̍Đ�
         if (sound)sound->Play(SOUND_ID::HIT);
     }
 }

}

//�`��
void CGokiManager::Draw(void)
{
    IGameObject::Draw();
}

//���
void CGokiManager::Finalize(void)
{
    IGameObject::Finalize();
}

//����
void CGokiManager::Create(GOKI_ID id)
{
    IGoki* goki = nullptr;

    switch (id)
    {
    case GOKI_ID::BROWN:goki = aqua::CreateGameObject<CGokiBrown>(this);
        break;
    case GOKI_ID::PINK:goki = aqua::CreateGameObject<CGokiPink>(this);
        break;
    case GOKI_ID::GOLD:goki = aqua::CreateGameObject<CGokiGold>(this);
        break;
    case GOKI_ID::BLACK:goki = aqua::CreateGameObject<CGokiBlack>(this);
        break;
    case GOKI_ID::BLUE:goki = aqua::CreateGameObject<CGokiBlue>(this);
        break;
    case GOKI_ID::SILVER:goki = aqua::CreateGameObject<CGokiSilver>(this);
        break;
    default:
        break;

    }

    if (!goki)return;

    goki->Initialize();

    CSoundManager* sound = (CSoundManager*)aqua::FindGameObject("SoundManager");

    if (sound) sound->Play(SOUND_ID::CREATE);
}

void CGokiManager::CheckHitGoki(void)
{
}

