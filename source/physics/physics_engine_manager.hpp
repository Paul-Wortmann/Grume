


#ifndef PHYSICS_MANAGER_HPP
#define PHYSICS_MANAGER_HPP

#include "../includes.hpp"
#include "../linked_list.hpp"
#include "physics_define.hpp"

class cPhysicsManager : public tcLinkedList<sPhysicsObject>
{
    public:
        void initialize(void);
        void terminate(void);

    protected:

    private:
        void m_freeAll(void);
        void m_freeData(sPhysicsObject*& _object);
};

#endif // PHYSICS_MANAGER_HPP

