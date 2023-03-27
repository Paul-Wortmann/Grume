/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "npc_manager.hpp"

std::uint32_t cNPCManager::initialize(void)
{
    return EXIT_SUCCESS;
}

void cNPCManager::terminate(void)
{

}

void cNPCManager::m_generateWaypoints(sEntity*& _entity)
{
    // If no AI component, exit
    if (_entity->ai == nullptr)
        return;

    // Extract entity position
    const std::uint32_t tile = gMapPositionToTile(m_mapPointer, _entity->base.position);
    const std::uint32_t tx = tile % m_mapPointer->info.size_x;
    const std::uint32_t ty = tile / m_mapPointer->info.size_x;

    // If no patrol node, create it
    if (_entity->ai->patrol == nullptr)
    {
        _entity->ai->patrol = new sEntityAIPatrol;
    }

    // First delete old waypoints if they exist
    if (_entity->ai->patrol->waypoint != nullptr)
    {
        delete[] _entity->ai->patrol->waypoint;
        _entity->ai->patrol->waypoint = nullptr;
        _entity->ai->patrol->waypointCount = 0;
        _entity->ai->patrol->waypointCurrent = 0;
    }

    // random number of waypoints 2 - 5
    _entity->ai->patrol->waypointCount = 3 + (rand() % 4);
    _entity->ai->patrol->waypoint = new std::uint32_t[_entity->ai->patrol->waypointCount];

    const float PI  = 3.14159265f;

    // Calculate angle between waypoints (in radians)
    float anglePoint = static_cast<float>(360.0f / static_cast<float>(_entity->ai->patrol->waypointCount)) * static_cast<float>(PI / 180.0f);

    // Random angle offset (in radians)
    float angleBias = static_cast<float>(rand() % 360) * static_cast<float>(PI / 180.0f);

    for (std::uint32_t i = 0; i < _entity->ai->patrol->waypointCount; ++i)
    {
        // calculate angle
        float angle = (anglePoint + angleBias) * static_cast<float>(i);

        // random radius 10 - 20 tiles
        float radius = 10.0f + static_cast<float>(rand() % 10);

        // Generate each point on the circle
        std::int32_t x = static_cast<std::int32_t>((radius * cos(angle)) + static_cast<float>(tx));
        std::int32_t y = static_cast<std::int32_t>((radius * sin(angle)) + static_cast<float>(ty));

        //std::cout << "Generating point: " << x << " : " << y << std::endl;


        // check and correct tile ranges
        if (x <= 0)
            x = 0;
        if (x > static_cast<std::int32_t>(m_mapPointer->info.size_x))
            x = static_cast<std::int32_t>(m_mapPointer->info.size_x);
        if (y <= 0)
            y = 0;
        if (y > static_cast<std::int32_t>(m_mapPointer->info.size_y))
            y = static_cast<std::int32_t>(m_mapPointer->info.size_y);

        // store result
        _entity->ai->patrol->waypoint[i] = gClosestFreeTile(m_mapPointer, (y * m_mapPointer->info.size_x) + x);
    }
};

