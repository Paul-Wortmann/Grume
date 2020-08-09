




#include "entity_manager.hpp"

cEntityManager::cEntityManager(void)
{
    
};

cEntityManager::~cEntityManager(void)
{
    
};

void cEntityManager::initialize(void)
{
    // initialize entity component managers
    managerAudio.initialize();
    managerGraphics.initialize();
    managerPhysics.initialize();

    // initialize the entity manager
    m_numEntities = 0;
    if (m_first != nullptr)
    {
        m_freeEntities();
    }
    m_first = new sEntity;
    m_last  = m_first;
};

void cEntityManager::terminate(void)
{
    // terminate entity components first
    managerAudio.terminate();
    managerGraphics.terminate();
    managerPhysics.terminate();

    //terminate entity manager
    m_freeEntities();
    m_numEntities = 0;
};

void cEntityManager::m_freeEntities(void)
{
    if (m_first != nullptr)
    {
        sEntity *entityDel = m_first;
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

void cEntityManager::m_freeEntityData(sEntity *_entity)
{
    // audio entity compnent 
    if (_entity->audio != nullptr)
    {
        delete _entity->audio;
        _entity->audio = nullptr;
    }

    // graphics entity compnent 
    if (_entity->graphics != nullptr)
    {
        delete _entity->graphics;
        _entity->graphics = nullptr;
    }

    // physics entity compnent 
    if (_entity->physics != nullptr)
    {
        delete _entity->physics;
        _entity->physics = nullptr;
    }
};

sEntity *cEntityManager::getNew(void)
{
    if (m_numEntities == 0)
    {
        if (m_first == nullptr)
        {
            m_first = new sEntity;
        }
        m_last = m_first;
    }
    else
    {
        m_last->next = new sEntity;
        m_last = m_last->next;
    }
    m_numEntities++;
    return m_last;
};

sEntity *cEntityManager::getFirst(void)
{
    return m_first;
};

void cEntityManager::addComponentAudio(sEntity *_entity)
{
    if (_entity->audio != nullptr)
    {
        _entity->audio = managerAudio.getNew();
    }
};

void cEntityManager::addComponentGraphics(sEntity *_entity)
{
    if (_entity->graphics != nullptr)
    {
        _entity->graphics = managerGraphics.getNew();
    }
};

void cEntityManager::addComponentPhysics(sEntity *_entity)
{
    if (_entity->physics != nullptr)
    {
        _entity->physics = managerPhysics.getNew();
    }
};
