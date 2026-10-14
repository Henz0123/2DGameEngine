//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_TOOLBAR_H
#define INC_2DGAMEENGINE_TOOLBAR_H
#include "raylib.h"
#include "../EditorAction.h"

namespace editor::ui
{
    class Toolbar {
    public:
        EditorAction Update();
        void Draw() const;
    private:
        void DrawPlayButton() const;
        Rectangle button{(GetScreenWidth()-100)/2.f, 10, 100, 35};
    };
}


#endif //INC_2DGAMEENGINE_TOOLBAR_H
