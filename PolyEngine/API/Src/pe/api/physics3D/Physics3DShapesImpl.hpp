#pragma once

#include <Defines.hpp>

class btCollisionShape;
class btTriangleMesh;

namespace pe::api::physics3D
{
	struct Physics3DShapeImpl : BaseObject<>
	{
		btCollisionShape* BulletShape = nullptr;
	};

	struct Physics3DStaticMeshSourceImpl : BaseObject<>
	{
		btTriangleMesh* BulletMesh = nullptr;
	};
}