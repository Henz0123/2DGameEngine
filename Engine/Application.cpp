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

    m_editor = std::make_unique<editor::Editor>();
}

void engine::Application::Run()
{
    while (!WindowShouldClose() && m_isRunning)
    {
        Update();
        Draw();
    }

    m_game.reset();
    m_editor.reset();
    CloseWindow();
}

void engine::Application::Update()
{
    float dt = GetFrameTime();

    auto action = m_editor->Update();

    switch (action)
    {
        case editor::EditorAction::Play:
            if (!m_game)
                m_game = std::make_unique<game::Game>();
            break;

        case editor::EditorAction::Stop:
            m_game.reset();
            break;

        case editor::EditorAction::None:
            break;
    }

    m_editor->SetPlaying(m_game != nullptr);

    if (m_game)
    {
        const core::Vector2 moveDirection = m_input.HandleInput();
        m_game->Update(moveDirection, dt);
    }
}

void engine::Application::Draw()
{

    m_renderer.Draw(m_game.get(), *m_editor);

}
