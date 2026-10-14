//
// Created by isak- on 10/14/2026.
//

#include "Enemy.h"

#include <cmath>

void game::Enemy::Update(float dt)
{
    m_moveDir = CalculateAIPathing();
    Move(m_moveDir, m_speed * dt);
}
void game::Enemy::Move(const core::Vector2 &moveDir, float speed)
{
    auto &[x, y] = m_transform.position;
    x += moveDir.x * speed;
    y += moveDir.y * speed;

    if (moveDir.x < 0)
        m_isMovingLeft = true;
    else if (moveDir.x > 0)
        m_isMovingLeft = false;
}

core::Vector2 game::Enemy::CalculateAIPathing()
{
    auto [x, y] = m_transform.position;
    auto &[xT, yT] = m_target->GetTransform().position;

    x -= xT;
    y -= yT;

    float distance = std::hypot(x, y);

    if (distance <= 0.0001f)
        return {0.f, 0.f};

    return {-x / distance, -y / distance};
}
