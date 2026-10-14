//
// Created by isak- on 9/6/2026.
//

#include "Game.h"
#include "../Core/Types.h"

game::Game::Game() : m_entityManager(std::make_unique<EntityManager>())
{
    CreatePlayer();

    auto player = m_entityManager->GetPlayer();
    player->SetSprite("../Assets/megaman-8bit.png");
}

void game::Game::Update(const core::Vector2 &moveDirection, float deltaTime)
{
    auto player = m_entityManager->GetPlayer();
    player->SetMoveDirection(moveDirection);
    m_entityManager->Update(deltaTime);
}

void game::Game::CreatePlayer() const
{
    m_entityManager->CreatePlayer();
}
