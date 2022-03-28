
/*!
 *  @file       ui_component.h
 *  @brief      UIコンポーネント
 *  @author     Kazuya Maruyama
 *  @date       2021/02/13
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include "aqua.h"

/*!
 *  @class      IUIComponent
 *
 *  @brief      UIコンポーネントクラス
 *
 *  @author     Kazuya Maruyama
 *
 *  @date       2021/02/13
 *
 *  @version    1.0
 */
class IUIComponent
    : public aqua::IGameObject
{
public:
    /*!
     *  @brief      コンストラクタ
     *
     *  @param[in]  parent          親オブジェクト
     *  @param[in]  object_name     オブジェクト名
     */
    IUIComponent( aqua::IGameObject* parent, const std::string& object_name );

    /*!
     *  @brief      デストラクタ
     */
    virtual ~IUIComponent( void ) = default;

    /*!
     *  @brief      初期化
     *
     *  @param[in]  position    位置
     */
    virtual void    Initialize( const aqua::CVector2& position );

    /*!
     *  @brief      位置の取得
     *
     *  @return     位置
     */
    aqua::CVector2  GetPosition( void ) const { return m_Position; }

    /*!
     *  @brief      位置の設定
     *
     *  @param[in]  position    位置
     */
    void            SetPosition(const aqua::CVector2& position) { m_Position = position; }

protected:
    aqua::CVector2              m_Position;     //! 表示位置

private:
    /*!
     *  @brief      初期化<br>
     *              使用禁止
     */
    void    Initialize( void );

    static const std::string    m_ui_category;  //! UIカテゴリー
};
