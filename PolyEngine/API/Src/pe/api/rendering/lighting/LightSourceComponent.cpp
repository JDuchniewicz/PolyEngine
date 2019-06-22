#include <EnginePCH.hpp>

#include <pe/api/rendering/lighting/LightSourceComponent.hpp>

RTTI_DEFINE_COMPONENT(::pe::api::rendering::lighting::AmbientLightWorldComponent)
RTTI_DEFINE_COMPONENT(::pe::api::rendering::lighting::DirectionalLightComponent)
RTTI_DEFINE_COMPONENT(::pe::api::rendering::lighting::PointLightComponent)
RTTI_DEFINE_COMPONENT(::pe::api::rendering::lighting::SpotLightComponent)

pe::api::rendering::lighting::AmbientLightWorldComponent::AmbientLightWorldComponent(const Color& color, float intensity)
	: LightColor(color), Intensity(intensity)
{
}

pe::api::rendering::lighting::DirectionalLightComponent::DirectionalLightComponent(const Color& color, float intensity)
	: LightColor(color), Intensity(intensity)
{
}

pe::api::rendering::lighting::PointLightComponent::PointLightComponent(const Color& color, float intensity, float range)
	: LightColor(color), Intensity(intensity), Range(range)
{
}

pe::api::rendering::lighting::SpotLightComponent::SpotLightComponent(const Color& color, float intensity, float range, float cutOff, float outerCutOff)
	: LightColor(color), Intensity(intensity), Range(range), CutOff(cutOff), OuterCutOff(outerCutOff)
{
}