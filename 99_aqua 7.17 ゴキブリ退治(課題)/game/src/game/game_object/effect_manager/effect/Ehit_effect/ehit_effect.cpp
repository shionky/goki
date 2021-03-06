#include "ehit_effect.h"


CEhitEffect::CEhitEffect(IGameObject* parent):IEffect(parent,"EHitEffet")
{
}

//初期化
void CEhitEffect::Initialize(const aqua::CVector2& position)
{
	m_Effect.Create("data/effect/gokihit.efkefc.efk");
	m_Effect.position = position;
	m_Effect.Play();
	
}

//更新
void CEhitEffect::Update(void)
{
	m_Effect.Update();
}


//描画
void CEhitEffect::Draw(void)
{
	m_Effect.Draw();
}

//解放
void CEhitEffect::Finalize(void)
{
	m_Effect.Delete();
}
