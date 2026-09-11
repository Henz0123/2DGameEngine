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

    CloseWindow();
}

void engine::Application::Update()
{
    const core::Vector2 moveDirection = m_input.HandleInput();
    m_game->Update(moveDirection);
}

void engine::Application::Draw()
{
    if (m_game)
        m_renderer.Draw(*m_game);
}
