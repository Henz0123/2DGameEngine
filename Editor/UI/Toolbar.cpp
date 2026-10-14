//
// Created by isak- on 10/14/2026.
//

#include "Toolbar.h"

editor::EditorAction editor::ui::Toolbar::Update(bool isPlaying)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), button)
    )
    {
        return isPlaying
                   ? EditorAction::Stop
                   : EditorAction::Play;
    }
    return EditorAction::None;
}

void editor::ui::Toolbar::Draw() const
{
    if (!isPlaying)
    {
        DrawPlayButton(isPlaying);
    } else
    {
        DrawPlayButton(isPlaying);
    }
}

void editor::ui::Toolbar::DrawPlayButton() const
{
    DrawRectangleRec(button, DARKGRAY);

    const char *label = isPlaying ? "Stop" : "Play";
    int fontSize = 20;

    float textX = button.x +
                  (button.width - MeasureText(label, fontSize)) / 2.0f;

    float textY = button.y +
                  (button.height - fontSize) / 2.0f;

    DrawRectangleRec(button, DARKGRAY);
    DrawText(label, static_cast<int>(textX),
             static_cast<int>(textY), fontSize, WHITE);
}
