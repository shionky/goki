#include "goki_Black.h"
#include"../../goki_manager.h"
#include"../../../camera_manager/camera_manager.h"
#include"../../../effect_manager/effect_manager.h"
#include"../../../ui_manager/ui_component/game_score/game_score.h"

const int CGokiBlack::m_width = 128;
const int CGokiBlack::m_height = 128;
const float CGokiBlack::m_radius = (float)m_width / 3.0f;
const int CGokiBlack::m_max_velocity = 200;
const int CGokiBlack::m_min_velocity = 100;

//コンストラクタ
CGokiBlack::CGokiBlack(aqua::IGameObject* parent)
	:IGoki(parent, "GokiBlack")
{
}

//デストラクタ
CGokiBlack::~CGokiBlack(void)
{
}

//初期化
void CGokiBlack::Initialize(void)
{
	m_Width = m_width;
	m_Height = m_height;
	m_Radius = m_radius;

	m_Position.x = (float)aqua::Rand(aqua::GetWindowWidth() - m_Width);
	m_Position.y = (float)aqua::Rand(aqua::GetWindowHeight() - m_Height);

	m_AnimeSprite.Create("data/goki_black.ass");

	m_AnimeSprite.anchor.x = (float)(m_Width / 2.0f);
	m_AnimeSprite.anchor.y = (float)(m_Height / 2.0f);

	float dir = aqua::DegToRad((float)aqua::Rand(360));

	float speed = (float)aqua::Rand(m_max_velocity - m_min_velocity) + m_min_velocity;

	m_Velocity.x = cos(dir) * speed;
	m_Velocity.y = sin(dir) * speed;

	m_timer.Setup(10.0f);

	m_Score = -1;

	m_AnimeSprite.scale;
}

//更新
void CGokiBlack::Update(void)
{
	//ライフが０になったら分裂する
	if (m_Life <= 0)
	{
		CGokiBlack* goki1 = aqua::CreateGameObject<CGokiBlack>((CGokiManager*)aqua::FindGameObject("GokiManager"));
		goki1->Initialize();
		goki1->Setposition(m_Position);


		CGokiBlack* goki2 = aqua::CreateGameObject<CGokiBlack>((CGokiManager*)aqua::FindGameObject("GokiManager"));
		goki2->Initialize();
		goki2->Setposition(m_Position);

		DeleteObject();
	}

	//時間経過で消える
	m_timer.Update();
	if (m_timer.Finished())
	{
		DeleteObject();
	}

	IGoki::Update();
}


//ダメージ処理
void CGokiBlack::Damege(void)
{

	if (--m_Life <= 0)
	{
		CGameScore* score = (CGameScore*)aqua::FindGameObject("GameScore");
		if (score)score->Add(m_Score);

		CEffectManager* effect = (CEffectManager*)aqua::FindGameObject("EffectManager");

		if (effect)effect->Create(EFFECT_ID::DEAD, GetCenterPosition());

		CCameraManager* camera = (CCameraManager*)aqua::FindGameObject("CamearManager");

		if (camera)camera->Shake();


		
	}
}


