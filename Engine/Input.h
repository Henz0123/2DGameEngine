//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_INPUT_H
#define INC_2DGAMEENGINE_INPUT_H
#include <unordered_map>
#include "../Core/Types.h"



namespace engine
{
    class Input {
    public:
        Input();

        core::Vector2 HandleInput();

        core::Vector2 m_moveDirection = core::Vector2(0.0f, 0.0f);
    private:
        // keybind.keycode, keybind.action
        std::unordered_map<int, core::InputAction> m_keyBinds;
    };
}


#endif //INC_2DGAMEENGINE_INPUT_H
