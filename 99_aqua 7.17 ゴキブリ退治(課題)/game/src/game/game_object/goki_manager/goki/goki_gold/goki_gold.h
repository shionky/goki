

#pragma once
#include"../goki.h"

class CGokiGold
	:public IGoki
{
public:
	//コンストラクタ
	CGokiGold(aqua::IGameObject* parent);

	//デストラクタ
	~CGokiGold(void);

	//初期化
	void	Initialize(void);

//	//更新
//	void	Update(void);

private:
	static const int	m_width;		//!<幅
	static const int	m_height;		//<!高さ
	static const float	m_radius;		//<!当たり半径
	static const int	m_max_velocity;	//<!最高速度
	static const int	m_min_velocity;	//<!最低速度
	static const int	m_scale	;		//<!大きさ
	aqua::CTimer		m_timer;		//<!時間
};
