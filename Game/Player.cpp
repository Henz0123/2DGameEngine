//
// Created by isak- on 9/6/2026.
//

#include "Player.h"


void game::Player::Update(float dt)
{
   Move(m_moveDir, m_speed * dt);
}

void game::Player::Move(const core::Vector2 &moveDirection, float speed)
{
    auto &[x, y] = m_transform.position;
    x += moveDirection.x * speed;
    y += moveDirection.y * speed;

    if (moveDirection.x < 0)
        m_isMovingLeft = true;
    else if (moveDirection.x > 0)
        m_isMovingLeft = false;
}

void game::Player::SetMoveDirection(const core::Vector2 &moveDir)
{
    m_moveDir = moveDir;
}
