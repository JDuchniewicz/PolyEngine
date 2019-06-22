#pragma once

#include <Defines.hpp>

namespace pe::api::rendering::camera
{
	class Scene;

	namespace CameraSystem
	{
		void CameraUpdatePhase(Scene* world);
	}
}