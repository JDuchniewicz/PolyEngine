#pragma once

#include <Defines.hpp>
#include <pe/api/ecs/ComponentBase.hpp>
#include <pe/api/rendering/renderingSystem.hpp>
#include <pe/api/rendering/particles/ParticleEmitter.hpp>

namespace pe::api::rendering::particles {

	class ENGINE_DLLEXPORT ParticleComponent : public ComponentBase
	{
		friend void ParticleUpdateSystem::ParticleUpdatePhase(Scene*);
	public:
		RTTI_DECLARE_COMPONENT(::pe::api::rendering::particles::ParticleComponent) { NO_RTTI_PROPERTY(); }

		ParticleComponent(const ParticleEmitter::Settings& emitter);
		virtual ~ParticleComponent();
		
		ParticleEmitter* GetEmitter() { return Emitter; }

		const ParticleEmitter* GetEmitter() const { return Emitter; }

	private:
		ParticleEmitter* Emitter = nullptr;
	};

	REGISTER_COMPONENT(ComponentsIDGroup, ParticleComponent)
}