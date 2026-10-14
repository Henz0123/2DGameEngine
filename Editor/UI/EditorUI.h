//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_EDITORUI_H
#define INC_2DGAMEENGINE_EDITORUI_H
#include "Toolbar.h"
#include "raylib.h"

namespace editor::ui
{
    class EditorUI {
    public:
        EditorAction Update(bool isPlaying);
    private:
        Toolbar m_toolbar;
    };
}


#endif //INC_2DGAMEENGINE_EDITORUI_H
