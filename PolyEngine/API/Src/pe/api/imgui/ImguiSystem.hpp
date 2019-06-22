#pragma once

#include <Defines.hpp>
#include <pe/api/ecs/ISystem.hpp>

namespace pe::api::imgui
{
	class Scene;

	class ImguiSystem : public ISystem
	{
	public:
		ImguiSystem();

		void OnUpdate(Scene* scene) override;
	};
}