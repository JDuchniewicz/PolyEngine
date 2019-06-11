#include <EnginePCH.hpp>

#include <pe/api/ai/PathfindingComponent.hpp>

using namespace pe::api::ai;

RTTI_DEFINE_COMPONENT(::pe::api::ai::PathfindingComponent)

void pe::api::ai::PathfindingComponent::SetDestination(const Vector& pos)
{
	if(!CurentDestination.HasValue() || CurentDestination.Value() != pos)
		RecalculateRequested = true;

	CurentDestination = pos;
}

void pe::api::ai::PathfindingComponent::ResetDestination()
{
	CurentDestination = Optional<Vector>();
	CalculatedPath.Clear();
	RecalculateRequested = false;
}




