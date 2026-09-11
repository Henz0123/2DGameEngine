//
// Created by isak- on 9/8/2026.
//

#include "EntityManager.h"
void game::EntityManager::Update(const core::Vector2 &moveDir, EntityID playerID)
{
    for (auto & entity : m_entities) {
        if (entity->GetID() == playerID) {
            entity->Update(moveDir, 5);
        }
    }
}

void game::EntityManager::CreatePlayer()
{
    m_entities.push_back(std::make_unique<Player>());
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
