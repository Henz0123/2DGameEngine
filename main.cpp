#include <iostream>

#include "Engine/Application.h"


int main()
{
    engine::Application app(1440, 960);

    app.Run();

    return 0;
}
