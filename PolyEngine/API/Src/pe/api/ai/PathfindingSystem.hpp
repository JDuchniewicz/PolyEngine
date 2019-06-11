#pragma once

#include <Defines.hpp>

namespace pe::api::ai;
{
	class Scene;

	namespace PathfindingSystem
	{
		ENGINE_DLLEXPORT void UpdatePhase(Scene* world);
	};
}
