#pragma once

#include <Defines.hpp>
#include <pe/api/input/InputQueue.hpp>
#include <pe/api/input/OutputQueue.hpp>

namespace pe::api::input
{
	class Scene;

	namespace InputSystem
	{
		void InputPhase(Scene*);
	}
}