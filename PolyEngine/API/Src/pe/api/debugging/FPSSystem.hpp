#pragma once

#include <Defines.hpp>

namespace pe::api::debugging
{
	class Scene;

	namespace FPSSystem
	{
		struct FPSData : public BaseObject<>
		{
			int FPS;
			double ElapsedTime;
			int LastFPS;
			String DisplayedFPSText;
		};

		float ENGINE_DLLEXPORT GetFPS(Scene* world);
		void FPSUpdatePhase(Scene*);
	}
}