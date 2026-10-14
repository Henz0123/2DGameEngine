//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_TILEMAP_H
#define INC_2DGAMEENGINE_TILEMAP_H
#include <memory>
#include <vector>
#include "../Core/Shapes.h"

namespace game
{
    class Tilemap {
    public:
        Tilemap(int width, int height)
            : m_width(width),
              m_height(height),
              m_tiles(width * height, -1)
        {}

        void SetTile(int x, int y, int tileID);

        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

        const core::Vector2 &GetOriginPoint() const;

        const std::vector<int> &GetTiles() const;

    private:
        int m_width;
        int m_height;

        std::vector<int> m_tiles;
        core::Vector2 m_origin{0.f, 0.f};
    };
}


#endif //INC_2DGAMEENGINE_TILEMAP_H
