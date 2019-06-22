#pragma once

#include <Defines.hpp>

class btCollisionObject;

namespace pe::api::physics3D
{
	struct Trigger3DImpl : BaseObject<>
	{
		btCollisionObject* BulletTrigger = nullptr;
	};
} // namespace pe::api::physics3D