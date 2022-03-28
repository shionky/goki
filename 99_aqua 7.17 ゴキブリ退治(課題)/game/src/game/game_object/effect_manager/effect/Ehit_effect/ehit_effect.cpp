#include "ehit_effect.h"


CEhitEffect::CEhitEffect(IGameObject* parent):IEffect(parent,"EHitEffet")
{
}

void CEhitEffect::Initialize(const aqua::CVector2& position)
{
	m_Effect.Create("data/effect/gokihit.efkefc.efk");
	m_Effect.position = position;
	m_Effect.Play();
	
}

void CEhitEffect::Update(void)
{
	m_Effect.Update();
}

void CEhitEffect::Draw(void)
{
	m_Effect.Draw();
}

void CEhitEffect::Finalize(void)
{
	m_Effect.Delete();
}
