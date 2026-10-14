//
// Created by isak- on 10/14/2026.
//

#include "Editor.h"
#include <iostream>


editor::EditorAction editor::Editor::Update(bool isPlaying)
{
   const auto& action = m_ui.Update(isPlaying);

    return action;
}

void editor::Editor::Draw(bool isPlaying) const
{
    if (!isPlaying)
    {
        DrawRectangleRec(button, DARKGRAY);
        DrawText("Play", 35, 18, 20, WHITE);
    }
}
