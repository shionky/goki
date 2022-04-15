#pragma once
#include "../effect.h"
#include"aqua.h"
class CEhitEffect
	:public IEffect
{
public:
	CEhitEffect(IGameObject* parent);
	~CEhitEffect() = default;

	//初期化
	void Initialize(const aqua::CVector2& position);
	
	//更新
	void Update(void);
	
	//描画
	void Draw(void);
	
	//解放
	void Finalize(void);
private:

	// エフェクト
	aqua::CEffect2D m_Effect;
};