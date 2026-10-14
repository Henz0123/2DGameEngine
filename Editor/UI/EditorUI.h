//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_EDITORUI_H
#define INC_2DGAMEENGINE_EDITORUI_H
#include "Toolbar.h"
#include "raylib.h"

namespace editor
{
    class Editor;
}

namespace editor::ui
{
    class EditorUI {
    public:
        explicit EditorUI(const Editor& editor);


        EditorAction Update();

       void Draw();

    private:
        const Editor& m_editor;
        Toolbar m_toolbar;
    };
}


#endif //INC_2DGAMEENGINE_EDITORUI_H
