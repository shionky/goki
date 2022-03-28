
/*!
 *  @file       scene_id.h
 *  @brief      シーンID
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

/*!
 *  @brief      シーンID
 */
enum class SCENE_ID
{
    DUMMY,      //! ダミーID
    SPLASH,     //! スプラッシュシーン
    TITLE,      //! タイトルシーン
    GAMEMAIN,   //! ゲームメインシーン
    MENU,       //! メニューシーン
    RESULT,     //! リザルトシーン
};
