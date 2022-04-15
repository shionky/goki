

#pragma once
#include"../goki.h"

class CGokiGold
	:public IGoki
{
public:
	//�R���X�g���N�^
	CGokiGold(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CGokiGold(void);

	//������
	void	Initialize(void);

//	//�X�V
//	void	Update(void);

private:
	static const int	m_width;		//!<��
	static const int	m_height;		//<!����
	static const float	m_radius;		//<!�����蔼�a
	static const int	m_max_velocity;	//<!�ō����x
	static const int	m_min_velocity;	//<!�Œᑬ�x
	static const int	m_scale	;		//<!�傫��
	aqua::CTimer		m_timer;		//<!����
};
