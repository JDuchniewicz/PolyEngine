#pragma once

#include <Defines.hpp>

namespace pe::api::ecs
{
	class Scene;
	class ISystem : public BaseObject<>
	{
	public:
		virtual void OnUpdate(Scene* scene) = 0;
	};
}