void cNPCManager::process(const std::int64_t &_dt)
{
    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        // Proceed if NPC of enemy type
        if ((m_entityTemp->base.inRnge) && (m_entityTemp->base.enabled) &&
            ((m_entityTemp->base.type == eEntityType::entityType_npc) ||
             (m_entityTemp->base.type == eEntityType::entityType_npc_fly) ||
             (m_entityTemp->base.type == eEntityType::entityType_npc_boss)))
        {
            // Particle spawn height offset
            glm::vec3 position = glm::vec3(m_entityTemp->base.position.x, m_entityTemp->base.position.y + m_entityTemp->base.particleHeight, m_entityTemp->base.position.z);

            // Character
            if ((m_entityTemp->character != nullptr) && (m_entityTemp->ai != nullptr) && (m_entityTemp->ai->state != eEntityAIState::entityAIStateCorpse))
            {
                // Process health regen
                m_entityTemp->character->attribute.health.current.amount += m_entityTemp->character->attribute.health.current.regen;
                if (m_entityTemp->character->attribute.health.current.amount > m_entityTemp->character->attribute.health.current.max)
                    m_entityTemp->character->attribute.health.current.amount = m_entityTemp->character->attribute.health.current.max;
                if (m_entityTemp->character->attribute.health.current.amount < 0.0f)
                    m_entityTemp->character->attribute.health.current.amount = 0.0f;

                // Process mana regen
                m_entityTemp->character->attribute.mana.current.amount += m_entityTemp->character->attribute.mana.current.regen;
                if (m_entityTemp->character->attribute.mana.current.amount > m_entityTemp->character->attribute.mana.current.max)
                    m_entityTemp->character->attribute.mana.current.amount = m_entityTemp->character->attribute.mana.current.max;
                if (m_entityTemp->character->attribute.mana.current.amount < 0.0f)
                    m_entityTemp->character->attribute.mana.current.amount = 0.0f;
            }

            // Update timer
            m_updateAICounter += static_cast<std::uint32_t>(_dt);

            // Ai
            if ((m_entityTemp->ai != nullptr) && (m_entityTemp->ai->state != eEntityAIState::entityAIStateCorpse))
            {
                // Only allow entity logic updates if timer ready
                if (m_updateAICounter > m_updateAIFrequency)
                {
                    // Reset timer
                    m_updateAICounter -= m_updateAIFrequency;

                    // Direction angle to face
                    float faceDirection;

                    // Calculate the distance to the player squared
                    float distancetoPlayerSqr = (((m_entityTemp->base.position.x - m_entityPlayer->base.position.x) *
                                                  (m_entityTemp->base.position.x - m_entityPlayer->base.position.x)) +
                                                 ((m_entityTemp->base.position.z - m_entityPlayer->base.position.z) *
                                                  (m_entityTemp->base.position.z - m_entityPlayer->base.position.z)));

                    // Calculate position tiles
                    std::uint32_t playerTile = gMapPositionToTile(m_mapPointer, m_entityPlayer->base.position);
                    std::uint32_t enemyTile  = gMapPositionToTile(m_mapPointer, m_entityTemp->base.position);

                    // Calculate state ranges
                    bool inRangeAttack    = (distancetoPlayerSqr < (m_entityTemp->ai->attackRange) * (m_entityTemp->ai->attackRange));
                    bool inRangePursue    = (distancetoPlayerSqr < (m_entityTemp->ai->moveRange) * (m_entityTemp->ai->moveRange));
                    bool inRangeAware     = (distancetoPlayerSqr < (m_entityTemp->ai->awareRange) * (m_entityTemp->ai->awareRange));
                    bool playerVisable    = gLineOfSight(m_mapPointer, playerTile, enemyTile);
                    bool lowHealth        = (m_entityTemp->character->attribute.health.current.amount < (m_entityTemp->character->attribute.health.current.max / 4.0));
                    bool lowHealthRetreat = (m_entityTemp->character->attribute.health.current.amount < (m_entityTemp->ai->retreatThreshold * m_entityTemp->character->attribute.health.current.max));


                    // Enable health bar for visible entities near the player
                    m_entityTemp->character->healthBarEnabled = (playerVisable && inRangePursue);

                    // If health is too low, use health spell
                    if (lowHealth)
                    {
                        // if mana -> health spell mana need, heal
                        if ((m_entityTemp->character->skill.heal.enabled) &&
                            (m_entityTemp->character->attribute.mana.current.amount > m_entityTemp->character->skill.heal.manaCost))
                        {
                            //std::cout << "Low health, healing!" << i << std::endl;
                            m_entityTemp->character->attribute.mana.current.amount -= m_entityTemp->character->skill.heal.manaCost;
                            m_entityTemp->character->attribute.health.current.amount += static_cast<float>(m_entityTemp->character->attribute.health.current.max / 2.0f);


                            // blood particles
                            m_particleEngine->spawnParticles(static_cast<eParticleType>(m_entityTemp->base.particleType), 40, position);
                        }
                    }

                    // If health is too low, retreat
                    if (lowHealthRetreat)
                    {
                        // Retreat if not already retreating
                        if (m_entityTemp->ai->state != eEntityAIState::entityAIStateRetreat)
                        {
                            m_entityTemp->ai->state = eEntityAIState::entityAIStateRetreat;
                            m_entityTemp->ai->stateChange = true;
                        }
                    }
                    // Health not low enough to retreat
                    else
                    {
                        // Cancel retreat if health has been restored
                        if (m_entityTemp->ai->state == eEntityAIState::entityAIStateRetreat)
                        {
                            m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;
                            m_entityTemp->ai->stateChange = true;
                        }
                    }

                    // If entity has dependent minions
                    if ((m_entityTemp->ai->leader != nullptr) && (m_entityTemp->ai->leader->minion != nullptr))
                    {
                        // Process current minions
                        for (std::uint32_t i = 0; i < m_entityTemp->ai->leader->minionMax; ++i)
                        {
                            sEntity *minion = static_cast<sEntity*>(m_entityTemp->ai->leader->minion[i].entity);
                            if (minion != nullptr)
                            {
                                // Minion is dead, revive
                                if (minion->ai->state == eEntityAIState::entityAIStateCorpse)
                                {
                                    if (m_entityTemp->character->attribute.mana.current.amount > static_cast<float>(m_entityTemp->ai->leader->reviveCost))
                                    {
                                        //std::cout << "Minion is dead, reviving!" << i << std::endl;
                                        m_entityTemp->character->attribute.mana.current.amount -= static_cast<float>(m_entityTemp->ai->leader->reviveCost);
                                        m_entityRevive(minion);
                                    }
                                }
                                // Minion low health: heal minion
                                else if (minion->character->attribute.health.current.amount < (minion->ai->retreatThreshold * minion->character->attribute.health.current.max))
                                {
                                    if (m_entityTemp->character->attribute.mana.current.amount > static_cast<float>(m_entityTemp->ai->leader->healCost))
                                    {
                                        //std::cout << "Minion has low health, healing!" << i << std::endl;
                                        m_entityTemp->character->attribute.mana.current.amount -= static_cast<float>(m_entityTemp->ai->leader->healCost);
                                        minion->character->attribute.health.current.amount = static_cast<float>(minion->character->attribute.health.current.max / 2.0f);

                                        // blood particles
                                        glm::vec3 minionPosition = glm::vec3(minion->base.position.x, minion->base.position.y + minion->base.particleHeight, minion->base.position.z);
                                        m_particleEngine->spawnParticles(static_cast<eParticleType>(m_entityTemp->base.particleType), 40, minionPosition);
                                        m_particleEngine->spawnParticles(static_cast<eParticleType>(m_entityTemp->base.particleType), 40, position);
                                    }
                                }
                            }
                        }
                        // If enough mana, spawn minions if not at max
                        if ((m_entityTemp->ai->leader->minionCurrent < m_entityTemp->ai->leader->minionMax) &&
                            (m_entityTemp->character->attribute.mana.current.amount > static_cast<float>(m_entityTemp->ai->leader->spawnCost)))
                        {
                            // Update minion count
                            m_entityTemp->ai->leader->minionCurrent++;

                            // Decrease mana by spawn cost
                            m_entityTemp->character->attribute.mana.current.amount -= static_cast<float>(m_entityTemp->ai->leader->spawnCost);

                            // Set a managed entity to be spawned
                            if (m_entityTemp->ai->leader->minionManaged)
                            {
                                //std::cout << "Spawning new NPC : " << m_entityTemp->ai->leader->minionCurrent << std::endl;
                                m_entityManager->spawnMinionEntities();
                                m_mapPointer->info.currentNumMob++;
                            }
                            // Spawn a non-managed entity
                            else
                            {
                                // calculate spawn position
                                glm::vec3 positionTemp = gMapTileToPosition(m_mapPointer, gClosestFreeTile(m_mapPointer, gMapPositionToTile(m_mapPointer, m_entityTemp->base.position)));
                                positionTemp.y = m_entityTemp->base.position.y;

                                // spawn entity
                                m_entityManager->spawnEntity(m_entityTemp->ai->leader->minionName, m_entityTemp->ai->leader->minionNumber, eDatabaseType::databaseTypeNpc, positionTemp);
                                m_mapPointer->info.currentNumMob++;
                            }

                            // blood particles
                            m_particleEngine->spawnParticles(static_cast<eParticleType>(m_entityTemp->base.particleType), 40, position);
                        }
                    }

                    // Process AI based on state
                    switch (m_entityTemp->ai->state)
                    {
                        // Default:
                        default:
                            // When in doubt return to an idle state
                            m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;
                        break;

                        // Idle state:
                        case eEntityAIState::entityAIStateIdle:

                            // reset the change state flag if it is set
                            if (m_entityTemp->ai->stateChange == true)
                            {
                                m_entityTemp->ai->stateChange = false;
                            }

                            // Attack player if in range
                            if ((inRangeAttack == true) && (playerVisable))
                            {
                                m_entityTemp->ai->state = eEntityAIState::entityAIStateAttack;
                                m_entityTemp->ai->stateChange = true;
                                //std::cout << "Setting state: attack" << std::endl;
                            }
                            // Pursue player if in range
                            else if ((inRangePursue == true) && (playerVisable))
                            {
                                m_entityTemp->ai->state = eEntityAIState::entityAIStatePursue;
                                m_entityTemp->ai->stateChange = true;
                                //std::cout << "Setting state: pursue" << std::endl;
                            }
                            // Observe player if in range
                            else if ((inRangeAware == true) && (m_entityTemp->movement->pathing == false))
                            {
                                // Turn to face the player
                                faceDirection = static_cast<float>(atan2(m_entityTemp->base.position.z - m_entityPlayer->base.position.z, m_entityTemp->base.position.x - m_entityPlayer->base.position.x));

                                // if not already patrolling, initiate patrol
                                if (m_entityTemp->ai->state != eEntityAIState::entityAIStatePatrol)
                                {
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStatePatrol;
                                    m_entityTemp->ai->stateChange = true;
                                    //std::cout << "Setting state: patrol" << std::endl;
                                }
                            }

                            // out of range, initiate patrol
                            else
                            {
                                // if not pathing, go on patrol
                                if (m_entityTemp->movement->pathing == false)
                                {

                                    // if not already patrolling, initiate patrol
                                    if (m_entityTemp->ai->state != eEntityAIState::entityAIStatePatrol)
                                    {
                                        m_entityTemp->ai->state = eEntityAIState::entityAIStatePatrol;
                                        m_entityTemp->ai->stateChange = true;
                                        //std::cout << "Setting state: patrol" << std::endl;
                                    }
                                }
                            }

                        break;

                        // Attack state:
                        case eEntityAIState::entityAIStateAttack:

                            // stop pathing
                            m_entityTemp->movement->pathing = false;

                            // Return AI state to idle
                            m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;

                            // Direction angle to face: player
                            faceDirection = static_cast<float>(atan2(m_entityTemp->base.position.z - m_entityPlayer->base.position.z, m_entityTemp->base.position.x - m_entityPlayer->base.position.x));

                            // Attack
                            //std::cout << "Can attack! : " << m_entityTemp->UID << std::endl;

                            m_entityTemp->ai->attackCounter += static_cast<std::uint32_t>(_dt);
                            if (m_entityTemp->ai->attackCounter > m_entityTemp->ai->attackFrequency)
                            {
                                m_entityTemp->ai->attackCounter = 0.0f;

                                // Inflict damage on the player
                                // **** this should be based on NPC strength and player defense, etc...

                                float damage = m_entityTemp->character->attribute.damagePhysical.base.amount / 2.0f;
                                m_entityPlayer->character->attribute.health.current.amount -= damage;

                                // Player death
                                if (m_entityPlayer->character->attribute.health.current.amount <= 0)
                                {
                                    m_entityPlayer->character->attribute.health.current.amount = 0;
                                    // Set state if not yet set
                                    if (m_entityPlayer->state->stateCurrent != eEntityState::entityState_idle)
                                    {
                                        m_entityManager->stateSet(m_entityPlayer, eEntityState::entityState_die);
                                    }
                                }

                                    // Set attack and defend states
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_attack)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_attack);
                                    }
                                    // Set state if not yet set
                                    if (m_entityPlayer->state->stateCurrent != eEntityState::entityState_defend)
                                    {
                                        m_entityManager->stateSet(m_entityPlayer, eEntityState::entityState_defend);
                                    }
                            }
                            else
                            {
                                // Set move idle
                                // Set state if not yet set
                                if (m_entityTemp->state->stateCurrent != eEntityState::entityState_idle)
                                {
                                    m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_idle);
                                }
                            }
                        break;

                        // Retreat state:
                        case eEntityAIState::entityAIStateRetreat:

                            // Initiate retreat
                            if (m_entityTemp->ai->stateChange == true)
                            {
                                // Reset state change flag
                                m_entityTemp->ai->stateChange = false;

                                //std::cout << "Initiating state: Retreat." << std::endl;

                                // Setup pathfinder
                                m_entityTemp->movement->mapPath.currentTile     = enemyTile;
                                m_entityTemp->movement->mapPath.startTile       = m_entityTemp->movement->mapPath.currentTile;
                                m_entityTemp->movement->mapPath.destinationTile = gClosestFreeTile(m_mapPointer, enemyTile, m_entityTemp->ai->spawnTile);

                                // Remove collision data from map prior to searching for a path to avoid false obstacle of entity
                                eTileEntityType tileEntityType = m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = 0;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                                // Attempt to path to destination
                                gAStar(m_mapPointer, m_entityTemp->movement->mapPath, m_entityTemp->base.flying, m_entityTemp->base.overSize);

                                // Return the collision data to the map after searching for a path
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = m_entityTemp->UID;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = tileEntityType;

                                if (m_entityTemp->movement->mapPath.pathLength > 0)
                                {
                                    //std::cout << "Retreat: path found: " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Path found
                                    m_entityTemp->movement->mapPath.currentPosition = 0;
                                    m_entityTemp->movement->pathing = true;

                                    // Set entity state : move
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_move)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_move);
                                    }
                                }
                                else
                                {
                                    //std::cout << "Retreat: path NOT found: " << m_entityTemp->movement->mapPath.startTile;
                                    //std::cout << " -> " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Failed to find a path
                                    m_entityTemp->movement->pathing = false;

                                    // Set AI state to idle
                                    m_entityTemp->ai->stateChange = true;
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;
                                }
                            }

                            // process retreat
                            else
                            {
                                // pathing finished, return to an idle state
                                if (m_entityTemp->movement->pathing == false)
                                {
                                    // Set AI state to idle
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;

                                    // Ensure finish pathing
                                    m_entityTemp->movement->pathing = false;

                                    // Set entity state : idle
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_idle)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_idle);
                                    }
                                }
                            }
                        break;

                        // Pursue state:
                        case eEntityAIState::entityAIStatePursue:

                            // Initiate pursue if conditions met
                            if ((m_entityTemp->ai->stateChange == true) ||
                               ((m_entityTemp->ai->lastKnownPlayerTile != m_entityPlayer->movement->mapPath.currentTile) && inRangePursue && playerVisable))
                            {
                                //std::cout << "Initiating pursue: " << std::endl;
                                // Reset state change flag
                                m_entityTemp->ai->stateChange = false;

                                // Setup pathfinder
                                m_entityTemp->ai->lastKnownPlayerTile = m_entityPlayer->movement->mapPath.currentTile;
                                m_entityTemp->movement->mapPath.destinationTile = gClosestFreeTile(m_mapPointer, enemyTile, m_entityPlayer->movement->mapPath.currentTile);
                                m_entityTemp->movement->mapPath.currentTile     = enemyTile;
                                m_entityTemp->movement->mapPath.startTile       = m_entityTemp->movement->mapPath.currentTile;

                                // Remove collision data from map prior to searching for a path to avoid false obstacle of entity
                                eTileEntityType tileEntityType = m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = 0;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                                // Attempt to path to destination
                                gAStar(m_mapPointer, m_entityTemp->movement->mapPath, m_entityTemp->base.flying, m_entityTemp->base.overSize);

                                // Return the collision data to the map after searching for a path
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = m_entityTemp->UID;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = tileEntityType;

                                if (m_entityTemp->movement->mapPath.pathLength > 0)
                                {
                                    //std::cout << "Pursue: path found: " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Path found
                                    m_entityTemp->movement->mapPath.currentPosition = 0;
                                    m_entityTemp->movement->pathing = true;

                                    // Set entity state : move
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_move)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_move);
                                    }
                                }
                                else
                                {
                                    //std::cout << "Pursue: path NOT found: " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Failed to find a path
                                    m_entityTemp->movement->pathing = false;

                                    // Set AI state to idle
                                    m_entityTemp->ai->stateChange = true;
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;
                                }
                            }

                            // Process pursue
                            else
                            {
                                // pathing finished, return to an idle state
                                if (m_entityTemp->movement->pathing == false)
                                {
                                    // Set AI state to idle
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateReturn;
                                    m_entityTemp->ai->stateChange = true;

                                    // Set entity state : move
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_move)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_move);
                                    }
                                }

                                // If in attack range, stop pursuing
                                if (inRangeAttack)
                                {
                                    // Stop pathing
                                    m_entityTemp->movement->pathing = false;

                                    // Set AI state to idle
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;

                                    // Set entity state : idle
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_idle)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_idle);
                                    }
                                }
                            }

                        break;

                        // Patrol state:
                        case eEntityAIState::entityAIStatePatrol:

                            // Initiate patrol
                            if (m_entityTemp->ai->stateChange == true)
                            {
                                // Ensure we have waypoint data
                                if ((m_entityTemp->ai->patrol == nullptr) || (m_entityTemp->ai->patrol->waypoint == nullptr))
                                {
                                    m_generateWaypoints(m_entityTemp);
                                }

                                // Reset state change flag
                                m_entityTemp->ai->stateChange = false;

                                // Setup pathfinder
                                m_entityTemp->movement->mapPath.destinationTile = gClosestFreeTile(m_mapPointer, enemyTile, m_entityTemp->ai->patrol->waypoint[m_entityTemp->ai->patrol->waypointCurrent]);
                                m_entityTemp->movement->mapPath.currentTile     = enemyTile;
                                m_entityTemp->movement->mapPath.startTile       = m_entityTemp->movement->mapPath.currentTile;

                                //std::cout << "Moving to waypoint: " << m_entityTemp->ai->patrol->waypointCurrent;
                                //std::cout << " tile: " << m_entityTemp->movement->mapPath.destinationTile << std::endl;

                                // Remove collision data from map prior to searching for a path to avoid false obstacle of entity
                                eTileEntityType tileEntityType = m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = 0;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                                // Attempt to path to destination
                                gAStar(m_mapPointer, m_entityTemp->movement->mapPath, m_entityTemp->base.flying, m_entityTemp->base.overSize);

                                // Return the collision data to the map after searching for a path
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = m_entityTemp->UID;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = tileEntityType;

                                if (m_entityTemp->movement->mapPath.pathLength > 0)
                                {
                                    //std::cout << "Patrol: path found: " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Path found
                                    m_entityTemp->movement->mapPath.currentPosition = 0;
                                    m_entityTemp->movement->pathing = true;

                                    // Set entity state : move
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_move)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_move);
                                    }
                                }
                                else
                                {
                                    //std::cout << "Patrol: path NOT found: " << m_entityTemp->movement->mapPath.startTile;
                                    //std::cout << " -> " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Failed to find a path
                                    m_entityTemp->movement->pathing = false;

                                    // Set AI state to idle
                                    m_entityTemp->ai->stateChange = true;
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;

                                    // increment waypoint count
                                    m_entityTemp->ai->patrol->waypointCurrent = (m_entityTemp->ai->patrol->waypointCurrent + 1) % m_entityTemp->ai->patrol->waypointCount;
                                }
                            }

                            // process patrol
                            else
                            {
                                // pathing finished or out of range, return to an idle state
                                if (m_entityTemp->movement->pathing == false)
                                {
                                    //std::cout << "Patrol: arrived at waypoint: " << m_entityTemp->ai->patrol->waypointCurrent << std::endl;

                                    // Ensure we have waypoint data
                                    if ((m_entityTemp->ai->patrol == nullptr) || (m_entityTemp->ai->patrol->waypoint == nullptr))
                                    {
                                        m_generateWaypoints(m_entityTemp);
                                    }

                                    // increment waypoint count
                                    m_entityTemp->ai->patrol->waypointCurrent = (m_entityTemp->ai->patrol->waypointCurrent + 1) % m_entityTemp->ai->patrol->waypointCount;

                                    // Set AI state change flag for path finder on next iteration
                                    m_entityTemp->ai->stateChange = true;
                                }

                                // If we are in range of the player and viasable, stop patroling
                                if ((inRangeAttack || inRangePursue) && playerVisable)
                                {
                                    //std::cout << "Patrol: player spotted, stopping" << std::endl;

                                    // Stop pathing
                                    m_entityTemp->movement->pathing = false;

                                    // Set AI state to idle
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;

                                    // Set entity state : idle
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_idle)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_idle);
                                    }
                                }
                            }
                        break;

                        // GoToTile state:
                        case eEntityAIState::entityAIStateGoToTile:

                            // Initiate retreat
                            if (m_entityTemp->ai->stateChange == true)
                            {
                                // Reset state change flag
                                m_entityTemp->ai->stateChange = false;

                                // Setup pathfinder
                                m_entityTemp->movement->mapPath.currentTile     = enemyTile;
                                m_entityTemp->movement->mapPath.startTile       = m_entityTemp->movement->mapPath.currentTile;

                                // Remove collision data from map prior to searching for a path to avoid false obstacle of entity
                                eTileEntityType tileEntityType = m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = 0;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                                // Attempt to path to destination
                                gAStar(m_mapPointer, m_entityTemp->movement->mapPath, m_entityTemp->base.flying, m_entityTemp->base.overSize);

                                // Return the collision data to the map after searching for a path
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = m_entityTemp->UID;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = tileEntityType;

                                if (m_entityTemp->movement->mapPath.pathLength > 0)
                                {
                                    // Path found
                                    m_entityTemp->movement->mapPath.currentPosition = 0;
                                    m_entityTemp->movement->pathing = true;

                                    // Set entity state : move
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_move)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_move);
                                    }
                                }
                                else
                                {
                                    // Failed to find a path
                                    m_entityTemp->movement->pathing = false;

                                    // Set AI state to idle
                                    m_entityTemp->ai->stateChange = true;
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;
                                }
                            }

                            // process retreat
                            else
                            {
                                // pathing finished or out of range, return to an idle state
                                if (m_entityTemp->movement->pathing == false)
                                {
                                    // Set AI state to idle
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;

                                    // Set entity state : idle
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_idle)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_idle);
                                    }
                                }
                            }
                        break;

                        // Return state:
                        case eEntityAIState::entityAIStateReturn:

                            // Initiate retreat
                            if (m_entityTemp->ai->stateChange == true)
                            {
                                // Reset state change flag
                                m_entityTemp->ai->stateChange = false;

                                //std::cout << "Initiating Retreat." << std::endl;

                                // Setup pathfinder
                                m_entityTemp->movement->mapPath.destinationTile = gClosestFreeTile(m_mapPointer, enemyTile, m_entityTemp->ai->spawnTile);
                                m_entityTemp->movement->mapPath.currentTile     = enemyTile;
                                m_entityTemp->movement->mapPath.startTile       = m_entityTemp->movement->mapPath.currentTile;

                                // Remove collision data from map prior to searching for a path to avoid false obstacle of entity
                                eTileEntityType tileEntityType = m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = 0;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                                // Attempt to path to destination
                                gAStar(m_mapPointer, m_entityTemp->movement->mapPath, m_entityTemp->base.flying, m_entityTemp->base.overSize);

                                // Return the collision data to the map after searching for a path
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = m_entityTemp->UID;
                                m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = tileEntityType;

                                if (m_entityTemp->movement->mapPath.pathLength > 0)
                                {
                                    //std::cout << "Return: path found: " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Path found
                                    m_entityTemp->movement->mapPath.currentPosition = 0;
                                    m_entityTemp->movement->pathing = true;

                                    // Set entity state : move
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_move)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_move);
                                    }
                                }
                                else
                                {
                                    //std::cout << "Return: path NOT found: " << m_entityTemp->movement->mapPath.destinationTile << std::endl;
                                    // Failed to find a path
                                    m_entityTemp->movement->pathing = false;

                                    // Set AI state to idle
                                    m_entityTemp->ai->stateChange = true;
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;
                                }
                            }

                            // process retreat
                            else
                            {
                                // pathing finished or out of range, return to an idle state
                                if (m_entityTemp->movement->pathing == false)
                                {
                                    // Set AI state to idle
                                    m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;

                                    // Set entity state : idle
                                    // Set state if not yet set
                                    if (m_entityTemp->state->stateCurrent != eEntityState::entityState_idle)
                                    {
                                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_idle);
                                    }
                                }
                            }
                        break;
                    }
                }


                // -------------------- Post-process ---------------------

                // Follow path
                if (m_entityTemp->movement->pathing == true)
                {
                    float moveSpeed = m_entityTemp->physics->acceleration * m_entityTemp->movement->speed;

                    //std::cout << "Pathing: " << moveSpeed << std::endl;

                    std::uint32_t currentTile    = m_entityTemp->movement->mapPath.path[m_entityTemp->movement->mapPath.currentPosition];
                    glm::vec3     currentTilePos = gMapTileToPosition(m_mapPointer, currentTile);

                    // Get the distance to the destination tile
                    float   distanceToTileSqr = ((m_entityTemp->base.position.x - currentTilePos.x) * (m_entityTemp->base.position.x - currentTilePos.x)) + ((m_entityTemp->base.position.z - currentTilePos.z) * (m_entityTemp->base.position.z - currentTilePos.z));

                    float   distanceToTravelSqr = m_entityTemp->physics->acceleration;// * m_entityTemp->physics->acceleration;

                    // Remove collision data from map
                    eTileEntityType tileEntityType = m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type;
                    m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = 0;
                    m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                    // Set tiles passable
                    gSetTileCollision(m_mapPointer, m_entityTemp->base.tileOnMap, false);

                    // if not center, move towards tile center
                    if (distanceToTileSqr > distanceToTravelSqr)
                    {
                        // Turn to face direction of movement
                        float angle = static_cast<float>(atan2(m_entityTemp->base.position.z - currentTilePos.z, m_entityTemp->base.position.x - currentTilePos.x));

                        if (m_entityTemp->base.rotationAxis.x != 0)
                        {
                            m_entityTemp->base.rotation.x = m_entityTemp->base.rotationOffset.x + (angle * m_entityTemp->base.rotationAxis.x);
                        }
                        else if (m_entityTemp->base.rotationAxis.y != 0)
                        {
                            m_entityTemp->base.rotation.y = m_entityTemp->base.rotationOffset.y + (angle * m_entityTemp->base.rotationAxis.y);
                        }
                        else if (m_entityTemp->base.rotationAxis.z != 0)
                        {
                            m_entityTemp->base.rotation.z = m_entityTemp->base.rotationOffset.z + (angle * m_entityTemp->base.rotationAxis.z);
                        }

                        // Move towards the tile
                        if (m_entityTemp->base.position.x < currentTilePos.x)
                        {
                            m_entityTemp->base.position.x += moveSpeed;
                            m_entityTemp->physics->velocity.x = moveSpeed;
                        }
                        if (m_entityTemp->base.position.x > currentTilePos.x)
                        {
                            m_entityTemp->base.position.x -= moveSpeed;
                            m_entityTemp->physics->velocity.x = moveSpeed * -1;
                        }
                        if (m_entityTemp->base.position.z < currentTilePos.z)
                        {
                            m_entityTemp->base.position.z += moveSpeed;
                            m_entityTemp->physics->velocity.z = moveSpeed;
                        }
                        if (m_entityTemp->base.position.z > currentTilePos.z)
                        {
                            m_entityTemp->base.position.z -= moveSpeed;
                            m_entityTemp->physics->velocity.z = moveSpeed * -1;
                        }

                    }

                    // move to tile center, set new tile in path
                    else
                    {
                        m_entityTemp->base.position.x = currentTilePos.x;
                        m_entityTemp->base.position.z = currentTilePos.z;
                        m_entityTemp->movement->mapPath.currentPosition++;
                        if (m_entityTemp->movement->mapPath.currentPosition > m_entityTemp->movement->mapPath.pathLength)
                        {
                            m_entityTemp->movement->pathing = false;

                            // Set entity state : idle
                            m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_idle);
                        }
                    }

                    // Add collision data to map
                    m_entityTemp->base.tileOnMap = gMapPositionToTile(m_mapPointer, m_entityTemp->base.position);
                    m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.UID  = m_entityTemp->UID;
                    m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = tileEntityType;

                    // Set tiles impassable
                    gSetTileCollision(m_mapPointer, m_entityTemp->base.tileOnMap, true);

                    m_entityTemp->movement->mapPath.currentTile = m_entityTemp->base.tileOnMap;
                }

                // Lastly update the entity's model matrix.
                m_entityManager->updateModelMatrix(m_entityTemp);
            }

            // Entity clicked
            if (m_entityTemp->base.clicked)
            {
                m_entityTemp->base.clicked = false;

                // Process corpse
                if ((m_entityTemp->ai != nullptr) && (m_entityTemp->ai->state == eEntityAIState::entityAIStateCorpse))
                {
                    // Corpses can't heal
                    m_entityTemp->character->attribute.health.current.amount = 0.0f;

                    // Leader has been killed
                    if (m_entityTemp->ai->leaderEntity == nullptr)
                    {
                        m_entityTemp->ai->state = eEntityAIState::entityAIStateIdle;
                    }

                }

                // Not yet a corpse
                if ((m_entityTemp->base.destructible) && (m_entityTemp->ai->state != eEntityAIState::entityAIStateCorpse))
                {
                    m_entityTemp->character->healthBarEnabled = true;
                    m_particleEngine->spawnParticles(static_cast<eParticleType>(m_entityTemp->base.particleType), 40, position);

                    // Calculate damage to NPC
                    float totalDamage = m_calculateDamage(m_entityPlayer, m_entityTemp);

                    // Modify NPC health
                    m_entityTemp->character->attribute.health.current.amount -= totalDamage;

                    // Set player state : attack
                    m_entityManager->stateSet(m_entityPlayer, eEntityState::entityState_attack);

                    // Death
                    if (m_entityTemp->character->attribute.health.current.amount <= 0.01f)
                    {
                        // Die or become a corpse
                        m_entityDeath(m_entityTemp);
                    }
                    else
                    {
                        // Set entity state : defend
                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_defend);
                    }

                    // Turn to face direction of object
                    m_entityPlayer->base.rotation.y = 1.5f - gPhysicsAngleTwoPoints(m_entityPlayer->base.position.x, m_entityPlayer->base.position.z, m_entityTemp->base.position.x, m_entityTemp->base.position.z);

                    // Update player matrix
                    m_entityManager->updateModelMatrix(m_entityPlayer);
                }
            }
        }

        // Inter-actable non-enemy NPCs: Trader
        else if ((m_entityTemp->base.enabled) && (m_entityTemp->base.type == eEntityType::entityType_npc_trader) && (m_entityTemp->base.clicked))
        {
            // Turn to face direction of NPC
            m_entityPlayer->base.rotation.y = 1.5f - gPhysicsAngleTwoPoints(m_entityPlayer->base.position.x, m_entityPlayer->base.position.z, m_entityTemp->base.position.x, m_entityTemp->base.position.z);

            // Entity clicked
            m_entityTemp->base.clicked = false;

            // Set entity state : interact
            m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_interact);

            // Event: close all menus
            sNPCManagerEvent* event_1 = new sNPCManagerEvent;
            event_1->type = eNPCEventType::NPCEventType_menu;
            event_1->data = eNPCEventData::NPCEventData_menuCloseAll;
            m_event.push(event_1);

            // Event: open vendor menu
            sNPCManagerEvent* event_2 = new sNPCManagerEvent;
            event_2->type = eNPCEventType::NPCEventType_menu;
            event_2->data = eNPCEventData::NPCEventData_menuVendor;
            m_event.push(event_2);

            // Event: open inventory menu
            sNPCManagerEvent* event_3 = new sNPCManagerEvent;
            event_3->type = eNPCEventType::NPCEventType_menu;
            event_3->data = eNPCEventData::NPCEventData_menuInventory;
            m_event.push(event_3);

            // Lastly update the player's model matrix.
            m_entityManager->updateModelMatrix(m_entityPlayer);
        }

        // Inter-actable non-enemy NPCs: Quest
        else if ((m_entityTemp->base.enabled) && (m_entityTemp->base.type == eEntityType::entityType_npc_quest) && (m_entityTemp->base.clicked))
        {
            // Turn to face direction of NPC
            m_entityPlayer->base.rotation.y = 1.5f - gPhysicsAngleTwoPoints(m_entityPlayer->base.position.x, m_entityPlayer->base.position.z, m_entityTemp->base.position.x, m_entityTemp->base.position.z);

            // Entity clicked
            m_entityTemp->base.clicked = false;

            // Set entity state : interact
            m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_interact);



            // Do quest stuff here.....



            // Lastly update the player's model matrix.
            m_entityManager->updateModelMatrix(m_entityPlayer);
        }
    }

    // Reset flags
    m_updatePaths = false;
}

