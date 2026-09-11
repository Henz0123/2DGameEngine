//
// Created by isak- on 9/6/2026.
//

#include "Renderer.h"


void engine::Renderer::Draw(const game::Game &game)
{
    const auto& entities = game.GetEntityManager()->GetEntities();

    BeginDrawing();
    ClearBackground(BLACK);
    for (const auto& entity : entities) {
        if (auto* renderable = dynamic_cast<game::Renderable*>(entity.get()))
            DrawPlayer(*renderable);
    }

    EndDrawing();
}

void engine::Renderer::DrawPlayer(const game::Renderable &entity)
{
    const auto &sprite = entity.GetSprite();
    const auto &direction = entity.IsFacingLeft();
    Rectangle source{
            0.f,
            0.f,
            direction ? static_cast<float>(sprite.texture.width) : -static_cast<float>(sprite.texture.width),
            static_cast<float>(sprite.texture.height)
    };
    Rectangle destination{
            sprite.transform.position.x,
            sprite.transform.position.y,
            sprite.transform.size.x,
            sprite.transform.size.y
    };
    DrawTexturePro(sprite.texture, source, destination, {0.f, 0.f},
                   sprite.transform.rotation, WHITE);
}
