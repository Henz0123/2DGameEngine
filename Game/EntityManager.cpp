//
// Created by isak- on 9/8/2026.
//

#include "EntityManager.h"

#include "Game.h"

void game::EntityManager::Update(float dt)
{

    for (auto & entity : m_entities) {
        if (entity->GetID() == m_playerID) {
            entity->Update(dt);
        }
    }
}

void game::EntityManager::CreatePlayer()
{

    m_entities.push_back(std::make_unique<Player>());
    m_playerID = GetLastID();
}
void game::EntityManager::CreateEnemy() {}

game::Entity * game::EntityManager::GetEntity(EntityID id) const
{
    for (auto & entity : m_entities) {
        if (entity->GetID() == id)
            return entity.get();
    }
    return nullptr;
}
