//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_ENEMY_H
#define INC_2DGAMEENGINE_ENEMY_H
#include "Entity.h"

#include "Renderable.h"
#include "../Engine/AssetPath.h"

namespace game
{
    class Enemy : public Entity, public Renderable {
    public:
        Enemy(const core::Transform &tform, const char *filename)
            : Entity(core::EntityType::Enemy)
        {
            m_transform = tform;
            SetSprite(filename);
        }

        ~Enemy() override
        {
            UnloadTexture(m_sprite.texture);
        }

        void Update(float dt) override;

        void Move(const core::Vector2 &moveDir, float speed);

        void SetSprite(const char *filename) override
        {
            m_sprite.texture = LoadTexture(
                    engine::AssetPath("Characters/pokemon-16bit-fixed.png").string().c_str()
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

        void SetTarget(const Entity *player)
        {
            m_target = player;
        }

        core::Vector2 CalculateAIPathing();

    private:
        core::Sprite m_sprite;
        bool m_isMovingLeft = false;
        core::Vector2 m_moveDir{.x = 0.f, .y = 0.f};
        float m_speed = 200.f;

        const Entity *m_target = nullptr;
    };
}


#endif //INC_2DGAMEENGINE_ENEMY_H
