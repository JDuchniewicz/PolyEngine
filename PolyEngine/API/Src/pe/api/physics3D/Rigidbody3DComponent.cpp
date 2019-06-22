#include <EnginePCH.hpp>

#include <pe/api/physics3D/Rigidbody3DComponent.hpp>
#include <pe/api/physics3D/Rigidbody3DImpl.hpp>

RTTI_DEFINE_COMPONENT(::pe::api::physics3D::Rigidbody3DComponent)

//------------------------------------------------------------------------------
pe::api::physics3D::Rigidbody3DComponent::Rigidbody3DComponent(Scene* world, const Rigidbody3DComponentTemplate& tmp)
	: BodyWorld(world)
{
	Template = tmp;
}

//------------------------------------------------------------------------------
pe::api::physics3D::Rigidbody3DComponent::~Rigidbody3DComponent()
{
	if (Template.Registered)
		Physics3DSystem::UnregisterComponent(BodyWorld, GetOwner());
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetMassProps(float mass, const Vector& inertia)
{
	Template.Mass = mass;
	Template.Inertia = inertia;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetRestitution(float restitution)
{
	Template.Restitution = restitution;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetFriction(float friction)
{
	Template.Friction = friction;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetRollingFriction(float friction)
{
	Template.RollingFriction = friction;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetDamping(float linearDamping, float angularDamping)
{
	Template.LinearDamping = linearDamping;
	Template.AngularDamping = angularDamping;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetLinearFactor(const Vector& linearFactor)
{
	Template.LinearFactor = linearFactor;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetAngularFactor(const Vector& angularFactor)
{
	Template.AngularFactor = angularFactor;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetLinearVelocity(const Vector& velocity)
{
	Template.LinearVelocity = velocity;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetAngularVelocity(const Vector& velocity)
{
	Template.AngularVelocity = velocity;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
Poly::Vector pe::api::physics3D::Rigidbody3DComponent::GetLinearVelocity()
{
	const btVector3& v = ImplData->BulletRigidBody->getLinearVelocity();
	return Vector(v.x(), v.y(), v.z());
}

//------------------------------------------------------------------------------
Poly::Vector pe::api::physics3D::Rigidbody3DComponent::GetAngularVelocity()
{
	const btVector3& v = ImplData->BulletRigidBody->getAngularVelocity();
	return Vector(v.x(), v.y(), v.z());
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::UpdatePosition()
{
	const EntityTransform& transform = GetTransform();

	Vector localTrans = transform.GetGlobalTranslation();
	Quaternion localRot = transform.GetGlobalRotation();

	btVector3 position(localTrans.X, localTrans.Y, localTrans.Z);
	btQuaternion orientation(localRot.X, localRot.Y, localRot.Z, localRot.W);

	btTransform initialTransform;
	initialTransform.setOrigin(position);
	initialTransform.setRotation(orientation);

	ImplData->BulletRigidBody->setWorldTransform(initialTransform);
	ImplData->BulletMotionState->setWorldTransform(initialTransform);
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::ApplyImpulseToCenter(const Vector& impulse)
{
	ImpulseToCenter = impulse;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::ApplyImpulse(const Vector& impulse, const Vector& relPos)
{
	Impulse = impulse;
	ImpulsePos = relPos;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::ApplyTorqueImpulse(const Vector& torque)
{
	TorqueImpulse = torque;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Rigidbody3DComponent::SetGravity(const Vector& gravity)
{
	Template.Gravity = gravity;

	TemplateChanged = true;
}

//------------------------------------------------------------------------------
Poly::Vector pe::api::physics3D::Rigidbody3DComponent::GetGravity() const
{
	const btVector3& g = ImplData->BulletRigidBody->getGravity();
	return Vector(g.x(), g.y(), g.z());
}
