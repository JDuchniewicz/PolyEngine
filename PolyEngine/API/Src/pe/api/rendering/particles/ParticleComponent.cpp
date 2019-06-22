#include <EnginePCH.hpp>

#include <pe/api/rendering/particles/ParticleComponent.hpp>
#include <pe/api/rendering/camera/CameraComponent.hpp>

using namespace pe::api::rendering::particles;

RTTI_DEFINE_COMPONENT(::pe::api::rendering::particles::ParticleComponent)

ParticleComponent::ParticleComponent(const ParticleEmitter::Settings& emitter)
{
	Emitter = new ParticleEmitter(emitter);
}

pe::api::rendering::particles::ParticleComponent::~ParticleComponent()
{
	delete Emitter;
}