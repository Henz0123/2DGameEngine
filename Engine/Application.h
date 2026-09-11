//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_APPLICATION_H
#define INC_2DGAMEENGINE_APPLICATION_H
#include "Input.h"
#include "../Game/Game.h"
#include <memory>
#include "Renderer.h"


namespace engine
{
    class Application {
    public:
        Application(int width, int height);

        void Run();

    private:
        void Update();

        void Draw();

        std::unique_ptr<game::Game> m_game;
        Renderer m_renderer;

        Input m_input;

        bool m_isRunning;
        int m_width, m_height;
    };
}


#endif //INC_2DGAMEENGINE_APPLICATION_H
