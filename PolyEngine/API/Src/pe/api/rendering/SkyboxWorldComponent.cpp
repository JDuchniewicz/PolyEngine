#include <EnginePCH.hpp>

#include <pe/api/rendering/SkyboxWorldComponent.hpp>
#include <pe/api/resources/ResourceManager.hpp>
#include <pe/api/resources/TextureResource.hpp>

using namespace pe::api::rendering;

RTTI_DEFINE_COMPONENT(::pe::api::rendering::SkyboxWorldComponent)

SkyboxWorldComponent::SkyboxWorldComponent(const String& panoramaPath, const eResourceSource source)
	: Tint(Color::WHITE)
{
	Init( {panoramaPath}, source);
}

SkyboxWorldComponent::SkyboxWorldComponent(const Dynarray<String>& panoramaPaths, const eResourceSource source)
	: Tint(Color::WHITE)
{
	Init(panoramaPaths, source);
}

SkyboxWorldComponent::~SkyboxWorldComponent()
{
	for (auto p : EquirectPanoramas)
		ResourceManager<TextureResource>::Release(p);
}

void SkyboxWorldComponent::Init(const Dynarray<String>& panoramaPaths, const eResourceSource source)
{
	for (auto p : panoramaPaths)
	{
		TextureResource* texture = ResourceManager<TextureResource>::Load(p, source, eTextureUsageType::HDR);
		EquirectPanoramas.PushBack(texture);
		gConsole.LogInfo("SkyboxWorldComponent::SkyboxWorldComponent panoramaPath: {}", p);
	}
}