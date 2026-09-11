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
        virtual void SetSprite(Texture2D texture, const core::Transform& transform) = 0;
        virtual const bool &IsFacingLeft() const = 0;
    };
}

#endif //INC_2DGAMEENGINE_RENDERABLE_H
