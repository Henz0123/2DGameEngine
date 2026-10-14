//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_OBJECTS_H
#define INC_2DGAMEENGINE_OBJECTS_H
#include "raylib.h"
#include "Types.h"

namespace core
{

    enum class RenderType {
        Rectangle,
        Triangle,
        Circle,
    };

    struct Shape {
        RenderType renderType;
    };

    struct Sprite {
        Texture2D texture = {};
    };

    struct PaletteEntry {
        int tileID;
        Color color;
        const char* label;
    };
}

#endif //INC_2DGAMEENGINE_OBJECTS_H
