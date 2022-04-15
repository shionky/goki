#include "ehit_effect.h"


CEhitEffect::CEhitEffect(IGameObject* parent):IEffect(parent,"EHitEffet")
{
}

//‰Šú‰»
void CEhitEffect::Initialize(const aqua::CVector2& position)
{
	m_Effect.Create("data/effect/gokihit.efkefc.efk");
	m_Effect.position = position;
	m_Effect.Play();
	
}

//XV
void CEhitEffect::Update(void)
{
	m_Effect.Update();
}


//•`‰æ
void CEhitEffect::Draw(void)
{
	m_Effect.Draw();
}

//‰ğ•ú
void CEhitEffect::Finalize(void)
{
	m_Effect.Delete();
}
