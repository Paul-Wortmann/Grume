




#include "entity_manager_audio.hpp"

cEntityManagerAudio::cEntityManagerAudio(void)
{
    
};

cEntityManagerAudio::~cEntityManagerAudio(void)
{
    
};

void cEntityManagerAudio::initialize(void)
{
    // initialize the entity manager
    m_numEntities = 0;
    if (m_first != nullptr)
    {
        m_freeEntities();
    }
    m_first = new sEntityAudio;
    m_last  = m_first;
};

void cEntityManagerAudio::terminate(void)
{
    //terminate entity manager
    m_freeEntities();
    m_numEntities = 0;
};

void cEntityManagerAudio::m_freeEntities(void)
{
    if (m_first != nullptr)
    {
        sEntityAudio *entityDel = m_first;
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

void cEntityManagerAudio::m_freeEntityData(sEntityAudio *_entity)
{

};

sEntityAudio *cEntityManagerAudio::getNew(void)
{
    if (m_numEntities == 0)
    {
        if (m_first == nullptr)
        {
            m_first = new sEntityAudio;
        }
        m_last = m_first;
    }
    else
    {
        m_last->next = new sEntityAudio;
        m_last = m_last->next;
    }
    m_numEntities++;
    return m_last;
};

sEntityAudio *cEntityManagerAudio::getFirst(void)
{
    return m_first;
};
