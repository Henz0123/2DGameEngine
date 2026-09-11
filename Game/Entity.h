//
// Created by isak- on 9/8/2026.
//

#ifndef INC_2DGAMEENGINE_ENTITY_H
#define INC_2DGAMEENGINE_ENTITY_H
#include "../Core/Characters.h"
#include "../Core/Types.h"

using EntityID = unsigned int;

namespace game
{
    class Entity {
    protected:
        Entity(core::CharacterType charType) : m_id(idCounter++), m_charType(charType)
        {

        }
        core::Transform m_transform;

    private:
        core::CharacterType m_charType;
        EntityID m_id;
        static EntityID idCounter;

    public:
        virtual ~Entity() = default;

        const core::CharacterType &GetCharType() const { return m_charType; }

        virtual void Update(const core::Vector2 &moveDirection, float speed) = 0;

        EntityID GetID() const { return m_id; }
    };
}


#endif //INC_2DGAMEENGINE_ENTITY_H
