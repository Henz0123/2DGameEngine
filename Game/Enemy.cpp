//
// Created by isak- on 10/14/2026.
//

#include "Enemy.h"
void game::Enemy::Update(float dt)
{
    Move(m_moveDir, m_speed * dt);
}
void game::Enemy::Move(const core::Vector2 &moveDir, float speed)
{

    auto &[x, y] = m_transform.position;

}
