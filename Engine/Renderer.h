//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_RENDERER_H
#define INC_2DGAMEENGINE_RENDERER_H
#include "raylib.h"

#include "../Game/Game.h"
#include "../Game/Player.h"
#include "../Editor/Editor.h"

namespace engine
{
    class Renderer {
    public:
        Renderer() = default;

        void Draw(const game::Game *game, const editor::Editor &editor);

    private:
        void DrawSprite(const game::Renderable &renderable, const core::Transform &transform);

        void DrawTilemap(
                const game::Tilemap &tilemap,
                const game::Tileset &tileset
                );
    };
}


#endif //INC_2DGAMEENGINE_RENDERER_H
