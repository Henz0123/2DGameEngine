//
// Created by isak- on 10/14/2026.
//

#include "EditorUI.h"
#include "../Editor.h"

editor::ui::EditorUI::EditorUI(const Editor &editor) : m_editor(editor) {}

editor::EditorAction editor::ui::EditorUI::Update()
{
    m_tilepalette.Update();
    return m_toolbar.Update(m_editor.IsPlaying());
}

void editor::ui::EditorUI::Draw() const
{
    m_toolbar.Draw(m_editor.IsPlaying());

    m_tilepalette.Draw();
    /*if (!m_editor.IsPlaying())
    {
        m_tilePalette.Draw();
    } */
}
