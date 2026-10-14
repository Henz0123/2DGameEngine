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
void game::EntityManager::CreateEnemy(const core::Transform &tform, const char* filename)
{
    m_entities.push_back(std::make_unique<Enemy>(tform, filename));

}

game::Entity * game::EntityManager::GetEntity(EntityID id) const
{
    for (auto & entity : m_entities) {
        if (entity->GetID() == id)
            return entity.get();
    }
    return nullptr;
}
