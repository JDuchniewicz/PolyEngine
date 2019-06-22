#pragma once

#include <Defines.hpp>

using namespace pe::api::physics2D;

namespace pe::api::physics2D {
	struct RigidBody2DData
	{
		b2BodyDef BodyDef;
		b2FixtureDef FixtureDef;
		b2Body* Body = nullptr;
		b2Fixture* Fixture = nullptr;
	};
}
