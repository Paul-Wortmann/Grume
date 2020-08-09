




#include "entity_manager_physics.hpp"

cEntityManagerPhysics::cEntityManagerPhysics(void)
{
    
};

cEntityManagerPhysics::~cEntityManagerPhysics(void)
{
    
};

void cEntityManagerPhysics::initialize(void)
{
    // initialize the entity manager
    m_numEntities = 0;
    if (m_first != nullptr)
    {
        m_freeEntities();
    }
    m_first = new sEntityPhysics;
    m_last  = m_first;
};

void cEntityManagerPhysics::terminate(void)
{
    //terminate entity manager
    m_freeEntities();
    m_numEntities = 0;
};

void cEntityManagerPhysics::m_freeEntities(void)
{
    if (m_first != nullptr)
    {
        sEntityPhysics *entityDel = m_first;
        for(m_temp = m_first->next; m_temp != nullptr; m_temp = m_temp->next)
        {
            if (entityDel != nullptr)
            {
                m_freeEntityData(entityDel);
                delete entityDel;
                entityDel = nullptr;
            }
            entityDel = m_temp;
        }
        if (entityDel != nullptr)
        {
            m_freeEntityData(entityDel);
            delete entityDel;
            entityDel = nullptr;
        }
    }
    m_first = nullptr;
    m_last  = nullptr;
    m_temp  = nullptr;
    m_numEntities = 0;    
};

void cEntityManagerPhysics::m_freeEntityData(sEntityPhysics *_entity)
{

};

sEntityPhysics *cEntityManagerPhysics::getNew(void)
{
    if (m_numEntities == 0)
    {
        if (m_first == nullptr)
        {
            m_first = new sEntityPhysics;
        }
        m_last = m_first;
    }
    else
    {
        m_last->next = new sEntityPhysics;
        m_last = m_last->next;
    }
    m_numEntities++;
    return m_last;
};

sEntityPhysics *cEntityManagerPhysics::getFirst(void)
{
    return m_first;
};
