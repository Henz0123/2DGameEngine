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

void editor::ui::Toolbar::Draw(bool isPlaying) const
{
    if (!isPlaying)
    {
        DrawRectangleRec(button, DARKGRAY);
        DrawText("Play", 35, 18, 20, WHITE);
    }
}
