//
// Created by isak- on 10/14/2026.
//

#include "Tilemap.h"

const std::vector<int>& game::Tilemap::GetTiles() const
{
    return m_tiles;
}

const core::Vector2 & game::Tilemap::GetOriginPoint() const
{
    return m_origin;
}



void game::Tilemap::SetTile(int x, int y, int tileID)
{
    m_tiles[y * m_width + x] = tileID;
}
