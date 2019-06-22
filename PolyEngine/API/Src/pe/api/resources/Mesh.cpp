#include <EnginePCH.hpp>

#include <pe/api/resources/Mesh.hpp>
#include <pe/api/resources/ResourceManager.hpp>
#include <pe/api/resources/TextureResource.hpp>

pe::api::resources::Mesh::~Mesh()
{
	if (AlbedoMap)
		ResourceManager<TextureResource>::Release(AlbedoMap);

	if (RoughnessMap)
		ResourceManager<TextureResource>::Release(RoughnessMap);

	if (MetallicMap)
		ResourceManager<TextureResource>::Release(MetallicMap);

	if (AmbientOcclusionMap)
		ResourceManager<TextureResource>::Release(AmbientOcclusionMap);

	if (NormalMap)
		ResourceManager<TextureResource>::Release(NormalMap);

	if (EmissiveMap)
		ResourceManager<TextureResource>::Release(EmissiveMap);
}
