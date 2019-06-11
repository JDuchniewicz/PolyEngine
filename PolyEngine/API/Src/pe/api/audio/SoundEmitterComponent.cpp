#include <EnginePCH.hpp>

#include <pe/api/audio/SoundEmitterComponent.hpp>
#include <pe/api/resources/ResourceManager.hpp>
#include <pe/api/resources/SoundResource.hpp>

using namespace pe::api::audio;

RTTI_DEFINE_COMPONENT(::pe::api::audio::SoundEmitterComponent)

SoundEmitterComponent::SoundEmitterComponent(const String& path, eResourceSource source, bool relative) :
	Background(relative)
{
	Resource = ResourceManager<SoundResource>::Load(path, source);

	alGenSources(1, &EmitterID);
	alSourcei(EmitterID, AL_BUFFER, Resource->GetBufferID());
}

SoundEmitterComponent::~SoundEmitterComponent()
{
	alDeleteSources(1, &EmitterID);

	if (Resource) 
		ResourceManager<SoundResource>::Release(Resource);
}