#include <EnginePCH.hpp>

#include <Rendering/ViewportWorldComponent.hpp>

using namespace Poly;

RTTI_DEFINE_COMPONENT(::Poly::ViewportWorldComponent)

ViewportWorldComponent::ViewportWorldComponent()
{
	AddViewport(::pe::core::math::AARect(::pe::core::math::Vector2f(0, 0), core::math::Vector2f(1, 1)));
}

ViewportID ViewportWorldComponent::AddViewport(const core::math::AARect& rect)
{
	ViewportID id = IDCounter++;
	Viewport view(rect);
	Viewports.insert(std::make_pair(id, view));

	return id;
}

void ViewportWorldComponent::RemoveViewport(ViewportID id)
{
	auto it = Viewports.find(id);
	ASSERTE(it != Viewports.end(), "Viewport doesn't exist.");
	Viewports.erase(it);
}

void ViewportWorldComponent::ResizeViewport(ViewportID id, const core::math::AARect& rect)
{
	auto it = Viewports.find(id);
	ASSERTE(it != Viewports.end(), "Viewport doesn't exist.");
	it->second.Resize(rect);
}

void ViewportWorldComponent::SetCamera(ViewportID id, CameraComponent* cam)
{
	auto it = Viewports.find(id);
	ASSERTE(it != Viewports.end(), "Viewport doesn't exist.");
	it->second.SetCamera(cam);
}