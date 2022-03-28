#pragma once
#include "../effect.h"
#include"aqua.h"
class CEhitEffect
	:public IEffect
{
public:
	CEhitEffect(IGameObject* parent);
	~CEhitEffect() = default;

	void Initialize(const aqua::CVector2& position);
	void Update(void);
	void Draw(void);
	void Finalize(void);
private:

	// エフェクト
	aqua::CEffect2D m_Effect;
};