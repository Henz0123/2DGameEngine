//
// Created by isak- on 9/6/2026.
//

#ifndef INC_2DGAMEENGINE_TYPES_H
#define INC_2DGAMEENGINE_TYPES_H


namespace core
{
    struct Vector2 {
        float x;
        float y;
    };

    struct Transform {
        Vector2 position;
        float rotation;
        Vector2 size;
    };

    enum class InputAction {
        MoveUp,
        MoveDown,
        MoveLeft,
        MoveRight,
    };

};


#endif //INC_2DGAMEENGINE_TYPES_H
