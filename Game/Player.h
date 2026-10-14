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
            m_transform = {{(GetScreenWidth() / 2.f) - 40.f, (GetScreenHeight() / 2.f) - 40.f}, 0, {80.f, 80.f}};
        }
        ;
        ~Player() override
        {
            UnloadTexture(m_sprite.texture);
        }

        void Update(float dt) override;
        void Move(const core::Vector2 &moveDirection, float speed);

        void SetSprite(const char* filename) override
        {
            m_sprite.texture = LoadTexture(filename);
        }


        const core::Sprite &GetSprite() const override
        {
            return m_sprite;
        }

        const bool &IsFacingLeft() const override
        {
            return m_isMovingLeft;
        }

        void SetMoveDirection(const core::Vector2& moveDir);
    private:
        core::Sprite m_sprite;
        bool m_isMovingLeft = false;
        core::Vector2 m_moveDir{.x = 0.f, .y = 0.f};
        float m_speed = 300.f;
    };
}


#endif //INC_2DGAMEENGINE_PLAYER_H
