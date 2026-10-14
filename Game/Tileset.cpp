//
// Created by isak- on 10/14/2026.
//

#include "Tileset.h"

#include "../Engine/AssetPath.h"

game::Tileset::Tileset(const std::string &filename, int tWidth, int tHeight)
    : m_texture(LoadTexture(engine::AssetPath(filename).string().c_str())),
      m_tileWidth(tWidth),
      m_tileHeight(tHeight)
{
    GenerateSourceRects();
}

game::Tileset::~Tileset()
{
    UnloadTexture(m_texture);
}

const Rectangle *game::Tileset::GetSourceRect(int tileID) const
{
    if (tileID < 0 || static_cast<std::size_t>(tileID) >= m_sourceRects.size())
    {
        return nullptr;
    }

    return &m_sourceRects[tileID];
}

const Texture2D &game::Tileset::GetTexture() const
{
    return m_texture;
}

void game::Tileset::GenerateSourceRects()
{
    int cols = m_texture.width / m_tileWidth;
    int rows = m_texture.height / m_tileHeight;

   for (int i = 0; i < cols * rows; ++i)
   {
       int x = i % cols;
       int y = i / cols;

       m_sourceRects.push_back({
       static_cast<float>(x * m_tileWidth),
           static_cast<float>(y * m_tileHeight),
       static_cast<float>(m_tileWidth),
       static_cast<float>(m_tileHeight)
       });
   }
}
