
#pragma once
#include"../goki.h"

class CGokiBlack
	:public IGoki
{
public:
	//�R���X�g���N�^
	CGokiBlack(aqua::IGameObject* parent);

	//
	~CGokiBlack(void);

	//
	void	Initialize(void);

	//
	void	Update(void);

	//�_���[�W�����̍Ē�`
	void	Damege(void)override;

	


	

	

private:
	static const int	m_width;		//!<��
	static const int	m_height;		//<!����
	static const float	m_radius;		//<!�����蔼�a
	static const int	m_max_velocity;	//<!�ō����x
	static const int	m_min_velocity;	//<!�Œᑬ�x
	aqua::CTimer		m_timer;		//<!���Ԑ���
	
};