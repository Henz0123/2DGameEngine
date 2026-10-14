//
// Created by isak- on 9/6/2026.
//

#include "Application.h"
#include <raylib.h>

engine::Application::Application(int width, int height)
    : m_isRunning(true),
      m_width(width),
      m_height(height)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(m_width, m_height, "GameEngine");

    int monitor = GetCurrentMonitor();

    m_width = static_cast<int>(GetMonitorWidth(monitor) * 0.85f);
    m_height = static_cast<int>(GetMonitorHeight(monitor) * 0.85f);

    SetWindowSize(m_width, m_height);

    Vector2 monitorPos = GetMonitorPosition(monitor);

    SetWindowPosition(
            static_cast<int>(monitorPos.x + (GetMonitorWidth(monitor) - m_width) / 2),
            static_cast<int>(monitorPos.y + (GetMonitorHeight(monitor) - m_height) / 2)
            );

    Vector2 windowPos = GetWindowPosition();
    Vector2 dpi = GetWindowScaleDPI();

    TraceLog(LOG_INFO, "Monitor: %d", monitor);
    TraceLog(LOG_INFO, "Monitor size: %d x %d",
             GetMonitorWidth(monitor), GetMonitorHeight(monitor));

    TraceLog(LOG_INFO, "Window size: %d x %d",
             GetScreenWidth(), GetScreenHeight());

    TraceLog(LOG_INFO, "Window position: %.0f, %.0f",
             windowPos.x, windowPos.y);

    TraceLog(LOG_INFO, "DPI scale: %.2f, %.2f",
             dpi.x, dpi.y);

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
