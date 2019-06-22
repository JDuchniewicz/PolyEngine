#include <EnginePCH.hpp>

#include <pe/api/movement/FreeFloatMovementComponent.hpp>

using namespace pe::api::movement;

RTTI_DEFINE_COMPONENT(::pe::api::movement::FreeFloatMovementComponent)

pe::api::movement::FreeFloatMovementComponent::FreeFloatMovementComponent(float movementSpeed, float rotationSpeed, float wheelSensitivity)
	: MovementSpeed(movementSpeed), RotationSpeed(rotationSpeed), WheelSensitivity(wheelSensitivity)
{
}
