

#pragma once
#include"../goki.h"

class CGokiBlue
	:public IGoki
{
public:
	//コンストラクタ
	CGokiBlue(aqua::IGameObject* parent);

	//デストラクタ
	~CGokiBlue(void);

	//初期化
	void	Initialize(void);

private:
	static const int	m_width;		//!<幅
	static const int	m_height;		//<!高さ
	static const float	m_radius;		//<!当たり半径
	static const int	m_max_velocity;	//<!最高速度
	static const int	m_min_velocity;	//<!最低速度
	
};