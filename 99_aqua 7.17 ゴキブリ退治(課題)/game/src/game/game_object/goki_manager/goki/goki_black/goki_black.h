
#pragma once
#include"../goki.h"

class CGokiBlack
	:public IGoki
{
public:
	//コンストラクタ
	CGokiBlack(aqua::IGameObject* parent);

	//
	~CGokiBlack(void);

	//
	void	Initialize(void);

	//
	void	Update(void);

	//ダメージ処理の再定義
	void	Damege(void)override;

	


	

	

private:
	static const int	m_width;		//!<幅
	static const int	m_height;		//<!高さ
	static const float	m_radius;		//<!当たり半径
	static const int	m_max_velocity;	//<!最高速度
	static const int	m_min_velocity;	//<!最低速度
	aqua::CTimer		m_timer;		//<!時間制限
	
};