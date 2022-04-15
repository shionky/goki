

#pragma once
#include"../goki.h"

class CGokiSilver
	:public IGoki
{
public:
	//�R���X�g���N�^
	CGokiSilver(aqua::IGameObject* parent);

	//
	~CGokiSilver(void);

	//
	void	Initialize(void);

	//
	void	Update(void);

private:
	static const int	m_width;		//!<��
	static const int	m_height;		//<!����
	static const float	m_radius;		//<!�����蔼�a
	static const int	m_max_velocity;	//<!�ō����x
	static const int	m_min_velocity;	//<!�Œᑬ�x
	aqua::CTimer		m_timer;		//<!����
};