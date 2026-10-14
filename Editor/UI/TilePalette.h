//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_TILEPALETTE_H
#define INC_2DGAMEENGINE_TILEPALETTE_H
#include <vector>
#include "../../Game/Tileset.h"
#include "../../Core/Shapes.h"

namespace editor::ui
{
    class TilePalette {
    public:
        TilePalette();

        void Update();

        void Draw() const;

        int GetSelectedTileID() const;

    private:
        std::vector<core::PaletteEntry> m_palettes{
                {0, RED, "Floor"},
                {1, BLUE, "Wall"},
                {2, PURPLE, "Pillar"},
                {3, BROWN, "Door"},
                {4, BLACK, "Empty"}
        };
        int m_selectedTileID = 0;
        game::Tileset m_tileset;
    };
}


#endif //INC_2DGAMEENGINE_TILEPALETTE_H
