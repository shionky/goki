
/*!
 *  @file       effect_manager.cpp
 *  @brief      エフェクト管理
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "effect_manager.h"
#include "effect\Ehit_effect\ehit_effect.h"
#include "effect\hit_effect\hit_effect.h"
#include "effect\dead_effect\dead_effect.h"

/*
 *  コンストラクタ
 */
CEffectManager::
CEffectManager( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "EffectManager" )
{
}

/*
 *  生成
 */
void
CEffectManager::
Create( EFFECT_ID id, const aqua::CVector2& position )
{
    IEffect* effect = nullptr;

    switch( id )
    {
    /*case EFFECT_ID::HIT:    effect = aqua::CreateGameObject<CHitEffect>(this);      break;*/
    case EFFECT_ID::HIT:    effect = aqua::CreateGameObject<CEhitEffect>(this);      break;
    case EFFECT_ID::DEAD:   effect = aqua::CreateGameObject<CDeadEffect>(this);     break;
    }

    if( effect )
        effect->Initialize( position );
}
