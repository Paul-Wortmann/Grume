


#ifndef PHYSICS_ENGINE_HPP
#define PHYSICS_ENGINE_HPP

#include "../includes.hpp"
#include "../entity/entity_define.hpp"

#include "physics_define.hpp"
#include "physics_engine_manager.hpp"

class cPhysicsEngine
{
    public:
        uint32 initialize(void);
        void terminate(void);
        void process(const float32 &_dt);

    protected:
        
    private:
        cPhysicsManager physicsManager = {};
};

#endif //PHYSICS_ENGINE_HPP
