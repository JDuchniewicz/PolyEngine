#include <EnginePCH.hpp>

#include <pe/api/rendering/camera/CameraComponent.hpp>
#include <pe/api/rendering/MeshRenderingComponent.hpp>
#include <pe/api/resources/ResourceManager.hpp>

using namespace pe::api::rendering;

RTTI_DEFINE_COMPONENT(::pe::api::rendering::MeshRenderingComponent)

MeshRenderingComponent::MeshRenderingComponent(const String& meshPath, eResourceSource source)
{
	Mesh = ResourceManager<MeshResource>::Load(meshPath, source);
	
	if (Mesh)
	{
		size_t materialsNum = GetMesh()->GetSubMeshes().GetSize();
		Materials.Resize(materialsNum);
		for (size_t i = 0; i < materialsNum; ++i)
		{
			SetMaterial(i, Material());
		}
	}
}

pe::api::rendering::MeshRenderingComponent::~MeshRenderingComponent()
{
	if (Mesh)
		ResourceManager<MeshResource>::Release(Mesh);
}

Optional<AABox> pe::api::rendering::MeshRenderingComponent::GetBoundingBox(eEntityBoundingChannel channel) const
{
	if (channel != eEntityBoundingChannel::RENDERING || !Mesh)
		return {};
	return Mesh->GetAABox();
}
