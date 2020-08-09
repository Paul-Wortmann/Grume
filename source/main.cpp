#include "defines.hpp"
#include "includes.hpp"

#include "entity_manager.hpp"
#include "graphics_engine.hpp"

int main(int argc, char **argv)
{
    // the entity manager needs to be initialized prior to any system initializations
    cEntityManager entityManager;
    entityManager.initialize();
    
    // system initializations
    cGraphicsEngine graphicsEngine;
    graphicsEngine.setEntityHandle(entityManager.getFirst());
    graphicsEngine.initialize();

    // main application loop
    graphicsEngine.process();
    
    
    // terminate systems
    graphicsEngine.terminate();
    
    // terminate the entity manager after terminating systems
    entityManager.terminate();
    return EXIT_SUCCESS;
}

