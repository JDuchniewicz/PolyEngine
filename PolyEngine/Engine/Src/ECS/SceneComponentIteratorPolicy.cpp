#include <EnginePCH.hpp>

#include <ECS/SceneComponentIteratorPolicy.hpp>
#include <ECS/Entity.hpp>
#include <ECS/Scene.hpp>

using namespace Poly;


SceneComponentIteratorPolicy::SceneComponentIteratorPolicy(Entity* entity, std::unique_ptr<IAllocatorIterator> begin, std::unique_ptr<IAllocatorIterator> end) 
{
    Iterator = std::move(begin);
    End = std::move(end);
    Match = entity;
}

SceneComponentIteratorPolicy SceneComponentIteratorPolicy::ConstructBegin(Entity* entity, size_t primaryComponentID)
{
    auto componentAllocator = entity->GetEntityScene()->GetComponentAllocator(primaryComponentID);
    return SceneComponentIteratorPolicy(entity, std::move(componentAllocator->GetAllocatorBegin()), std::move(componentAllocator->GetAllocatorEnd()));
}

SceneComponentIteratorPolicy SceneComponentIteratorPolicy::ConstructEnd(Entity* entity, size_t primaryComponentID)
{
    auto componentAllocator = entity->GetEntityScene()->GetComponentAllocator(primaryComponentID);
    return SceneComponentIteratorPolicy(entity, std::move(componentAllocator->GetAllocatorEnd()), std::move(componentAllocator->GetAllocatorEnd()));
}

bool SceneComponentIteratorPolicy::operator==(const IEntityIteratorPolicy& rhs) const
{
    return Iterator.get() == rhs.Get();
}

bool SceneComponentIteratorPolicy::operator!=(const IEntityIteratorPolicy& rhs) const
{
    return !(Iterator.get() == rhs.Get()); // can move to interface after it works
}

Entity* SceneComponentIteratorPolicy::GetEntity() const
{
    return Match;
}

IAllocatorIterator* SceneComponentIteratorPolicy::Get() const
{
    return Iterator.get();
} 

void SceneComponentIteratorPolicy::Increment()
{
    Iterator->increment();
    Match = reinterpret_cast<ComponentBase*>(Iterator->data())->GetOwner(); //with current implementation asserts when iterated through whole range 
}

bool SceneComponentIteratorPolicy::IsValid() const 
{
    return Iterator->data() != End->data();
}