


#ifndef ENTITY_PHYSICS_HPP
#define ENTITY_PHYSICS_HPP

#include "../includes.hpp"

enum eBodyType: int16
{
    staticBody  = 0,
    dynamicBody = 1
};

struct sEntityPhysics
{
    sEntityPhysics* next          = nullptr;
    eBodyType       bodyType      = eBodyType::staticBody;
};

#endif // ENTITY_PHYSICS_HPP
