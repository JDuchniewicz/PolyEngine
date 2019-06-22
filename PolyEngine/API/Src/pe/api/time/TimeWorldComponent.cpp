#include <EnginePCH.hpp>

#include <pe/api/time/TimeWorldComponent.hpp>

RTTI_DEFINE_COMPONENT(::pe::api::time::TimeWorldComponent)

//------------------------------------------------------------------------------
pe::api::time::TimeWorldComponent::TimeWorldComponent()
{
	LastFrameTime = std::chrono::steady_clock::now();
	Timers[(size_t) eEngineTimer::SYSTEM] = Timer(false);
	Timers[(size_t) eEngineTimer::GAMEPLAY] = Timer(true);
}

