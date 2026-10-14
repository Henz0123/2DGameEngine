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
#include "../Engine/AssetPath.h"

namespace core
{
    struct Shape;
    struct Sprite;
}

namespace game
{
    class Player : public Entity, public Renderable {
    public:
        Player(const core::Transform &tform)
            : Entity(core::EntityType::Player)
        {
            m_transform = tform;
        }
        ;

        ~Player() override
        {
            UnloadTexture(m_sprite.texture);
        }

        void Update(float dt) override;

        void Move(const core::Vector2 &moveDirection, float speed);

        void SetSprite(const char *filename) override
        {
            m_sprite.texture = LoadTexture(
                    engine::AssetPath(filename).string().c_str()
                    );
        }


        const core::Sprite &GetSprite() const override
        {
            return m_sprite;
        }

        const bool &IsFacingLeft() const override
        {
            return m_isMovingLeft;
        }

        void SetMoveDirection(const core::Vector2 &moveDir);

    private:
        core::Sprite m_sprite;
        bool m_isMovingLeft = false;
        core::Vector2 m_moveDir{.x = 0.f, .y = 0.f};
        float m_speed = 300.f;
    };
}


#endif //INC_2DGAMEENGINE_PLAYER_H
