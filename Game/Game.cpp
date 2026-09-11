//
// Created by isak- on 9/6/2026.
//

#include "Game.h"
#include "../Core/Types.h"

game::Game::Game() : m_entityManager(std::make_unique<EntityManager>())
{
    CreatePlayer();
    m_player->SetSprite(LoadTexture("../Assets/megaman-8bit.png"), {{400, 400}, 0, {40, 40}});
}

void game::Game::Update(const core::Vector2 &moveDirection)
{
   m_entityManager->Update(moveDirection, m_playerID);
}

void game::Game::CreatePlayer()
{
    m_entityManager->CreatePlayer();
    m_playerID = m_entityManager->GetLastID();
    m_player = dynamic_cast<Player *>(m_entityManager->GetEntity(m_playerID));
}
