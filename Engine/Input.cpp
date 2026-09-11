//
// Created by isak- on 9/6/2026.
//

#include "Input.h"
#include "raylib.h"
#include <algorithm>


engine::Input::Input()
{
    m_keyBinds = {
            {KEY_W, core::InputAction::MoveUp},
            {KEY_S, core::InputAction::MoveDown},
            {KEY_A, core::InputAction::MoveLeft},
            {KEY_D, core::InputAction::MoveRight}
    };
}

core::Vector2 engine::Input::HandleInput()
{
    m_moveDirection = core::Vector2(0.0f, 0.0f);
    for (const auto &[keyCode, action]: m_keyBinds) {
        if (!IsKeyDown(keyCode))
            continue;


        if (action == core::InputAction::MoveUp)
            m_moveDirection.y -= 1;
        if (action == core::InputAction::MoveDown)
            m_moveDirection.y += 1;
        if (action == core::InputAction::MoveLeft)
            m_moveDirection.x -= 1;
        if (action == core::InputAction::MoveRight)
            m_moveDirection.x += 1;


    }

    return core::Vector2(
        m_moveDirection.x = std::clamp(m_moveDirection.x, -1.0f, 1.0f),
        m_moveDirection.y = std::clamp(m_moveDirection.y, -1.0f, 1.0f)
    );
};
