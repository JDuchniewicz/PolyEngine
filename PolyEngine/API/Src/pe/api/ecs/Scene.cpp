#include <EnginePCH.hpp>

#include <pe/api/ecs/Scene.hpp>

using namespace pe::api::ecs;

RTTI_DEFINE_TYPE(::pe::api::ecs::Scene);

//------------------------------------------------------------------------------
Scene::Scene()
	: EntitiesAllocator(MAX_ENTITY_COUNT), ComponentDel(), EntityDel(), RootEntity(nullptr, EntityDel)
{
	memset(ComponentAllocators, 0, sizeof(IterablePoolAllocatorBase*) * MAX_COMPONENTS_COUNT);

	RootEntity.reset(SpawnEntityInternal());
}

//------------------------------------------------------------------------------
Scene::~Scene()
{
	RootEntity.reset();
	
	for (size_t i = 0; i < MAX_COMPONENTS_COUNT; ++i)
	{
		if (ComponentAllocators[i])
			delete ComponentAllocators[i];
	}
}

//------------------------------------------------------------------------------
void pe::api::ecs::Scene::BeforeDeserializationCallback()
{
	gEngine->SetCurrentlySerializedScene(this);
}

//------------------------------------------------------------------------------
void pe::api::ecs::Scene::AfterDeserializationCallback()
{
	gEngine->SetCurrentlySerializedScene(nullptr);
}

//------------------------------------------------------------------------------
Entity* Scene::SpawnEntity()
{
	Entity* ent = SpawnEntityInternal();
	ent->SetParent(RootEntity.get());
	return ent;
}

//------------------------------------------------------------------------------
Entity * pe::api::ecs::Scene::SpawnEntityInternal()
{
	Entity* ent = EntitiesAllocator.Alloc();
	::new(ent) Entity(this);
	return ent;
}

//------------------------------------------------------------------------------
void Scene::DestroyEntity(Entity* entity)
{
	HEAVY_ASSERTE(entity, "Invalid entity ID");

	entity->ReleaseFromParent();
	EntityDel(entity);
}

//------------------------------------------------------------------------------
bool Scene::HasWorldComponent(size_t ID) const
{
	return RootEntity->HasComponent(ID);
}

//------------------------------------------------------------------------------
void Scene::RemoveComponentById(Entity* ent, size_t id)
{
	HEAVY_ASSERTE(ent->Components[id], "Removing not present component");
	ent->Components[id].reset();
}