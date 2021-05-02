


#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include "../includes.hpp"
#include "../linked_list.hpp"
#include "ui_defines.hpp"
#include "../entity/entity_manager.hpp"

class cUIManager : public tcLinkedList<sUIComponent>
{
    public:
        void initialize(cEntityManager* _entityManager);
        void terminate(void);
        void load(const std::string &_fileName);

    protected:

    private:
        cEntityManager* m_entityManager = nullptr;

        void m_freeAll(void);
        void m_freeData(sUIComponent*& _pointer);

};

#endif //UI_MANAGER_HPP