void cNPCManager::m_entityDeath(sEntity*& _entity)
{
    // If minion has a leader, become a corpse
    if ((_entity->ai != nullptr) && (_entity->ai->leaderEntity != nullptr))
    {
        _entity->character->healthBarEnabled = false;
        _entity->ai->state = eEntityAIState::entityAIStateCorpse;
        _entity->graphics->model = m_resourceManager->loadModel(_entity->ai->modelCorpse);
        m_graphicsEngine->initializeEntity(_entity);
        _entity->physics->type = ePhysicsType::physicsTypeNone;
    }
    //Else die and give loot and experience
    else
    {
        // Avoid unintended mouse clicks
        m_io->keyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
        m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
        m_io->keyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;
        m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;

        // Update map mob count
        m_mapPointer->info.currentNumMob--;

        // Screen shake on NPC death
        if ((_entity->base.deathShakeChance > 0) && (static_cast<std::uint32_t>(rand() % 101) < _entity->base.deathShakeChance))
        {
            m_graphicsEngine->addScreenShake(_entity->base.deathShakeDuration, _entity->base.deathShakeForce);
        }

        // Set entity state : die
        m_entityManager->stateSet(_entity, eEntityState::entityState_die);
        _entity->base.dying = true;

        // If leader, release managed minions
        if ((_entity->ai != nullptr) && (_entity->ai->leader != nullptr))
        {
            for (std::uint32_t i = 0; i < _entity->ai->leader->minionMax; ++i)
            {
                if (_entity->ai->leader->minion[i].entity != nullptr)
                {
                    sEntity *minion = static_cast<sEntity*>(_entity->ai->leader->minion[i].entity);
                    minion->ai->leaderEntity = nullptr;
                    _entity->ai->leader->minion[i].entity = nullptr;

                    // if the minion is a corpse, kill it
                    if (minion->ai->state == eEntityAIState::entityAIStateCorpse)
                    {
                        m_entityDeath(minion);
                    }
                }
            }
        }

        // Calculate spawn position
        glm::vec3 spawnPosition = _entity->base.position;
        spawnPosition.y = m_mapPointer->info.terrainHeight -1.0f;

        // Gib drop
        std::uint32_t gibCount = m_databaseManager->getDatabaseEntryCount(_entity->base.debris, eDatabaseType::databaseTypeObject);
        for (std::uint32_t i = 0; i < gibCount; ++i)
        {
            glm::vec3 gibPosition = spawnPosition;
            gibPosition.x += static_cast<float>(1.0 - (gRandFloatNormalized() * 2.0));
            gibPosition.z += static_cast<float>(1.0 - (gRandFloatNormalized() * 2.0));
            sEntity* tEntity = nullptr;
            tEntity = m_particleEngine->spawnEntity(_entity->base.debris, i + 1, eDatabaseType::databaseTypeObject, gibPosition);

            // if the entity was loaded
            if (tEntity != nullptr)
            {
                // variation: position
                float posX = gRandFloatNormalized() - 1.0f;
                float posZ = gRandFloatNormalized() - 1.0f;
                tEntity->base.position.x += posX;
                tEntity->base.position.z += posZ;

                // variation: rotation
                float rotation = static_cast<float>(gRandFloatNormalized() * M_PI * 2.0f);
                tEntity->base.rotation.x = rotation * tEntity->base.rotationAxis.x;
                tEntity->base.rotation.y = rotation * tEntity->base.rotationAxis.y;
                tEntity->base.rotation.z = rotation * tEntity->base.rotationAxis.z;

                // Update model matrix
                m_entityManager->updateModelMatrix(tEntity);
            }

            // blood particles
            glm::vec3 position = glm::vec3(gibPosition.x, gibPosition.y + _entity->base.particleHeight, gibPosition.z);
            m_particleEngine->spawnParticles(static_cast<eParticleType>(_entity->base.particleType), 40, position);
        }

        // Loot
        if (_entity->loot != nullptr)
        {
            // Gold
            if (_entity->loot->gold > 0)
            {
                for (uint32_t i = 0; i < _entity->loot->gold; ++i)
                {
                    std::uint32_t gold = _entity->loot->gold_min;
                    gold += rand() % (_entity->loot->gold_max - _entity->loot->gold_min);

                    // spawn coins
                    sEntity* tEntity = nullptr;
                    tEntity = m_particleEngine->spawnEntity("coins", 0, eDatabaseType::databaseTypeItem, spawnPosition);

                    // If entity could be loaded
                    if (tEntity != nullptr)
                    {
                        // text tool-tip
                        tEntity->base.textActive  = true;
                        tEntity->base.textData    = std::to_string(gold);
                        tEntity->base.collectable = true;

                        // gold loot
                        tEntity->loot->gold       = 1;
                        tEntity->loot->gold_min   = gold;
                        tEntity->loot->gold_max   = gold;

                        // placement variation: position
                        float posX = gRandFloatNormalized() - 1.0f;
                        float posZ = gRandFloatNormalized() - 1.0f;
                        tEntity->base.position.x += posX;
                        tEntity->base.position.z += posZ;

                        // placement variation: rotation
                        tEntity->base.rotation.y = static_cast<float>(gRandFloatNormalized() * M_PI * 2.0f); // random angle

                        // Update model matrix
                        m_entityManager->updateModelMatrix(tEntity);
                    }
                }
            }

            // Experience
            if ((_entity->loot->experience) && (m_entityPlayer->character->level.current != m_entityPlayer->character->level.max))
            {
                std::uint32_t exp = _entity->loot->experience_min;
                exp += rand() % (_entity->loot->experience_max - _entity->loot->experience_min);
                m_entityPlayer->character->level.exp += exp;

                // Check experience and push a level up event
                if (m_entityPlayer->character->level.exp >= m_entityPlayer->character->level.expNext)
                {
                    sNPCManagerEvent* event = new sNPCManagerEvent;
                    event->type = eNPCEventType::NPCEventType_player;
                    event->data = eNPCEventData::NPCEventData_levelUp;
                    m_event.push(event);
                }
            }

            // Get item from the loot table
            std::string   itemDatabaseName   = {};
            std::uint32_t itemDatabaseNumber = 0;
            m_lootManager->getLoot(_entity->loot->itemID, itemDatabaseName, itemDatabaseNumber);

            // Spawn item
            if (_entity->loot->itemID != 0)
            {
                // spawn loot
                sEntity* tEntity = nullptr;
                tEntity = m_particleEngine->spawnEntity(itemDatabaseName, itemDatabaseNumber, eDatabaseType::databaseTypeItem, spawnPosition);

                // if loot could be spawned
                if (tEntity != nullptr)
                {
                    // Save database data if an item
                    tEntity->base.databaseName = itemDatabaseName;
                    tEntity->base.databaseNumber = itemDatabaseNumber;

                    // variation: position
                    float posX = gRandFloatNormalized() - 1.0f;
                    float posZ = gRandFloatNormalized() - 1.0f;
                    tEntity->base.position.x += posX;
                    tEntity->base.position.z += posZ;

                    // variation: rotation
                    float rotation = static_cast<float>(gRandFloatNormalized() * M_PI * 2.0f);
                    tEntity->base.rotation.x = rotation * tEntity->base.rotationAxis.x;
                    tEntity->base.rotation.y = rotation * tEntity->base.rotationAxis.y;
                    tEntity->base.rotation.z = rotation * tEntity->base.rotationAxis.z;

                    // Update model matrix
                    m_entityManager->updateModelMatrix(tEntity);

                    // text tooltip
                    tEntity->base.textActive  = true;
                    tEntity->base.collectable = true;

                    // Add loot component
                    if (tEntity->loot == nullptr)
                    {
                        tEntity->loot = new sEntityLoot;
                    }

                }
            }

        }

        // set on death quest data
        if (_entity->quest != nullptr)
        {
            m_questManager->setQuest(_entity->quest->onDeath.questName, _entity->quest->onDeath.setState);
        }

        // Last, remove the entity from the game
        _entity->character->healthBarEnabled = false;
        _entity->base.dying = true;
        m_entityManager->deleteEntity(_entity);
    }
}

