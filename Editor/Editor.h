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
        EditorAction Update(bool isPlaying);

        void Draw(bool isPlaying) const;
    private:

        ui::EditorUI m_ui;
   Rectangle button{10, 10, 100, 35};
    };
}


#endif //INC_2DGAMEENGINE_EDITOR_H
