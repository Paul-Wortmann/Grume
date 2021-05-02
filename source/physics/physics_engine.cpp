
#include "physics_engine.hpp"

uint32 cPhysicsEngine::initialize(void)
{
    physicsManager.initialize();
    return EXIT_SUCCESS;
}

void cPhysicsEngine::terminate(void)
{
    physicsManager.terminate();
}

void cPhysicsEngine::process(const float32 &_dt)
{
}

