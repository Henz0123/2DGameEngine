//
// Created by isak- on 9/6/2026.
//

#include "Application.h"
#include <raylib.h>

engine::Application::Application(int width, int height)
    : m_width(width),
      m_height(height),
      m_isRunning(true)
{
    InitWindow(width, height, "GameEngine");
    SetTargetFPS(60);

    m_game = std::make_unique<game::Game>();
}

void engine::Application::Run()
{
    while (!WindowShouldClose() && m_isRunning) {
        Update();
        Draw();
    }

    m_game.reset();
    CloseWindow();
}

void engine::Application::Update()
{
    float deltaTime = GetFrameTime();
    const core::Vector2 moveDirection = m_input.HandleInput();
    m_game->Update(moveDirection, deltaTime);
}

void engine::Application::Draw()
{
    if (m_game)
        m_renderer.Draw(*m_game);
}
