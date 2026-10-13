//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_RENDERER_H
#define INC_2DGAMEENGINE_RENDERER_H
#include "raylib.h"

#include "../Game/Game.h"
#include "../Game/Player.h"

namespace engine
{
    class Renderer {
    public:
        Renderer() = default;
        void Draw(const game::Game& game);

    private:
        void DrawSprite(const game::Renderable& renderable, const core::Transform& transform);
    };
}


#endif //INC_2DGAMEENGINE_RENDERER_H
