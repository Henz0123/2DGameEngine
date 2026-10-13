//
// Created by isak- on 9/6/2026.
//

#include "Game.h"
#include "../Core/Types.h"

game::Game::Game() : m_entityManager(std::make_unique<EntityManager>())
{
    CreatePlayer();
    m_player->SetSprite("../Assets/megaman-8bit.png");
}

void game::Game::Update(const core::Vector2 &moveDirection, float deltaTime)
{
    m_player->SetMoveDirection(moveDirection);
   m_entityManager->Update(deltaTime);
}

void game::Game::CreatePlayer()
{
    m_entityManager->CreatePlayer();
    EntityID playerID = m_entityManager->GetPlayerID();
    m_player = dynamic_cast<Player *>(m_entityManager->GetEntity(playerID));
}
