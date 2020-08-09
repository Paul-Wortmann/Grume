/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */




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
    m_audio    = managerAudio.getFirst();
    m_graphics = managerGraphics.getFirst();
    m_physics  = managerPhysics.getFirst();

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

sEntity *cEntityManager::getFirstEntity(void)
{
    return m_first;
};

sEntityAnimation *cEntityManager::getFirstAnimationComponent(void)
{
    return m_animation;
};

sEntityAudio *cEntityManager::getFirstAudioComponent(void)
{
    return m_audio;
};

sEntityGraphics *cEntityManager::getFirstGraphicsComponent(void)
{
    return m_graphics;
};

sEntityPhysics *cEntityManager::getFirstPhysicsComponent(void)
{
    return m_physics;
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
