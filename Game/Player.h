//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_PLAYER_H
#define INC_2DGAMEENGINE_PLAYER_H
#include "../Core/Types.h"
#include <vector>
#include "../Core/Shapes.h"
#include "Entity.h"
#include "Renderable.h"

namespace core
{
    struct Shape;
    struct Sprite;
}

namespace game
{
    class Player : public Entity, public Renderable {
    public:
        Player() : Entity(core::CharacterType::Player)
        {
            m_transform = {{0.f, 0.f}, 0, {0.f, 0.f}};
        }
        ;
        ~Player() override
        {
            UnloadTexture(m_sprite.texture);
        }

        void Update(const core::Vector2 &moveDir, float speed) override;
        void Move(const core::Vector2 &moveDirection, float speed);

        void SetSprite(Texture2D texture, const core::Transform& transform) override
        {
            m_sprite.transform = transform;
            m_sprite.texture = texture;
        }


        const core::Sprite &GetSprite() const override
        {
            return m_sprite;
        }

        const bool &IsFacingLeft() const override
        {
            return m_isMovingLeft;
        }
    private:
        core::Sprite m_sprite;
        bool m_isMovingLeft = false;

    };
}


#endif //INC_2DGAMEENGINE_PLAYER_H
