#pragma once

#include <Defines.hpp>
#include <pe/api/ecs/ComponentBase.hpp>
#include <pe/api/audio/SoundSystem.hpp>
#include <pe/api/audio/SoundListenerComponent.hpp>

typedef struct ALCcontext_struct ALCcontext;

namespace pe::api::audio
{
	class Scene;

	/// Component containing OpenAL context used in sound rendering.
	/// Only one context can be active in time.
	/// There can be only one context per world.
	/// @see SoundSystem
	class ENGINE_DLLEXPORT SoundWorldComponent : public ComponentBase
	{
	friend void SoundSystem::SetWorldCurrent(Scene* world);
	public:
		RTTI_DECLARE_COMPONENT(::pe::api::audio::SoundWorldComponent) { NO_RTTI_PROPERTY(); }
		/// Creates context from current device (stored in engine).
		/// @param world - world which will  be associated with just created context.
		/// @see OpenALDevice
		SoundWorldComponent(Scene* world);

		/// Releases stored context.
		~SoundWorldComponent();

		const Dynarray<SoundListenerComponent>& GetListeners() const { return Listeners; };

	private:
		ALCcontext* Context;
		Dynarray<SoundListenerComponent> Listeners;
	};

	REGISTER_COMPONENT(ComponentsIDGroup, SoundWorldComponent)

} // namespace pe::api::audio