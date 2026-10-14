//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_GAME_H
#define INC_2DGAMEENGINE_GAME_H
#include "../Core/Types.h"
#include "EntityManager.h"
#include "Tilemap.h"
#include "Tileset.h"

namespace game
{
    class Game {
    public:
        Game();

        const EntityManager *GetEntityManager() const
        {
            return m_entityManager.get();
        }

        const Tilemap *GetTileMap() const
        {
            return m_tilemap.get();
        }
        const Tileset* GetTileset() const
        {
            return m_tileset.get();
        }

        void Update(const core::Vector2 &moveDirection, float deltaTime);

        void CreatePlayer() const;

        void CreateEnemy() const;

        void FillTiles();

    private:
        std::unique_ptr<EntityManager> m_entityManager;
        std::unique_ptr<Tilemap> m_tilemap;

        std::unique_ptr<Tileset> m_tileset;
    };
}


#endif //INC_2DGAMEENGINE_GAME_H
