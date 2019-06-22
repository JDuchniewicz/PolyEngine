#pragma once

#include <Defines.hpp>

namespace pe::api::rendering::particles
{
	class Scene;
	class EntityTransform;
	class ParticleComponent;
	class ParticleEmitter;

	namespace ParticleUpdateSystem
	{
		void ParticleUpdatePhase(Scene* world);
		void EmitterEmit(Scene*, ParticleEmitter*, ParticleComponent*);
		void EmitterUpdate(Scene*, ParticleEmitter*);
		void EmitterRecreateBuffer(Scene*, ParticleEmitter*);
	}
}