


#ifndef NPC_MANAGER_HPP
#define NPC_MANAGER_HPP

#include "../includes.hpp"
#include "../linked_list.hpp"
#include "npc_define.hpp"

class cNPCManager : public tcLinkedList<sNPC>
{
    public:
        void initialize(void);
        void terminate(void);

    protected:

    private:
        void m_freeAll(void);
        void m_freeData(sNPC*& _pointer);
};

#endif //NPC_MANAGER_HPP
