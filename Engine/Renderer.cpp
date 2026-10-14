//
// Created by isak- on 9/6/2026.
//

#include "Renderer.h"
#include "../Core/Constants.h"

void engine::Renderer::Draw(const game::Game &game)
{
    const auto& entities = game.GetEntityManager()->GetEntities();

    const auto& tilemap = game.GetTileMap();
    const auto& tileset = game.GetTileset();

    BeginDrawing();
    ClearBackground(BLACK);
    if (tilemap && tileset)
    {
        DrawTilemap(*tilemap, *tileset);
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

void engine::Renderer::DrawTilemap(const game::Tilemap &tilemap, const game::Tileset &tileset)
{
    const auto& tiles = tilemap.GetTiles();
    const auto& origin = tilemap.GetOriginPoint();

    const int width = tilemap.GetWidth();
    const float drawSize = core::TILE_DRAW_SIZE;

    for (std::size_t i = 0; i < tiles.size(); ++i)
    {
        int tileID = tiles[i];
        const Rectangle* source = tileset.GetSourceRect(tileID);

        if (!source)
            continue;

        int x = static_cast<int>(i % width);
        int y = static_cast<int>(i / width);

        Rectangle destination{
            origin.x + x * drawSize,
            origin.y + y * drawSize,
            drawSize,
            drawSize
        };

        DrawTexturePro(
            tileset.GetTexture(),
            *source,
            destination,
            {0.f, 0.f},
            0.f,
            WHITE
        );
    }
}