void cNPCManager::m_entityRevive(sEntity*& _entity)
{
    _entity->character->attribute.health.current.amount = _entity->character->attribute.health.current.max;
    _entity->ai->state = eEntityAIState::entityAIStateIdle;
    _entity->graphics->model = m_resourceManager->loadModel(_entity->ai->modelAlive);
    m_graphicsEngine->initializeEntity(_entity);
    _entity->physics->type = ePhysicsType::physicsTypeDynamic;

    // blood particles
    glm::vec3 position = glm::vec3(_entity->base.position.x, _entity->base.position.y + _entity->base.particleHeight, _entity->base.position.z);
    m_particleEngine->spawnParticles(static_cast<eParticleType>(_entity->base.particleType), 40, position);

}

float cNPCManager::m_calculateDamage(sEntity* _entity_1, sEntity* _entity_2)
{
    // Damage totals
    float physicalDamage  = 0.0f;
    float fireDamage      = 0.0f;
    float iceDamage       = 0.0f;
    float lightningDamage = 0.0f;
    float totalDamage     = 0.0f;

    // Defense totals
    float physicalDefense  = 0.0f;
    float fireDefense      = 0.0f;
    float iceDefense       = 0.0f;
    float lightningDefense = 0.0f;
    float totalDefense     = 0.0f;

    // Critical hit
    bool  physicalCrit     = (static_cast<float>(rand() % 100) < _entity_1->character->attribute.damagePhysical.current.critChance);
    bool  fireCrit         = (static_cast<float>(rand() % 100) < _entity_1->character->attribute.damageFire.current.critChance);
    bool  iceCrit          = (static_cast<float>(rand() % 100) < _entity_1->character->attribute.damageIce.current.critChance);
    bool  lightningCrit    = (static_cast<float>(rand() % 100) < _entity_1->character->attribute.damageLightning.current.critChance);

    // Block hit
    bool  physicalBlock    = (static_cast<float>(rand() % 100) < _entity_2->character->attribute.armorPhysical.current.blockChance);
    bool  fireBlock        = (static_cast<float>(rand() % 100) < _entity_2->character->attribute.resistanceFire.current.blockChance);
    bool  iceBlock         = (static_cast<float>(rand() % 100) < _entity_2->character->attribute.resistanceIce.current.blockChance);
    bool  lightningBlock   = (static_cast<float>(rand() % 100) < _entity_2->character->attribute.resistanceLightning.current.blockChance);

    // Physical damage
    physicalDamage = _entity_1->character->attribute.damagePhysical.current.amount;
    if (physicalCrit)
        physicalDamage += _entity_1->character->attribute.damagePhysical.current.amount * _entity_1->character->attribute.damagePhysical.current.critMultiplier;

    // Fire damage
    fireDamage = _entity_1->character->attribute.damageFire.current.amount;
    if (fireCrit)
        fireDamage += _entity_1->character->attribute.damageFire.current.amount * _entity_1->character->attribute.damageFire.current.critMultiplier;

    // Ice damage
    iceDamage = _entity_1->character->attribute.damageIce.current.amount;
    if (iceCrit)
        iceDamage += _entity_1->character->attribute.damageIce.current.amount * _entity_1->character->attribute.damageIce.current.critMultiplier;

    // Lightning damage
    lightningDamage = _entity_1->character->attribute.damageLightning.current.amount;
    if (lightningCrit)
        lightningDamage += _entity_1->character->attribute.damageLightning.current.amount * _entity_1->character->attribute.damageLightning.current.critMultiplier;

    // Armor / Resistance

    // Physical armor
    physicalDefense = _entity_2->character->attribute.armorPhysical.current.amount;
    if (physicalBlock)
        physicalDefense += _entity_2->character->attribute.armorPhysical.current.amount * _entity_2->character->attribute.armorPhysical.current.blockPercent;

    // Fire armor
    fireDefense = _entity_2->character->attribute.resistanceFire.current.amount;
    if (fireBlock)
        fireDefense += _entity_2->character->attribute.resistanceFire.current.amount * _entity_2->character->attribute.resistanceFire.current.blockPercent;

    // Ice armor
    iceDefense = _entity_2->character->attribute.resistanceIce.current.amount;
    if (iceBlock)
        iceDefense += _entity_2->character->attribute.resistanceIce.current.amount * _entity_2->character->attribute.resistanceIce.current.blockPercent;

    // Lightning armor
    lightningDefense = _entity_2->character->attribute.resistanceLightning.current.amount;
    if (lightningBlock)
        lightningDefense += _entity_2->character->attribute.resistanceLightning.current.amount * _entity_2->character->attribute.resistanceLightning.current.blockPercent;



    // Note: this does not factor in NPC armor / resistance
    // Note: this does not factor in damage types
    // Note: we should calculate total damage and total armor first before applying it
    // Note: rand() for crit does not factor in max chance or player level

    // Crit damage
    if (static_cast<float>(rand() % 100) < _entity_1->character->attribute.damagePhysical.current.critChance)
    {
        totalDamage = _entity_1->character->attribute.damagePhysical.current.amount * _entity_1->character->attribute.damagePhysical.current.critMultiplier;
        totalDamage += _entity_1->character->attribute.damagePhysical.current.amount;
    }
    else
    // Normal damage
    {
        totalDamage = _entity_1->character->attribute.damagePhysical.current.amount;
    }
    return totalDamage;
}
