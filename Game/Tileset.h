//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_TILESET_H
#define INC_2DGAMEENGINE_TILESET_H
#include <string>
#include <vector>
#include "raylib.h"


namespace game
{
    class Tileset {
    public:
        explicit Tileset(const std::string& filename, int tWidth, int tHeight);
        ~Tileset();

        const Rectangle* GetSourceRect(int tileID) const;
        const Texture2D& GetTexture() const;

    private:
        Texture2D m_texture{};
        std::vector<Rectangle> m_sourceRects;

        void GenerateSourceRects();

        int m_tileWidth;
        int m_tileHeight;

    };
}


#endif //INC_2DGAMEENGINE_TILESET_H
