//
// Created by isak- on 9/8/2026.
//

#ifndef INC_2DGAMEENGINE_ENTITYMANAGER_H
#define INC_2DGAMEENGINE_ENTITYMANAGER_H
#include <vector>
#include <memory>
#include "Entity.h"
#include "Player.h"
#include <optional>
#include "Enemy.h"

namespace game
{
    class EntityManager {

    protected:
        std::vector<std::unique_ptr<Entity>> m_entities;

    public:
        void Update(float dt);

        int GetLastID() const
        {

            Entity *it = m_entities.back().get();
            return it->GetID();
        }
        void CreatePlayer(const core::Transform &tform);
        void CreateEnemy(const core::Transform &tform, const char* filename);

        Entity* GetEntity(EntityID id) const;

        const std::vector<std::unique_ptr<Entity>> &GetEntities() const { return m_entities; }

        Player* GetPlayer()
        {
            if (!m_playerID)
                return nullptr;

            for (auto& entity : m_entities)
            {
                if (entity->GetID() == m_playerID)
                    return dynamic_cast<Player *>(entity.get());
            }

            return nullptr;
        }

    private:
        std::optional<EntityID> m_playerID;
    };
}


#endif //INC_2DGAMEENGINE_ENTITYMANAGER_H
