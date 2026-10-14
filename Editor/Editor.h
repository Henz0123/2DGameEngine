//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_EDITOR_H
#define INC_2DGAMEENGINE_EDITOR_H

#include "EditorAction.h"

#include "raylib.h"
#include "UI/EditorUI.h"

namespace editor
{
    class Editor {
    public:
        EditorAction Update();

        void Draw() const;

        void SetPlaying(bool isPlaying);
        bool IsPlaying() const;

    private:

        ui::EditorUI m_ui;

        bool m_isPlaying = false;
    };
}


#endif //INC_2DGAMEENGINE_EDITOR_H
