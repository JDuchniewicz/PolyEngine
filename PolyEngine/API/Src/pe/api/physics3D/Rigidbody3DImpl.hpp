#pragma once

#include <Defines.hpp>

struct btDefaultMotionState;
class btRigidBody;

namespace pe::api::physics3D
{
	struct Rigidbody3DImpl : BaseObject<>
	{
		btDefaultMotionState* BulletMotionState = nullptr;
		btRigidBody* BulletRigidBody = nullptr;
	};
} // namespace pe::api::physics3D