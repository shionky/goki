#include "goki_Silver.h"
#include"../../goki_manager.h"
#include"../../../ui_manager/ui_component/game_score/game_score.h"

const int CGokiSilver::m_width = 128;
const int CGokiSilver::m_height = 128;
const float CGokiSilver::m_radius = (float)m_width / 3.0f;
const int CGokiSilver::m_max_velocity = 200;
const int CGokiSilver::m_min_velocity = 100;

//コンストラクタ
CGokiSilver::CGokiSilver(aqua::IGameObject* parent)
	:IGoki(parent, "GokiSilver")
{
}

//デストラクタ
CGokiSilver::~CGokiSilver(void)
{
}

//初期化
void CGokiSilver::Initialize(void)
{
	m_Width = m_width;
	m_Height = m_height;
	m_Radius = m_radius;

	m_Position.x = (float)aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = (float)aqua::Rand(aqua::GetWindowHeight() - m_Height);

	m_AnimeSprite.Create("data/goki_silver.ass");

	m_AnimeSprite.anchor.x = (float)(m_Width / 2.0f);
	m_AnimeSprite.anchor.y = (float)(m_Height / 2.0f);

	float dir = aqua::DegToRad((float)aqua::Rand(360));

	float speed = (float)aqua::Rand(m_max_velocity - m_min_velocity) + m_min_velocity;

	m_Velocity.x = cos(dir) * speed;
	m_Velocity.y = sin(dir) * speed;

	m_timer.Setup(5.0);

}

void CGokiSilver::Update(void)
{
	//時間経過で薄くなる
	m_timer.Update();
	if (m_timer.Finished())
	{
	 m_AnimeSprite.color.alpha = 45;

	 m_Score = 3;
	}
	IGoki::Update();

}
