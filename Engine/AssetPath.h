//
// Created by isak- on 10/14/2026.
//

#ifndef INC_2DGAMEENGINE_ASSETPATH_H
#define INC_2DGAMEENGINE_ASSETPATH_H
#include <filesystem>
#include "raylib.h"

namespace engine
{
    inline std::filesystem::path AssetPath(
    const std::filesystem::path& relativePath)
    {
        return std::filesystem::path(GetApplicationDirectory()) / "Assets" / relativePath;
    }
}
#endif //INC_2DGAMEENGINE_ASSETPATH_H
