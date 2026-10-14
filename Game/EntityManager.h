//
// Created by isak- on 9/8/2026.
//

#ifndef INC_2DGAMEENGINE_ENTITYMANAGER_H
#define INC_2DGAMEENGINE_ENTITYMANAGER_H
#include <vector>
#include <memory>
#include "Entity.h"
#include "Player.h"

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
        void CreatePlayer();
        void CreateEnemy();

        Entity* GetEntity(EntityID id) const;

        const std::vector<std::unique_ptr<Entity>> &GetEntities() const { return m_entities; }

        Player* GetPlayer()
        {
            for (auto& entity : m_entities)
            {
                if (entity->GetID() == m_playerID)
                    return dynamic_cast<Player *>(entity.get());
            }
        }

    private:
        EntityID m_playerID;
    };
}


#endif //INC_2DGAMEENGINE_ENTITYMANAGER_H
