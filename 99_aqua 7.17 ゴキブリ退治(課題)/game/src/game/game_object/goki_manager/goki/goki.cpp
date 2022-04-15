
/*!
 *  @file       goki.cpp
 *  @brief      ゴキブリ
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "goki.h"
#include "..\..\effect_manager\effect_manager.h"
#include "..\..\camera_manager\camera_manager.h"
#include "..\..\ui_manager\ui_component\game_score\game_score.h"

const std::string IGoki::m_goki_category = "Goki";
const int IGoki::m_default_life = 1;
const int IGoki::m_default_score = 1;

/*
 *  コンストラクタ
 */
IGoki::
IGoki( aqua::IGameObject* parent, const std::string& name )
    : aqua::IGameObject( parent, name, "Goki" )
    ,m_Width(0)
    ,m_Height(0)
    ,m_Radius(0)
    ,m_Velocity(aqua::CVector2::ZERO)
    ,m_Life(m_default_life)
    ,m_Score(m_default_score)
{
}

/*
*   初期化
*/
void IGoki::Initialize(void)
{
    m_Position = aqua::CVector2::ZERO;
    m_Velocity = aqua::CVector2::ZERO;
}

/*
*   更新
*/
void IGoki::Update(void)
{
    m_Position += m_Velocity * aqua::GetDeltaTime();

    CCameraManager* camera =
        (CCameraManager*)aqua::FindGameObject("CameraManager");

    m_AnimeSprite.position = m_Position - camera->GetPosition();

    CheckHitWall();

    m_AnimeSprite.rotation = atan2(m_Velocity.y, m_Velocity.x) + aqua::DegToRad(90.0f);

    m_AnimeSprite.Update();
}

/*
*   描画
*/
void IGoki::Draw(void)
{
    m_AnimeSprite.Draw();
}

/*
*   解放
*/
void IGoki::Finalize(void)
{
    m_AnimeSprite.Delete();
}

/*
*   ダメージ
*/
void IGoki::Damege(void)
{
    //
    if (--m_Life <= 0)
    {
        CGameScore* score = (CGameScore*)aqua::FindGameObject("GameScore");
        if (score)score->Add(m_Score);

        CEffectManager* effect = (CEffectManager*)aqua::FindGameObject("EffectManager");

        if (effect)effect->Create(EFFECT_ID::DEAD, GetCenterPosition());

        CCameraManager* camera = (CCameraManager*)aqua::FindGameObject("CamearManager");

        if (camera)camera->Shake();

        DeleteObject();
    }
}

//幅取得
int IGoki::GetWidth(void)
{
    return m_Width;
}

//高さ取得
int IGoki::GetHeight(void)
{
    return m_Height;
}

//半径取得
float IGoki::GetRadius(void)
{
    return m_Radius;
}

//中心位置取得
aqua::CVector2 IGoki::GetCenterPosition(void)
{
    return m_Position + m_AnimeSprite.anchor;
}

//ライフ取得
int IGoki::GetLife(void)
{
    return m_Life;
}

//座標情報取得
void IGoki::Setposition(aqua::CVector2 pos)
{
    m_Position = pos;
}


//壁判定取得
void IGoki::CheckHitWall(void)
{
    const float width = (float)(aqua::GetWindowWidth() - m_Width);
    const float height = (float)(aqua::GetWindowHeight() - m_Height);
    if (m_Position.x < 0.0f)
    {
        m_Position.x = 0.0f - m_Position.x;
        m_Velocity.x *= -1.0f;
    }
    if (m_Position.x > width)
    {
        m_Position.x = width - (m_Position.x - width);
        m_Velocity.x *= -1.0f;
    }
    if (m_Position.y < 0.0f)
        
    {
        m_Position.y = 0.0f - m_Position.y;
        m_Velocity.y *= -1.0f;
    }
    if (m_Position.y > height)
    {
        m_Position.y = height - (m_Position.y - height);
        m_Velocity.y *= -1.0f;
    }
}
