//
// Created by isak- on 10/14/2026.
//

#include "EditorUI.h"

editor::EditorAction editor::ui::EditorUI::Update(bool isPlaying)
{
    const auto &action = m_toolbar.Update(isPlaying);

    return action;
}
