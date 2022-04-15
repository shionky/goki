

#pragma once
#include"../goki.h"

class CGokiSilver
	:public IGoki
{
public:
	//コンストラクタ
	CGokiSilver(aqua::IGameObject* parent);

	//
	~CGokiSilver(void);

	//
	void	Initialize(void);

	//
	void	Update(void);

private:
	static const int	m_width;		//!<幅
	static const int	m_height;		//<!高さ
	static const float	m_radius;		//<!当たり半径
	static const int	m_max_velocity;	//<!最高速度
	static const int	m_min_velocity;	//<!最低速度
	aqua::CTimer		m_timer;		//<!時間
};