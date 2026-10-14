//
// Created by isak- on 10/14/2026.
//

#include "TilePalette.h"

#include "raylib.h"

editor::ui::TilePalette::TilePalette()
    : m_tileset("Tilemaps/PNG/walls_floor.png", 16, 16)
{}

void editor::ui::TilePalette::Update()
{
    if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        return;

    constexpr int cellSize = 40;
    constexpr int cols = 5;
    constexpr int spacing = 4;

    Vector2 mouse = GetMousePosition();

    // FORTSETT HER
    for (int i = 0; i < m_palettes.size(); ++i)
    {
        int x = i % cols;
        int y = i / cols;

          Rectangle cell{
            10.f + x * (cellSize + spacing),
            50.f + y * (cellSize + spacing),
            static_cast<float>(cellSize),
            static_cast<float>(cellSize)
        };

        if (CheckCollisionPointRec(mouse, cell))
        {
            m_selectedTileID = m_palettes[i].tileID;
            TraceLog(LOG_INFO, "Valgt fargen: %d", m_palettes[i].color);

            break;
        }
    }
}

void editor::ui::TilePalette::Draw() const
{
    Rectangle rec{0.f, 0.f, 400, static_cast<float>(GetScreenHeight())};
    DrawRectangleRec(rec, DARKGRAY);
/*
    constexpr int cols = 5;
    constexpr int tileSize = 32;
    constexpr int spacing = 4;

    for (int id = 0; id < 25; ++id)
    {
        const Rectangle* source = m_tileset.GetSourceRect(id);

        if (!source)
            continue;

        int x = id % cols;
        int y = id / cols;

        Rectangle destination{
            8.0f + x * (tileSize + spacing),
            60.f + y * (tileSize + spacing),
            static_cast<float>(tileSize),
            static_cast<float>(tileSize),
        };

        DrawTexturePro(m_tileset.GetTexture(), *source, destination, {0.f, 0.f}, 0, WHITE);
    }*/


    //Temporary
    constexpr int cellsize = 40;
    constexpr int cols = 5;
    constexpr int spacing = 6;

    for (int id = 0; id < m_palettes.size(); ++id)
    {
        int x = id % cols;
        int y = id / cols;

        Rectangle cell{
            10.f + x * (cellsize + spacing),
            50.f + y * (cellsize + spacing),
            static_cast<float>(cellsize),
            static_cast<float>(cellsize)
        };
        DrawRectangleRec(cell, m_palettes[id].color);
        DrawRectangleLinesEx(cell, 2.0f, WHITE);

        if (m_selectedTileID == m_palettes[id].tileID)
        {
            DrawRectangleLinesEx(cell, 4.0f, YELLOW);
        }

        DrawText(m_palettes[id].label,
                 static_cast<int>(cell.x),
                 static_cast<int>(cell.y + cell.height + 2),
                 10,
                 WHITE);

    }
}



int editor::ui::TilePalette::GetSelectedTileID() const
{
    return 0;
}
