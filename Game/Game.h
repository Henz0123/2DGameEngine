//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_GAME_H
#define INC_2DGAMEENGINE_GAME_H
#include "Player.h"
#include "../Core/Types.h"
#include "EntityManager.h"

namespace game
{
    class Game {
    public:
        Game();

        const EntityManager* GetEntityManager() const
        {
            return m_entityManager.get();
        }

        void Update(const core::Vector2 &moveDirection, float deltaTime);

        void CreatePlayer();


    private:
        Player* m_player;
        std::unique_ptr<EntityManager> m_entityManager;

    };
}


#endif //INC_2DGAMEENGINE_GAME_H
