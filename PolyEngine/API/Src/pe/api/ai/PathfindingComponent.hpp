#pragma once

#include <Defines.hpp>
#include <pe/api/ecs/ComponentBase.hpp>
#include <pe/api/ai/PathfindingSystem.hpp>

namespace pe::api::ai;
{
	class ENGINE_DLLEXPORT NavNode : public BaseObject<>
	{};

	class ENGINE_DLLEXPORT NavGraph : public BaseObject<>
	{
	public:
		virtual float GetTravelCost(const pe::api::ai::NavNode* from, const pe::api::ai::NavNode* to) const = 0;
		virtual float GetHeuristicCost(const pe::api::ai::NavNode* from, const pe::api::ai::NavNode* to) const = 0;
		virtual Vector GetNodeWorldPosition(const pe::api::ai::NavNode* node) const = 0;
		virtual const NavNode* GetNodeFromWorldPosition(const Vector& pos) const = 0;
		virtual void GetConnections(const pe::api::ai::NavNode* node, Dynarray<const NavNode*>& connections) const = 0;
		virtual bool CanConnectDirectly(const NavNode* n1, const NavNode* n2) const = 0;
	};

	class ENGINE_DLLEXPORT PathfindingComponent : public ComponentBase
	{
	public:
		RTTI_DECLARE_COMPONENT(::pe::api::ai::PathfindingComponent) { NO_RTTI_PROPERTY(); }

		PathfindingComponent(const NavGraph* navGraphs) : NavigationGraph(navGraphs) {}

		void SetDestination(const Vector& pos);
		void ResetDestination();

		inline const Dynarray<Vector>& GetPath() const { return CalculatedPath; }
	private:
		const NavGraph* NavigationGraph = nullptr;
		Dynarray<Vector> CalculatedPath;
		Optional<Vector> CurentDestination;
		bool RecalculateRequested = false;
		bool LastPathSearchFailed = false;

		friend void PathfindingSystem::UpdatePhase(Scene* world);
	};

	REGISTER_COMPONENT(::pe::api::ai::ComponentsIDGroup, PathfindingComponent)
}
