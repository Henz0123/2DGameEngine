//
// Created by isak- on 10/14/2026.
//

#include "Editor.h"
#include <iostream>


editor::EditorAction editor::Editor::Update()
{
    const auto &action = m_ui.Update();

    return action;
}

void editor::Editor::Draw() const
{
    m_ui.DrawToolbar();

    if (!m_isPlaying)
        m_ui.DrawTilePalette();
}

void editor::Editor::SetPlaying(bool isPlaying)
{
    m_isPlaying = isPlaying;
}

bool editor::Editor::IsPlaying() const
{
    return m_isPlaying;
}
