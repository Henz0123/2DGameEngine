//
// Created by isak- on 9/6/2026.
//

#include "Game.h"
#include "../Core/Types.h"

game::Game::Game()
    : m_entityManager(std::make_unique<EntityManager>())
{
    CreatePlayer();

    auto player = m_entityManager->GetPlayer();
    player->SetSprite("../Assets/megaman-8bit.png");

    CreateEnemy();
}

void game::Game::Update(const core::Vector2 &moveDirection, float deltaTime)
{
    auto player = m_entityManager->GetPlayer();
    player->SetMoveDirection(moveDirection);
    m_entityManager->Update(deltaTime);
}

void game::Game::CreatePlayer() const
{
    core::Transform tform = {{(GetScreenWidth() / 2.f) - 40.f, (GetScreenHeight() / 2.f) - 40.f}, 0.f, {80.f, 80.f}};
    m_entityManager->CreatePlayer(tform);
}

void game::Game::CreateEnemy() const
{
    core::Transform tform = {{20.f, 20.f}, 0.f, {80.f, 80.f}};
    Enemy &enemy = m_entityManager->CreateEnemy(tform, "../Assets/pokemon-16bit-fixed.png");

    enemy.SetTarget(m_entityManager->GetPlayer());
}
