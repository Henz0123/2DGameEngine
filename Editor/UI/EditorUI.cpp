//
// Created by isak- on 10/14/2026.
//

#include "EditorUI.h"

editor::ui::EditorUI::EditorUI(const Editor &editor) : m_editor(editor) {}

editor::EditorAction editor::ui::EditorUI::Update()
{
    const auto &action = m_toolbar.Update();

    return action;
}

void editor::ui::EditorUI::Draw()
{
    m_toolbar.Draw();
}
