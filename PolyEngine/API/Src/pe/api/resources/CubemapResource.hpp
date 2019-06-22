#pragma once

#include <Defines.hpp>
#include <pe/api/resources/ResourceBase.hpp>
#include <pe/api/rendering/IRenderingDevice.hpp>

typedef unsigned int GLuint;

namespace pe::api::resources 
{
	class ITextureDeviceProxy;

	class ENGINE_DLLEXPORT CubemapResource : public ResourceBase
	{
	public:
		CubemapResource(const EnumArray<String, eCubemapSide> paths);
		~CubemapResource() override;
		
		float* GetImage(const eCubemapSide side) const { return Images[side]; }
		int GetWidth() const { return Width; }
		int GetHeight() const { return Height; }
		int GetChannels() const { return Channels; }

		const ICubemapDeviceProxy* GetTextureProxy() const { return TextureProxy.get(); }
	private:
		std::unique_ptr<ICubemapDeviceProxy> TextureProxy;
		EnumArray<float*, eCubemapSide> Images;
		int Width;
		int Height;
		int Channels;
	};
}

