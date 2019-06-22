#include <EnginePCH.hpp>

#include <pe/api/rendering/camera/CameraComponent.hpp>
#include <pe/api/rendering/SpritesheetComponent.hpp>
#include <pe/api/resources/ResourceManager.hpp>
#include <pe/api/resources/TextureResource.hpp>

using namespace pe::api::rendering;

RTTI_DEFINE_COMPONENT(::pe::api::rendering::SpritesheetComponent)

SpritesheetComponent::SpritesheetComponent(const SpritesheetSettings& settings) : Settings(settings)
{
	Spritesheet = ResourceManager<TextureResource>::Load(settings.SpritePath, settings.Source, eTextureUsageType::ALBEDO);
}

SpritesheetComponent::~SpritesheetComponent()
{
	if (Spritesheet)
	{
		ResourceManager<TextureResource>::Release(Spritesheet);
	}
}
