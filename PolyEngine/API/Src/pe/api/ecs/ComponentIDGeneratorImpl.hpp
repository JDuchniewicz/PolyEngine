#include <pe/api/ecs/ComponentIDGenerator.hpp>

namespace pe::api::ecs
{
	namespace Impl
	{
		template<typename U>
		size_t ComponentIDGenerator::GetComponentTypeID() noexcept
		{
			static const size_t value = GenerateID();
			return value;
		}
	}
}
