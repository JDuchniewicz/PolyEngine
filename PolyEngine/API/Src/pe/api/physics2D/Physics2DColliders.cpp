#include <EnginePCH.hpp>

#include <Box2D/Box2D.h>
#include <pe/api/physics2D/Physics2DColliders.hpp>

RTTI_DEFINE_COMPONENT(::pe::api::physics2D::Box2DColliderComponent)
RTTI_DEFINE_COMPONENT(::pe::api::physics2D::Circle2DColliderComponent)

pe::api::physics2D::Box2DColliderComponent::Box2DColliderComponent(const Vector& size)
{
	Shape = std::make_unique<b2PolygonShape>();
	Shape->SetAsBox(size.X / 2, size.Y / 2);
}

pe::api::physics2D::Box2DColliderComponent::~Box2DColliderComponent()
{
}

void pe::api::physics2D::Box2DColliderComponent::SetSize(const Vector& size)
{
	Shape->SetAsBox(size.X / 2, size.Y / 2);
}


pe::api::physics2D::Circle2DColliderComponent::Circle2DColliderComponent(float size)
{
	Shape = std::make_unique<b2CircleShape>();
	Shape->m_radius = size;
}

pe::api::physics2D::Circle2DColliderComponent::~Circle2DColliderComponent()
{
}

void pe::api::physics2D::Circle2DColliderComponent::SetSize(float size)
{
	Shape->m_radius = size;
}
