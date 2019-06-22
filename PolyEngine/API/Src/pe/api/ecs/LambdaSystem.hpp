#pragma once

#include <Defines.hpp>
#include <pe/api/ecs/ISystem.hpp>

namespace pe::api::ecs
{
	class Scene;
	using PhaseUpdateFunction = std::function<void(Scene*)>;

	class LambdaSystem : public ISystem
	{
	public:
		explicit LambdaSystem(PhaseUpdateFunction func) { UpdateFunctionObject = std::move(func); }
		void OnUpdate(Scene* scene) override { UpdateFunctionObject(scene); }
	private:
		PhaseUpdateFunction UpdateFunctionObject;
	};
}