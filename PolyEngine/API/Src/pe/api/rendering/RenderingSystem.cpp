#include <EnginePCH.hpp>

#include <pe/api/rendering/RenderingSystem.hpp>
#include <pe/api/rendering/IRenderingDevice.hpp>
#include <pe/api/ecs/Scene.hpp>

using namespace pe::api::rendering;

void RenderingSystem::RenderingPhase(Scene* world)
{	
	IRenderingDevice* device = gEngine->GetRenderingDevice();
	device->RenderWorld(world);
}
