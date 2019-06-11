#include <EnginePCH.hpp>

#include <pe/api/debugging/FPSSystem.hpp>
#include <pe/api/debugging/DebugDrawSystem.hpp>
#include <pe/api/debugging/DebugWorldComponent.hpp>
#include <pe/api/time/TimeSystem.hpp>
#include <pe/api/ecs/DeferredTaskSystem.hpp>
#include <pe/api/configs/DebugConfig.hpp>

using namespace pe::api::debugging;

void FPSSystem::FPSUpdatePhase(Scene* world)
{
	DebugWorldComponent* com = world->GetWorldComponent<DebugWorldComponent>();
	
	if (gDebugConfig.DisplayFPS && TimeSystem::GetTimerElapsedTime(world, eEngineTimer::SYSTEM) - com->FPSData.ElapsedTime > 1)
	{
		com->FPSData.ElapsedTime = TimeSystem::GetTimerElapsedTime(world, eEngineTimer::SYSTEM);

		StringBuilder sb;
		sb.AppendFormat("FPS: {}", com->FPSData.FPS);
		com->FPSData.DisplayedFPSText = sb.StealString();
		com->FPSData.LastFPS = com->FPSData.FPS;
		com->FPSData.FPS = 0;
	}

	com->FPSData.FPS++;

	DebugDrawSystem::DrawText2D(world, Vector2i(50, 50), com->FPSData.DisplayedFPSText, 32);
}

float FPSSystem::GetFPS(Scene * world)
{
	return (float)world->GetWorldComponent<DebugWorldComponent>()->FPSData.LastFPS;
}
