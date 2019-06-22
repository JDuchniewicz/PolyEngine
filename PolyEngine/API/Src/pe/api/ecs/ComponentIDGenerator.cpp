#include <EnginePCH.hpp>

#include <pe/api/ecs/ComponentIDGenerator.hpp>

using namespace pe::api::ecs;

pe::api::ecs::ComponentManager& pe::api::ecs::ComponentManager::Get()
{
	static ComponentManager instance;
	return instance;
}

Optional<size_t> pe::api::ecs::ComponentManager::GetComponentID(const RTTI::TypeInfo& typeinfo) const
{
	const auto& it = TypeToIDMap.find(typeinfo);
	if (it == TypeToIDMap.end())
		return {};
	return it->second;
}

Poly::RTTI::TypeInfo pe::api::ecs::ComponentManager::GetComponentType(size_t id) const
{
	const auto& it = IDToTypeMap.find(id);
	if (it == IDToTypeMap.end())
		return RTTI::TypeInfo::INVALID;
	return it->second;
}

Dynarray<std::pair<RTTI::TypeInfo, size_t>> pe::api::ecs::ComponentManager::GetComponentTypesList() const
{
	Dynarray<std::pair<RTTI::TypeInfo, size_t>> ret;
	ret.Reserve(TypeToIDMap.size());

	for (const auto& kv : TypeToIDMap)
		ret.PushBack({kv.first, kv.second});

	return ret;
}

IterablePoolAllocatorBase* pe::api::ecs::ComponentManager::CreateAllocator(size_t id, size_t componentCount) const
{
	const auto& it = IDToCreatorMap.find(id);
	if (it == IDToCreatorMap.end())
		return nullptr;
	return it->second(componentCount);
}

void pe::api::ecs::ComponentManager::Clear()
{
	TypeToIDMap.clear();
	IDToTypeMap.clear();
	IDToCreatorMap.clear();
}

size_t pe::api::ecs::Impl::ComponentIDGenerator::GenerateID() noexcept
{
	static size_t value = 0;
	return value++;
}