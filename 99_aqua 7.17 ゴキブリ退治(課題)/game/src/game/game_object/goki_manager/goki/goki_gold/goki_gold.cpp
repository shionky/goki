#include "goki_gold.h"

const int CGokiGold::m_width = 128;
const int CGokiGold::m_height = 128;
const float CGokiGold::m_radius = (float)m_width / 3.0f;
const int CGokiGold::m_max_velocity = 200;
const int CGokiGold::m_min_velocity = 100;

//コンストラクタ
CGokiGold::CGokiGold(aqua::IGameObject* parent)
	:IGoki(parent, "GokiGold")
{
}

//デストラクタ
CGokiGold::~CGokiGold(void)
{
}

//初期化
void CGokiGold::Initialize(void)
{
	m_Width = m_width;
	m_Height = m_height;
	m_Radius = m_radius;

	m_Position.x = (float)aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = (float)aqua::Rand(aqua::GetWindowHeight() - m_Height);

	m_AnimeSprite.Create("data/goki_gold.ass");

	m_AnimeSprite.anchor.x = (float)(m_Width / 2.0f);
	m_AnimeSprite.anchor.y = (float)(m_Height / 2.0f);

	float dir = aqua::DegToRad((float)aqua::Rand(360));

	float speed = (float)aqua::Rand(m_max_velocity - m_min_velocity) + m_min_velocity;

	m_Velocity.x = cos(dir) * speed;
	m_Velocity.y = sin(dir) * speed;


}
