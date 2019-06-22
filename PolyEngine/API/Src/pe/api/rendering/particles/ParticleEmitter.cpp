#include <EnginePCH.hpp>

#include <pe/api/rendering/particles/ParticleEmitter.hpp>
#include <pe/api/resources/ResourceManager.hpp>

using namespace pe::api::rendering::particles;

ParticleEmitter::ParticleEmitter(const Settings& settings)
	: settings(settings), ToEmit(settings.InitialSize), ParticlesPool(settings.MaxSize)
{
	Spritesheet = ResourceManager<TextureResource>::Load(
		settings.Spritesheet.SpritePath,
		settings.Spritesheet.Source,
		eTextureUsageType::ALBEDO
	);
	ParticleProxy = gEngine->GetRenderingDevice()->CreateParticle();
}

ParticleEmitter::~ParticleEmitter()
{
	if (Spritesheet)
	{
		ResourceManager<TextureResource>::Release(Spritesheet);
	}
}

void ParticleEmitter::Emit(size_t size)
{
	ToEmit += size;
}