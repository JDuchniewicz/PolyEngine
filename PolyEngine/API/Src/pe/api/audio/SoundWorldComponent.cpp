#include <EnginePCH.hpp>

#include <pe/api/audio/SoundWorldComponent.hpp>

using namespace pe::api::audio;

RTTI_DEFINE_COMPONENT(::pe::api::audio::SoundWorldComponent)

SoundWorldComponent::SoundWorldComponent(Scene* /*world*/)
{
	Context = alcCreateContext(gEngine->GetAudioDevice().Device, nullptr);
}

SoundWorldComponent::~SoundWorldComponent()
{
	alcDestroyContext(Context);
}
