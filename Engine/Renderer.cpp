//
// Created by isak- on 9/6/2026.
//

#include "Renderer.h"


void engine::Renderer::Draw(const game::Game &game)
{
    const auto& entities = game.GetEntityManager()->GetEntities();

    const auto& tilemap = game.GetTileMap();

    BeginDrawing();
    ClearBackground(BLACK);
    if (tilemap)
    {

        for (int tileID : tilemap->GetTiles())
        {

        }
    }

    for (const auto& entity : entities) {
        if (auto* renderable = dynamic_cast<game::Renderable*>(entity.get()))
            DrawSprite(*renderable, entity->GetTransform());
    }

    EndDrawing();
}

void engine::Renderer::DrawSprite(const game::Renderable& renderable, const core::Transform& transform)
{
    const auto &sprite = renderable.GetSprite();

    const auto &direction = renderable.IsFacingLeft();
    Rectangle source{
            0.f,
            0.f,
            direction ? static_cast<float>(sprite.texture.width) : -static_cast<float>(sprite.texture.width),
            static_cast<float>(sprite.texture.height)
    };
    Rectangle destination{
            transform.position.x,
            transform.position.y,
           transform.size.x,
           transform.size.y
    };
    DrawTexturePro(sprite.texture, source, destination, {0.f, 0.f},
                  transform.rotation, WHITE);
}
