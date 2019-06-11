#pragma once

#include <Defines.hpp>
#include <pe/api/ecs/ComponentBase.hpp>
#include <pe/api/debugging/FPSSystem.hpp>
#include <pe/api/time/TimeSystem.hpp>

namespace pe::api::debugging
{
	class Scene;

	/// <summary>WorldComponent that holds data for debug system.</summary>
	class ENGINE_DLLEXPORT DebugWorldComponent : public ComponentBase
	{
		RTTI_DECLARE_COMPONENT(::pe::api::debugging::DebugWorldComponent) { NO_RTTI_PROPERTY(); }

		friend void FPSSystem::FPSUpdatePhase(Scene*);
		friend float FPSSystem::GetFPS(Scene*);

	private:
		FPSSystem::FPSData FPSData;
	};
	REGISTER_COMPONENT(ComponentsIDGroup, DebugWorldComponent)
}