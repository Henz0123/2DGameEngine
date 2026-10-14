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

    public:
        explicit Entity(core::EntityType charType) :  m_charType(charType), m_id(idCounter++)
        {
        }
        virtual ~Entity() = default;

        Entity(const Entity&) = delete;
        Entity& operator=(const Entity&) = delete;

        const core::EntityType GetCharType() const { return m_charType; }

        virtual void Update(float dt) = 0;

        EntityID GetID() const { return m_id; }

        const core::Transform& GetTransform() const
        {
            return m_transform;
        }

    protected:
        core::Transform m_transform;

    private:
        core::EntityType m_charType;
        EntityID m_id;
        inline static EntityID idCounter;


    };
}


#endif //INC_2DGAMEENGINE_ENTITY_H
