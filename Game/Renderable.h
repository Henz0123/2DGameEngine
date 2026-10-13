//
// Created by isak- on 9/8/2026.
//

#ifndef INC_2DGAMEENGINE_RENDERABLE_H
#define INC_2DGAMEENGINE_RENDERABLE_H
#include "../Core/Shapes.h"

namespace game
{
    class Renderable {
    public:
        virtual ~Renderable() = default;
        virtual const core::Sprite& GetSprite() const = 0;
        virtual void SetSprite(const char* filename) = 0;
        virtual const bool &IsFacingLeft() const = 0;
    };
}

#endif //INC_2DGAMEENGINE_RENDERABLE_H
