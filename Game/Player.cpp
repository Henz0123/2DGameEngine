//
// Created by isak- on 9/6/2026.
//

#include "Player.h"


void game::Player::Update(const core::Vector2 &moveDir, float speed)
{
   Move(moveDir, speed);
}

void game::Player::Move(const core::Vector2 &moveDirection, float speed)
{
    auto &[x, y] = m_sprite.transform.position;
    x += moveDirection.x * speed;
    y += moveDirection.y * speed;

    if (moveDirection.x < 0)
        m_isMovingLeft = true;
    else if (moveDirection.x > 0)
        m_isMovingLeft = false;
}

