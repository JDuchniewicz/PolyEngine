#include <EnginePCH.hpp>

#include <pe/api/movement/MovementSystem.hpp>
#include <pe/api/movement/FreeFloatMovementComponent.hpp>
#include <pe/api/ecs/EntityTransform.hpp>
#include <pe/api/ecs/Scene.hpp>
#include <pe/api/time/TimeSystem.hpp>
#include <pe/api/input/InputSystem.hpp>
#include <pe/api/input/InputWorldComponent.hpp>


using namespace pe::api::movement;

void MovementSystem::MovementUpdatePhase(Scene* world)
{
	float deltaTime = (float)(TimeSystem::GetTimerDeltaTime(world, pe::api::time::eEngineTimer::GAMEPLAY));
	InputWorldComponent* inputCmp = world->GetWorldComponent<InputWorldComponent>();
	
	if (inputCmp->GetIsConsumed())
		return;

	for (auto freeFloatTuple : world->IterateComponents<FreeFloatMovementComponent>())
	{
		FreeFloatMovementComponent* freeFloatMovementCmp = std::get<FreeFloatMovementComponent*>(freeFloatTuple);
		EntityTransform& trans = freeFloatMovementCmp->GetTransform();

		float wheelDelta = freeFloatMovementCmp->GetWheelSensitivity() * inputCmp->GetWheelPosDelta().Y;
		float currSpeed = freeFloatMovementCmp->GetMovementSpeed();
		float newSpeed = Clamp(currSpeed + wheelDelta, 0.001f, 10000.0f);
		freeFloatMovementCmp->SetMovementSpeed(newSpeed);
		
		Vector move;
		if (inputCmp->IsPressed(eKey::KEY_W))
			move -= Vector::UNIT_Z;
		else if (inputCmp->IsPressed(eKey::KEY_S))
			move += Vector::UNIT_Z;

		if (inputCmp->IsPressed(eKey::KEY_A))
			move -= Vector::UNIT_X;
		else if (inputCmp->IsPressed(eKey::KEY_D))
			move += Vector::UNIT_X;

		if (inputCmp->IsPressed(eKey::KEY_Q))
			move -= Vector::UNIT_Y;
		else if (inputCmp->IsPressed(eKey::KEY_E))
			move += Vector::UNIT_Y;

		if (move.LengthSquared() > 0)
			move.Normalize();

		move *= freeFloatMovementCmp->GetMovementSpeed() * deltaTime;

		trans.SetLocalTranslation(trans.GetLocalTranslation() + trans.GetLocalRotation() * move);
		
		if (inputCmp->IsPressed(eMouseButton::LEFT))
		{
			Vector2i delta = inputCmp->GetMousePosDelta();

			Quaternion rot = Quaternion(Vector::UNIT_Y, Angle::FromRadians(-delta.X * freeFloatMovementCmp->GetAngularVelocity()));
			rot *= trans.GetLocalRotation();
			rot *= Quaternion(Vector::UNIT_X, Angle::FromRadians(-delta.Y * freeFloatMovementCmp->GetAngularVelocity()));

			if (rot != Quaternion()) {
				rot.Normalize();
				trans.SetLocalRotation(rot);
			}
		}
	}
}