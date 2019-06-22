#include <EnginePCH.hpp>

#include <pe/api/physics3D/Physics3DWorldComponent.hpp>

RTTI_DEFINE_COMPONENT(pe::api::physics3D::Physics3DWorldComponent)

//------------------------------------------------------------------------------
pe::api::physics3D::Physics3DWorldComponent::Physics3DWorldComponent(Physics3DConfig config)
	: Config(config)
{
	CollisionConfiguration = std::make_unique<btDefaultCollisionConfiguration>();
	Dispatcher = std::make_unique<btCollisionDispatcher>(CollisionConfiguration.get());
	Broadphase = std::make_unique<btDbvtBroadphase>();
	Solver = std::make_unique<btSequentialImpulseConstraintSolver>();
	DynamicsWorld = std::make_unique<btDiscreteDynamicsWorld>(Dispatcher.get(), Broadphase.get(), Solver.get(), CollisionConfiguration.get());

	// set default gravity
	DynamicsWorld->setGravity(btVector3(config.Gravity.X, config.Gravity.Y, config.Gravity.Z));
}

//------------------------------------------------------------------------------
pe::api::physics3D::Physics3DWorldComponent::~Physics3DWorldComponent()
{
	DynamicsWorld.release();
	Solver.release();
	Broadphase.release();
	Dispatcher.release();
	CollisionConfiguration.release();
}

//------------------------------------------------------------------------------
void pe::api::physics3D::Physics3DWorldComponent::SetGravity(const Vector& g)
{
	Config.Gravity = g;
	DynamicsWorld->setGravity(btVector3(g.X, g.Y, g.Z));
}

void pe::api::physics3D::Physics3DWorldComponent::SetTimeStep(float timestep)
{
	Config.TimeStep = timestep;
}