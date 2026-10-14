//
// Created by isak- on 9/6/2026.
//

#include "Game.h"
#include "../Core/Types.h"
#include "../Engine/AssetPath.h"

game::Game::Game()
    : m_entityManager(std::make_unique<EntityManager>()), m_tilemap(std::make_unique<Tilemap>(208, 368))
{
    CreatePlayer();

    auto player = m_entityManager->GetPlayer();

    player->SetSprite("Characters/megaman-8bit.png");

    m_tileset = LoadTexture(engine::AssetPath("Tilemaps/PNG/walls_floor.png").string().c_str());
    FillTiles();
}

void game::Game::Update(const core::Vector2 &moveDirection, float deltaTime)
{


    auto player = m_entityManager->GetPlayer();
    player->SetMoveDirection(moveDirection);
    m_entityManager->Update(deltaTime);
}

void game::Game::CreatePlayer() const
{
    core::Transform tform = {{(GetScreenWidth() / 2.f) - 40.f, (GetScreenHeight() / 2.f) - 40.f}, 0.f, {80.f, 80.f}};
    m_entityManager->CreatePlayer(tform);
}

void game::Game::CreateEnemy() const
{
    core::Transform tform = {{20.f, 20.f}, 0.f, {80.f, 80.f}};
    Enemy &enemy = m_entityManager->CreateEnemy(tform, "../Assets/pokemon-16bit-fixed.png");

    enemy.SetTarget(m_entityManager->GetPlayer());

}

void game::Game::FillTiles()
{
    auto [ w, h ] = m_tilemap->GetSize();
    w /= 16;
    h /= 16;

    for (int i = 0; i < w; i++)
    {
        for (int x = 0; x < h; x++)
        {
            int tileID = 0;

            if (x == 0 || x == 4 || i == 0 || i == 2)
            {
                tileID = 1;
            }

            m_tilemap->SetTile(x, i, tileID);
        }
    }
}
