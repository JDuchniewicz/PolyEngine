#include <EnginePCH.hpp>

#include <pe/api/physics3D/Collider3DImpl.hpp>
#include <pe/api/physics3D/Physics3DShapes.hpp>
#include <pe/api/physics3D/Physics3DShapesImpl.hpp>
#include <pe/api/physics3D/Rigidbody3DComponent.hpp>

RTTI_DEFINE_COMPONENT(pe::api::physics3D::Collider3DComponent)

//------------------------------------------------------------------------------
pe::api::physics3D::Collider3DComponent::Collider3DComponent(Scene* world, Collider3DComponentTemplate&& tmp)
	: BodyWorld(world)
{
	Template.Shape = std::move(tmp.Shape);
	Template.Registered = tmp.Registered;
	Template.CollisionGroup = tmp.CollisionGroup;
	Template.CollisionMask = tmp.CollisionMask;
}

//------------------------------------------------------------------------------
pe::api::physics3D::Collider3DComponent::~Collider3DComponent()
{
	Rigidbody3DComponent* rigidbody = GetSibling<Rigidbody3DComponent>();

	// if rigidbody exists and is NOT registered and collider is registered
	// or
	// if rigidbody doesnt't exist and collider is registered
	if ((rigidbody && !rigidbody->IsRegistered() && Template.Registered)
		|| (!rigidbody && Template.Registered))
	{
		Physics3DSystem::UnregisterComponent(BodyWorld, GetOwner());
	}
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Collider3DComponent::SetShape(const Physics3DShape* shape)
{
	Template.Shape.release();
	Template.Shape = std::make_unique<Physics3DShape>(*shape);
	ImplData->BulletTrigger->setCollisionShape(Template.Shape->ImplData->BulletShape);
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Collider3DComponent::UpdatePosition()
{
	const EntityTransform& transform = GetTransform();

	Vector localTrans = transform.GetGlobalTranslation();
	Quaternion localRot = transform.GetGlobalRotation();

	btVector3 position(localTrans.X, localTrans.Y, localTrans.Z);
	btQuaternion orientation(localRot.X, localRot.Y, localRot.Z, localRot.W);

	btTransform initialTransform;
	initialTransform.setOrigin(position);
	initialTransform.setRotation(orientation);

	ImplData->BulletTrigger->setWorldTransform(initialTransform);
}
