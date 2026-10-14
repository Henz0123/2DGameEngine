//
// Created by isak- on 9/8/2026.
//

#include "EntityManager.h"




void game::EntityManager::Update(float dt)
{

    for (auto & entity : m_entities) {
            entity->Update(dt);
    }
}

void game::EntityManager::CreatePlayer(const core::Transform &tform)
{

    m_entities.push_back(std::make_unique<Player>(tform));
    m_playerID = GetLastID();
}
game::Enemy &game::EntityManager::CreateEnemy(const core::Transform &tform, const char* filename)
{
    auto enemy = std::make_unique<Enemy>(tform, filename);
    Enemy& ref = *enemy;

   m_entities.push_back(std::move(enemy));

    return ref;
}

game::Entity *game::EntityManager::GetEntity(EntityID id) const
{
    for (auto & entity : m_entities) {
        if (entity->GetID() == id)
            return entity.get();
    }
    return nullptr;
}
