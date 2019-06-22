#pragma once

#include <Defines.hpp>
#include <pe/api/ecs/ComponentBase.hpp>
#include <pe/api/rendering/camera/CameraSystem.hpp>
#include <pe/api/rendering/Viewport.hpp>

namespace pe::api::rendering
{
	class AARect;
	typedef size_t ViewportID;

	class ENGINE_DLLEXPORT ViewportWorldComponent : public ComponentBase
	{
		RTTI_DECLARE_COMPONENT(::pe::api::rendering::ViewportWorldComponent) { NO_RTTI_PROPERTY(); }
	friend void CameraSystem::CameraUpdatePhase(Scene*);
	public:
		ViewportWorldComponent();

		ViewportID AddViewport(const AARect&);
		void RemoveViewport(ViewportID);
		void ResizeViewport(ViewportID, const AARect&);
		void SetCamera(ViewportID, CameraComponent*);

		std::unordered_map<size_t, Viewport>& GetViewports() { return Viewports; }

	private:
		std::unordered_map<size_t, Viewport> Viewports;
		ViewportID IDCounter = 0;
	};

	REGISTER_COMPONENT(ComponentsIDGroup, ViewportWorldComponent)
}