
#ifndef PHYISCS_DEFINE_HPP
#define PHYISCS_DEFINE_HPP

#include "../includes.hpp"

struct sPhysicsObject
{
    // Linked list management
    sPhysicsObject* next         = nullptr;

    // General information
    bool            enabled      = false;
};

#endif //PHYISCS_DEFINE_HPP

