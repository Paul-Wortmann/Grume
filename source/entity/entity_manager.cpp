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

#include "entity_manager.hpp"

std::uint32_t cEntityManager::initialize(void)
{
    return EXIT_SUCCESS;
}

void cEntityManager::terminate(void)
{
    freeAll();
}

void cEntityManager::freeData(sEntity*& _pointer)
{
    // AI
    if (_pointer->ai != nullptr)
    {
        // Leader
        if (_pointer->ai->leader != nullptr)
        {
            // Minions
            if (_pointer->ai->leader->minion != nullptr)
            {
                delete[] _pointer->ai->leader->minion;
                _pointer->ai->leader->minion = nullptr;
            }

            delete _pointer->ai->leader;
            _pointer->ai->leader = nullptr;
        }

        // Patrol
        if (_pointer->ai->patrol != nullptr)
        {
            // Waypoints
            if (_pointer->ai->patrol->waypoint != nullptr)
            {
                delete[] _pointer->ai->patrol->waypoint;
                _pointer->ai->patrol->waypoint = nullptr;
            }

            delete _pointer->ai->patrol;
            _pointer->ai->patrol = nullptr;
        }

        // AI
        delete _pointer->ai;
        _pointer->ai = nullptr;
    }

    // Animation
    if (_pointer->animation != nullptr)
    {
        // Bone transform
        if (_pointer->animation->boneTransform != nullptr)
        {
            delete[] _pointer->animation->boneTransform;
            _pointer->animation->boneTransform = nullptr;
        }

        delete _pointer->animation;
        _pointer->animation = nullptr;
    }

    // Base
    _pointer->base.name            = {};
    _pointer->base.enabled         = true;
    _pointer->base.dying           = false;
    _pointer->base.type            = eEntityType::entityType_none;
    _pointer->base.owner           = eEntityOwner::entityOwner_none;
    _pointer->base.tileOnMap       = 0;

    _pointer->base.hitPoints       = 40; // Used for objects that can take damage
    _pointer->base.debris          = {};
    _pointer->base.clicked         = false;
	_pointer->base.destructible    = false;
	_pointer->base.collectable     = false;
	_pointer->base.interactable    = false;
	_pointer->base.flexibility     = 0.0f;

    _pointer->base.textActive      = false;
    _pointer->base.textHover       = false;
    _pointer->base.textData        = {};

    _pointer->base.position        = glm::vec3(0.0f, 0.0f, 0.0f);
    _pointer->base.rotation        = glm::vec3(0.0f, 0.0f, 0.0f);
    _pointer->base.rotationOffset  = glm::vec3(0.0f, 0.0f, 0.0f);
    _pointer->base.rotationAxis    = glm::vec3(0.0f, 1.0f, 0.0f);
    _pointer->base.scale           = glm::vec3(1.0f, 1.0f, 1.0f);

    _pointer->base.initialized     = false;
    _pointer->base.hasFunction     = false;

    // Character
    if (_pointer->character != nullptr)
    {
        // Health bar material
        if (_pointer->character->healthBarmaterial != nullptr)
        {
            delete[] _pointer->character->healthBarmaterial;
            _pointer->character->healthBarmaterial = nullptr;
        }

        delete _pointer->character;
        _pointer->character = nullptr;
    }

    // Footprint
    if (_pointer->footprint != nullptr)
    {
        // Footprint data
        if (_pointer->footprint->data != nullptr)
        {
            delete[] _pointer->footprint->data;
            _pointer->footprint->data = nullptr;
        }
        delete _pointer->footprint;
        _pointer->footprint = nullptr;
    }

    // Graphics
    if (_pointer->graphics != nullptr)
    {
        // Material
        if (_pointer->graphics->material != nullptr)
        {
            delete[] _pointer->graphics->material;
            _pointer->graphics->material = nullptr;
        }

        delete _pointer->graphics;
        _pointer->graphics = nullptr;
    }

    // Interaction
    if (_pointer->interaction != nullptr)
    {
        delete _pointer->interaction;
        _pointer->interaction = nullptr;
    }

    // Loot
    if (_pointer->loot != nullptr)
    {
        delete _pointer->loot;
        _pointer->loot = nullptr;
    }

    // Movement
    if (_pointer->movement != nullptr)
    {
        if (_pointer->movement->mapPath.path != nullptr)
        {
            delete[] _pointer->movement->mapPath.path;
            _pointer->movement->mapPath.path = nullptr;
        }
        delete _pointer->movement;
        _pointer->movement = nullptr;
    }

    // Particle
    if (_pointer->particle != nullptr)
    {
        delete _pointer->particle;
        _pointer->particle = nullptr;
    }

    // Physics
    if (_pointer->physics != nullptr)
    {
        delete _pointer->physics;
        _pointer->physics = nullptr;
    }

    // Quest
    if (_pointer->quest != nullptr)
    {
        delete _pointer->quest;
        _pointer->quest = nullptr;
    }

    // State
    if (_pointer->state != nullptr)
    {
        // Audio
        m_audioEngine->deleteSound(_pointer->state->attack.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->close.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->defend.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->die.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->idle.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->interact.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->levelUp.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->move.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->open.audio.sound);
        m_audioEngine->deleteSound(_pointer->state->spawn.audio.sound);

        delete _pointer->state;
        _pointer->state = nullptr;
    }

    // Tile Collision
    if (_pointer->tileCollision != nullptr)
    {
        if (_pointer->tileCollision->data != nullptr)
        {
            delete[] _pointer->tileCollision->data;
            _pointer->tileCollision->data = nullptr;
        }

        delete _pointer->tileCollision;
        _pointer->tileCollision = nullptr;
    }

}

void cEntityManager::updateModelMatrix(sEntity*& _entity)
{
    if ((_entity != nullptr) && (_entity->graphics != nullptr))
    {
        // 1. Translation
        glm::mat4 translationMatrix = glm::translate(glm::mat4(1), _entity->base.position);

        // 2. Rotation
        glm::mat4 rotationMatrix = glm::mat4(1);
        rotationMatrix = glm::rotate(rotationMatrix, _entity->base.rotation.x, glm::vec3(1, 0, 0));
        rotationMatrix = glm::rotate(rotationMatrix, _entity->base.rotation.y, glm::vec3(0, 1, 0));
        rotationMatrix = glm::rotate(rotationMatrix, _entity->base.rotation.z, glm::vec3(0, 0, 1));

        // 3. Scale
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1), _entity->base.scale);

        // 4. Finally calculate the model matrix
        _entity->graphics->modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
    }
}

sEntity* cEntityManager::getEntity(const std::uint32_t &_ID)
{
    for (sEntity* tEntity = getHead(); tEntity != nullptr; tEntity = tEntity->next)
    {
        if (tEntity->UID == _ID)
            return tEntity;
    }
    return nullptr;
}

sEntity* cEntityManager::getEntityOnTile(const std::uint32_t &_tile)
{
    for (sEntity* tEntity = getHead(); tEntity != nullptr; tEntity = tEntity->next)
    {
        if ((tEntity->base.tileOnMap == _tile) && (tEntity->base.type == eEntityType::entityType_objectStatic))
            return tEntity;
    }
    return nullptr;
}

void cEntityManager::process(const std::int64_t &_dt)
{
        //std::cout << "Range check: " << _dt << std::endl;
    m_rangeUpdateTime += static_cast<float>(_dt);
    if (m_rangeUpdateTime > m_rangeUpdateMax)
    {
        m_rangeUpdateTime -= m_rangeUpdateMax;
        // Calculate range based on player position
        float range_x_min = m_range_x_min + m_playerEntity->base.position.x;
        float range_x_max = m_range_x_max + m_playerEntity->base.position.x;
        float range_z_min = m_range_z_min + m_playerEntity->base.position.z;
        float range_z_max = m_range_z_max + m_playerEntity->base.position.z;

        for (sEntity* tEntity = getHead(); tEntity != nullptr; tEntity = tEntity->next)
        {
            // Range check and set
            tEntity->base.inRnge = ((tEntity->base.position.x > range_x_min) &&
                                    (tEntity->base.position.x < range_x_max) &&
                                    (tEntity->base.position.z > range_z_min) &&
                                    (tEntity->base.position.z < range_z_max));
            // process dying entities
            if (tEntity->base.dying)
            {
                bool soundPlayingDie = false;
                if ((tEntity->state != nullptr) && (tEntity->state->die.audio.sound != nullptr))
                    soundPlayingDie = ma_sound_is_playing(&tEntity->state->die.audio.sound->data);

                bool soundPlayingInteract = false;
                if ((tEntity->state != nullptr) && (tEntity->state->interact.audio.sound != nullptr))
                    soundPlayingDie = ma_sound_is_playing(&tEntity->state->interact.audio.sound->data);

                if ((soundPlayingDie == false) && (soundPlayingInteract == false))
                {
                    freeData(tEntity);
                    tEntity->base.dying = false;
                    tEntity->base.inRnge = false;
                }
            }
        }
    }
}

sEntity* cEntityManager::load(const std::string &_fileName)
{
    // This is probably an invalid file name, or an empty string
    if (_fileName.length() < 5)
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return nullptr;
    }

    sEntity* tEntity = nullptr;
    cXML xmlEntityFile;
    xmlEntityFile.load(std::string(FILE_PATH_ENTITY) + _fileName);
    if (xmlEntityFile.isValid())
    {
        // Reuse a dead entity if possible
        for (sEntity* ptEntity = getHead(); ptEntity != nullptr; ptEntity = ptEntity->next)
        {
            if ((ptEntity->base.enabled == false) && (ptEntity->base.dying == false))
            {
                tEntity = ptEntity;
                break;
            }
        }

        // Else create a new entity
        if (tEntity == nullptr)
        {
            tEntity = getNew();
        }
        else
        {
            //std::cout << "Reusing entity: " << tEntity->UID << std::endl;
        }

        // Ownership (default to map as owner, as this will free the entity on map unload)
        tEntity->base.owner = eEntityOwner::entityOwner_map;

        // Base
        tEntity->base.enabled        = true;
        tEntity->base.dying          = false;
        tEntity->base.initialized    = false;
        tEntity->base.name           = xmlEntityFile.getString("<base_name>");
        tEntity->base.position       = xmlEntityFile.getVec3("<base_position>");
        tEntity->base.position.y    += m_mapPointer->info.terrainHeight;
        tEntity->base.scale          = xmlEntityFile.getVec3("<base_scale>");
        tEntity->base.rotation       = xmlEntityFile.getVec3("<base_rotation>");
        tEntity->base.rotationAxis   = xmlEntityFile.getVec3("<base_rotation_axis>");
        tEntity->base.rotationOffset = tEntity->base.rotation;
        tEntity->base.hitPoints      = xmlEntityFile.getInteger("<base_hit_points>");
        tEntity->base.destructible   = (xmlEntityFile.getInteger("<base_destructible>") > 0);
        tEntity->base.collectable    = (xmlEntityFile.getInteger("<base_collectable>") > 0);
        tEntity->base.interactable   = (xmlEntityFile.getInteger("<base_interactable>") > 0);

        if ((tEntity->base.destructible) || (tEntity->base.collectable))
            tEntity->base.interactable = true;

        if (xmlEntityFile.getInstanceCount("<base_flexibility>") > 0)
            tEntity->base.flexibility    = xmlEntityFile.getFloat("<base_flexibility>");

        // Footprint
        if (xmlEntityFile.getInstanceCount("<footprint>") > 0)
        {
            // create a new footprint if one does not already exist
            if (tEntity->footprint == nullptr)
            {
                tEntity->footprint = new sEntityFootprint;
            }

            // Free footprint data if it exists
            if (tEntity->footprint->data != nullptr)
            {
                delete[] tEntity->footprint->data;
            }

            // Get the footprint dimensions
            tEntity->footprint->size_x = xmlEntityFile.getInteger("<footprint_x>");
            tEntity->footprint->size_y = xmlEntityFile.getInteger("<footprint_y>");

            std::uint32_t instanceCount = xmlEntityFile.getInstanceCount("<footprint_data>");

            // Footprint size too small, or no data
            if ((tEntity->footprint->size_x == 0) || (tEntity->footprint->size_y == 0) || (instanceCount == 0))
            {
                delete tEntity->footprint;
                tEntity->footprint = nullptr;
            }
            else
            {
                // Allocate memory for the footprint data
                tEntity->footprint->data = new std::uint32_t[tEntity->footprint->size_x * tEntity->footprint->size_y];

                // Load the footprint data
                std::uint32_t dataNum   = 0;
                std::uint32_t dataCount = xmlEntityFile.getInstanceCount("<footprint_data>");
                for (std::uint32_t i = 0; i < dataCount; ++i)
                {
                    // Get next footprint data
                    std::string footprintData = xmlEntityFile.getString("<footprint_data>", 1 + i);

                    // Process the footprint data string
                    footprintData += " ";
                    std::uint64_t footprintDataLength = footprintData.length();
                    std::string tString = "";
                    if (footprintDataLength > 2)
                    {
                        for (std::uint64_t j = 0; j < footprintDataLength; ++j)
                        {
                            if ((j > 0) && (footprintData[j] == ' ') && (footprintData[j-1] != ' '))
                            {
                                tEntity->footprint->data[dataNum] = std::stoi(tString);
                                dataNum++;
                                tString = "";
                            }
                            else
                            {
                                tString += footprintData[j];
                            }
                        }
                    }
                }
            }
        }

        // Particles
        if (xmlEntityFile.getInstanceCount("<base_particle_type>") > 0)
            tEntity->base.particleType    = static_cast<eParticleType>(xmlEntityFile.getInteger("<base_particle_type>"));
        if (xmlEntityFile.getInstanceCount("<base_particle_height>") > 0)
            tEntity->base.particleHeight  = xmlEntityFile.getFloat("<base_particle_height>");

        tEntity->base.clicked             = false;
        tEntity->base.debris              = xmlEntityFile.getString("<base_debris>");
        tEntity->base.type                = static_cast<eEntityType>(xmlEntityFile.getInteger("<base_type>"));

        tEntity->base.flyOver             = (xmlEntityFile.getInteger("<base_fly_over>") > 0);
        tEntity->base.flying              = (xmlEntityFile.getInteger("<base_flying>") > 0);
        tEntity->base.overSize            = (xmlEntityFile.getInteger("<base_over_size>") > 0);

        tEntity->base.textActive          = (xmlEntityFile.getInteger("<base_textActive>") > 0);
        if (xmlEntityFile.getInstanceCount("<base_textData>") > 0)
            tEntity->base.textData        = xmlEntityFile.getString("<base_textData>").c_str();
        if (xmlEntityFile.getInstanceCount("<base_textColor>") > 0)
        {
            tEntity->base.textColor       = xmlEntityFile.getVec3("<base_textColor>");
            tEntity->base.textColor.x     /= 255.0f;
            tEntity->base.textColor.y     /= 255.0f;
            tEntity->base.textColor.z     /= 255.0f;
        }

        // Death screen shake
        tEntity->base.deathShakeChance    = xmlEntityFile.getInteger("<death_shake_chance>");
        tEntity->base.deathShakeDuration  = xmlEntityFile.getInteger("<death_shake_duration>");
        tEntity->base.deathShakeForce     = xmlEntityFile.getFloat("<death_shake_force>");

        // AI
        if (xmlEntityFile.getInstanceCount("<ai>") > 0)
        {
            // AI
            if (tEntity->ai == nullptr)
            {
                tEntity->ai = new sEntityAI;
            }
            tEntity->ai->modelAlive       = xmlEntityFile.getString("<graphics_model>");
            tEntity->ai->modelCorpse      = xmlEntityFile.getString("<ai_model_corpse>");

            tEntity->ai->attackRange      = xmlEntityFile.getFloat("<ai_attack_range>");
            tEntity->ai->attackFrequency  = xmlEntityFile.getInteger("<ai_attack_frequency>");
            tEntity->ai->awareRange       = xmlEntityFile.getFloat("<ai_aware_range>");
            tEntity->ai->moveRange        = xmlEntityFile.getFloat("<ai_move_range>");
            tEntity->ai->retreatRange     = xmlEntityFile.getFloat("<ai_retreat_range>");
            tEntity->ai->retreatThreshold = xmlEntityFile.getFloat("<ai_retreat_threshold>");

            if (xmlEntityFile.getInstanceCount("<ai_leader>") > 0)
            {
                if (tEntity->ai->leader == nullptr)
                {
                    tEntity->ai->leader = new sEntityAILeader;
                }

                // Minions
                if (xmlEntityFile.getInstanceCount("<ai_leader_minion_managed>") > 0)
                    tEntity->ai->leader->minionManaged = (xmlEntityFile.getInteger("<ai_leader_minion_managed>") > 0);

                tEntity->ai->leader->minionCurrent = xmlEntityFile.getInteger("<ai_leader_minion_start>");
                tEntity->ai->leader->minionMax     = xmlEntityFile.getInteger("<ai_leader_minion_max>");
                if (tEntity->ai->leader->minionCurrent > tEntity->ai->leader->minionMax)
                {
                    // Swap if Current > Max
                    std::uint32_t temp = tEntity->ai->leader->minionCurrent;
                    tEntity->ai->leader->minionCurrent = tEntity->ai->leader->minionMax;
                    tEntity->ai->leader->minionMax = temp;
                }
                tEntity->ai->leader->minionName   = xmlEntityFile.getString("<ai_leader_minion_name>");
                tEntity->ai->leader->minionNumber = xmlEntityFile.getInteger("<ai_leader_minion_number>");
                tEntity->ai->leader->minion       = new sEntityAIMinion[tEntity->ai->leader->minionMax];

                // Leader abilities
                tEntity->ai->leader->spawn        = (xmlEntityFile.getInteger("<ai_leader_minion_spawn>") > 0);
                tEntity->ai->leader->spawnCost    = xmlEntityFile.getInteger("<ai_leader_minion_spawn_cost>");

                tEntity->ai->leader->revive       = (xmlEntityFile.getInteger("<ai_leader_minion_revive>") > 0);
                tEntity->ai->leader->reviveCost   = xmlEntityFile.getInteger("<ai_leader_minion_revive_cost>");

                tEntity->ai->leader->heal         = (xmlEntityFile.getInteger("<ai_leader_minion_heal>") > 0);
                tEntity->ai->leader->healCost     = xmlEntityFile.getInteger("<ai_leader_minion_heal_cost>");
            }

            // Movement
            if (tEntity->movement == nullptr)
            {
                tEntity->movement = new sEntityMovement;
            }
        }

        // Movement
        if (xmlEntityFile.getInstanceCount("<movement>") > 0)
        {
            // Movement
            if (tEntity->movement == nullptr)
            {
                tEntity->movement = new sEntityMovement;
            }
            tEntity->movement->speed = xmlEntityFile.getFloat("<movement_speed>");

        }

        // Character
        if (xmlEntityFile.getInstanceCount("<character>") > 0)
        {
            if (tEntity->character == nullptr)
            {
                tEntity->character = new sEntityCharacter;
            }

            if (xmlEntityFile.getInstanceCount("<character_importance>") > 0)
                tEntity->character->importance = static_cast<eCharacterImportance>(xmlEntityFile.getInteger("<character_importance>"));

            // Model
            tEntity->character->healthBarModel = m_resourceManager->loadModel(xmlEntityFile.getString("<character_billboard_model>"));

            // Material
            if (tEntity->character->healthBarModel != nullptr)
            {
                tEntity->character->healthBarmaterial = new sMaterial*[tEntity->character->healthBarModel->numMesh];
                // Load materials
                for (std::uint32_t i = 0; i < tEntity->character->healthBarModel->numMesh; ++i)
                {
                    std::string tString = xmlEntityFile.getString("<character_billboard_material>", 1 + i);
                    if (tString.length() > 0)
                    {
                        tEntity->character->healthBarmaterial[i] = m_resourceManager->loadMaterial(tString);
                    }
                    else
                    {
                        tEntity->character->healthBarmaterial[i] = m_resourceManager->loadMaterial(xmlEntityFile.getString("<character_billboard_material>"));
                    }
                }

            }

            if (xmlEntityFile.getInstanceCount("<character_billboard_position>") > 0)
                tEntity->character->healthBarOffset = xmlEntityFile.getFloat("<character_billboard_position>");
            if (xmlEntityFile.getInstanceCount("<character_billboard_scale>") > 0)
                tEntity->character->healthBarScale = xmlEntityFile.getVec2("<character_billboard_scale>");

            // Health
            if (xmlEntityFile.getInstanceCount("<character_health_max>") > 0)
            {
                tEntity->character->attribute.health.max = xmlEntityFile.getFloat("<character_health_max>");
                tEntity->character->attribute.health.current = tEntity->character->attribute.health.max;
            }
            if (xmlEntityFile.getInstanceCount("<character_health_current>") > 0)
                tEntity->character->attribute.health.current = xmlEntityFile.getFloat("<character_health_current>");
            if (xmlEntityFile.getInstanceCount("<character_health_regen>") > 0)
                tEntity->character->attribute.health.regen = xmlEntityFile.getFloat("<character_health_regen>");

            // Mana
            if (xmlEntityFile.getInstanceCount("<character_mana_max>") > 0)
            {
                tEntity->character->attribute.mana.max = xmlEntityFile.getFloat("<character_mana_max>");
                tEntity->character->attribute.mana.current = tEntity->character->attribute.mana.max;
            }
            if (xmlEntityFile.getInstanceCount("<character_mana_current>") > 0)
                tEntity->character->attribute.mana.current = xmlEntityFile.getFloat("<character_mana_current>");
            if (xmlEntityFile.getInstanceCount("<character_mana_regen>") > 0)
                tEntity->character->attribute.mana.regen = xmlEntityFile.getFloat("<character_mana_regen>");

            // Damage
            if (xmlEntityFile.getInstanceCount("<character_damage_physical_base>") > 0)
                tEntity->character->attribute.damagePhysical.base = xmlEntityFile.getFloat("<character_damage_physical_base>");
            if (xmlEntityFile.getInstanceCount("<character_damage_physical_crit_chance>") > 0)
                tEntity->character->attribute.damagePhysical.critChance = xmlEntityFile.getFloat("<character_damage_physical_crit_chance>");
            if (xmlEntityFile.getInstanceCount("<character_damage_physical_crit_multiplier>") > 0)
                tEntity->character->attribute.damagePhysical.critMultiplier = xmlEntityFile.getFloat("<character_damage_physical_crit_multiplier>");

            if (xmlEntityFile.getInstanceCount("<character_damage_fire_base>") > 0)
                tEntity->character->attribute.damageFire.base = xmlEntityFile.getFloat("<character_damage_fire_base>");
            if (xmlEntityFile.getInstanceCount("<character_damage_fire_crit_chance>") > 0)
                tEntity->character->attribute.damageFire.critChance = xmlEntityFile.getFloat("<character_damage_fire_crit_chance>");
            if (xmlEntityFile.getInstanceCount("<character_damage_fire_crit_multiplier>") > 0)
                tEntity->character->attribute.damageFire.critMultiplier = xmlEntityFile.getFloat("<character_damage_fire_crit_multiplier>");

            if (xmlEntityFile.getInstanceCount("<character_damage_frost_base>") > 0)
                tEntity->character->attribute.damageFrost.base = xmlEntityFile.getFloat("<character_damage_frost_base>");
            if (xmlEntityFile.getInstanceCount("<character_damage_frost_crit_chance>") > 0)
                tEntity->character->attribute.damageFrost.critChance = xmlEntityFile.getFloat("<character_damage_frost_crit_chance>");
            if (xmlEntityFile.getInstanceCount("<character_damage_frost_crit_multiplier>") > 0)
                tEntity->character->attribute.damageFrost.critMultiplier = xmlEntityFile.getFloat("<character_damage_frost_crit_multiplier>");

            // Armor
            if (xmlEntityFile.getInstanceCount("<character_armor_physical_base>") > 0)
                tEntity->character->attribute.armorPhysical.base = xmlEntityFile.getFloat("<character_armor_physical_base>");
            if (xmlEntityFile.getInstanceCount("<character_armor_fire_base>") > 0)
                tEntity->character->attribute.resistanceFire.base = xmlEntityFile.getFloat("<character_armor_fire_base>");
            if (xmlEntityFile.getInstanceCount("<character_armor_frost_base>") > 0)
                tEntity->character->attribute.resistanceFrost.base = xmlEntityFile.getFloat("<character_armor_frost_base>");

            // Skills
            if (xmlEntityFile.getInstanceCount("<character_skill_heal_enabled>") > 0)
                tEntity->character->skill.heal.enabled = (xmlEntityFile.getInteger("<character_skill_heal_enabled>") > 0);
            if (xmlEntityFile.getInstanceCount("<character_skill_heal_mana_cost>") > 0)
                tEntity->character->skill.heal.manaCost = xmlEntityFile.getFloat("<character_skill_heal_mana_cost>");
            if (xmlEntityFile.getInstanceCount("<character_skill_heal_amount>") > 0)
                tEntity->character->skill.heal.manaCost = xmlEntityFile.getFloat("<character_skill_heal_amount>");

        }

        // Graphics
        if (xmlEntityFile.getInstanceCount("<graphics>") > 0)
        {
            if (tEntity->graphics == nullptr)
            {
                tEntity->graphics = new sEntityGraphics;
            }

            // Model
            std::string tString = xmlEntityFile.getString("<graphics_model>");
            tEntity->graphics->model = m_resourceManager->loadModel(tString);

            // Material
            tEntity->graphics->numMaterial = xmlEntityFile.getInstanceCount("<graphics_material>");
            if (tEntity->graphics->numMaterial > 0)
            {
                tEntity->graphics->material = new sMaterial*[tEntity->graphics->numMaterial];
                // Load materials
                for (std::uint32_t i = 0; i < tEntity->graphics->numMaterial; ++i)
                {
                    tString = xmlEntityFile.getString("<graphics_material>", 1 + i);
                    if (tString.length() > 0)
                    {
                        tEntity->graphics->material[i] = m_resourceManager->loadMaterial(tString);
                    }
                    else
                    {
                        tEntity->graphics->material[i] = m_resourceManager->loadMaterial(xmlEntityFile.getString("<graphics_material>"));
                    }
                }
            }
            // Mesh enabled
            std::uint32_t meshEnableModifierCount = xmlEntityFile.getInstanceCount("<graphics_mesh_enabled>");
            if ((meshEnableModifierCount != 0) &&
                (meshEnableModifierCount <= tEntity->graphics->model->numMesh))
            {
                for (std::uint32_t i = 0; i < meshEnableModifierCount; ++i)
                {
                    tEntity->graphics->model->mesh[i].enabled = (xmlEntityFile.getInteger("<graphics_mesh_enabled>", 1 + i) > 0);
                }
            }

            // Icon
            if (xmlEntityFile.getInstanceCount("<graphics_icon>") > 0)
                tEntity->graphics->icon = m_resourceManager->loadTexture(xmlEntityFile.getString("<graphics_icon>"))->ID;
        }

        // Animation (make sure to load the model first)
        if (xmlEntityFile.getInstanceCount("<animation>") > 0)
        {
            // Pointer
            if (tEntity->animation == nullptr)
            {
                tEntity->animation = new sEntityAnimation;
            }

            tEntity->animation->animationIndependent = (xmlEntityFile.getInteger("<animation_independent>") > 0);

            tEntity->animation->currentAnimTime = 0;
            tEntity->animation->startAnimTime = 0;
            tEntity->animation->stopAnimTime = 1;
            tEntity->animation->repeatAnimation = false;
            tEntity->animation->finishedAnimation =  true;
        }

        // Interaction
        if (xmlEntityFile.getInstanceCount("<interaction>") > 0)
        {
            // Pointer
            if (tEntity->interaction == nullptr)
            {
                tEntity->interaction = new sEntityInteraction;
            }

            glm::ivec3 data                = xmlEntityFile.getIvec3("<interaction_action>");
            tEntity->interaction->type     = static_cast<eEntityInteraction>(data.x);
            tEntity->interaction->state_1  = static_cast<eEntityState>(data.y);
            tEntity->interaction->state_2  = static_cast<eEntityState>(data.z);

            tEntity->interaction->mouse    = (xmlEntityFile.getInteger("<interaction_mouse>") > 0);
            tEntity->interaction->distance = xmlEntityFile.getFloat("<interaction_distance>");
        }

        // Loot
        if (xmlEntityFile.getInstanceCount("<loot>") > 0)
        {
            // Pointer
            if (tEntity->loot == nullptr)
            {
                tEntity->loot = new sEntityLoot;
            }

            // Gold
            tEntity->loot->gold     = xmlEntityFile.getInteger("<loot_gold>");
            tEntity->loot->gold_min = xmlEntityFile.getInteger("<loot_gold_min>");
            tEntity->loot->gold_max = xmlEntityFile.getInteger("<loot_gold_max>");

            // Experience
            tEntity->loot->experience     = (xmlEntityFile.getInteger("<loot_experience>") > 0);
            tEntity->loot->experience_min = xmlEntityFile.getInteger("<loot_experience_min>");
            tEntity->loot->experience_max = xmlEntityFile.getInteger("<loot_experience_max>");

            // Guaranteed item drops
            if (xmlEntityFile.getInstanceCount("<loot_item_id>") > 0)
                tEntity->loot->itemID = xmlEntityFile.getInteger("<loot_item_id>");
        }

        // Particle
        if (xmlEntityFile.getInstanceCount("<particle>") > 0)
        {
            if (tEntity->particle == nullptr)
            {
                tEntity->particle = new sEntityParticle;
            }
            tEntity->particle->gravity = xmlEntityFile.getFloat("<particle_gravity>");
        }

        // Physics
        if (xmlEntityFile.getInstanceCount("<physics>") > 0)
        {
            if (tEntity->physics == nullptr)
            {
                tEntity->physics = new sEntityPhysics;
            }
            tEntity->physics->acceleration       = xmlEntityFile.getFloat("<physics_acceleration>");
            tEntity->physics->boundingVolumeType = static_cast<ePhysicsBoundingVolumeType>(xmlEntityFile.getInteger("<physics_bounding_volume_type>"));
            tEntity->physics->halfDimentions     = xmlEntityFile.getVec3("<physics_collision_half_dimentions>");
            tEntity->physics->mass               = xmlEntityFile.getFloat("<physics_mass>");
            tEntity->physics->radius             = xmlEntityFile.getFloat("<physics_collision_radius>");
            tEntity->physics->type               = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<physics_type>"));
            tEntity->physics->velocity           = xmlEntityFile.getVec3("<physics_velocity>");
            tEntity->physics->velocityMax        = xmlEntityFile.getFloat("<physics_max_velocity>");
            tEntity->physics->damage             = xmlEntityFile.getFloat("<physics_dammage>");
        }

        // Quest
        if (xmlEntityFile.getInstanceCount("<quest>") > 0)
        {
            // allocate memory if entity has a quest component
            if (tEntity->quest == nullptr)
            {
                tEntity->quest = new sEntityQuest;
            }

            // if quest on death component, process
            if (xmlEntityFile.getInstanceCount("<quest_on_death>") > 0)
            {
                // Data parsing
                std::string   dataString       = {};
                std::uint32_t dataStringLength = 0;
                std::uint32_t tStringNum       = 0;
                std::string   tString          = {};

                // Get data
                dataString  = xmlEntityFile.getString("<quest_on_death>");
                dataString += " "; // end of string marker
                dataStringLength = dataString.length();
                tStringNum  = 0;
                tString     = "";

                // Process data
                /// # quest name, set state
                if (dataStringLength > 4)
                {
                    for (std::uint32_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                tEntity->quest->onDeath.questName = tString; // quest name
                            }
                            else if (tStringNum == 1)
                            {
                                tEntity->quest->onDeath.setState = std::stoi(tString); // set state
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += dataString[j];
                        }
                    }
                }
            }
        }

        // State
        if (xmlEntityFile.getInstanceCount("<state>") > 0)
        {
            if (tEntity->state == nullptr)
            {
                tEntity->state = new sEntityState;
            }
            tEntity->state->stateInitial   = static_cast<eEntityState>(xmlEntityFile.getInteger("<state_initial>"));

            std::string fileName = {};

            // Attack
            if (xmlEntityFile.getInstanceCount("<state_attack_audio_name>") > 0)
            {
                tEntity->state->attack.audio.name   = xmlEntityFile.getString("<state_attack_audio_name>");
                tEntity->state->attack.audio.number = xmlEntityFile.getInteger("<state_attack_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->attack.audio.name, tEntity->state->attack.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->attack.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->attack.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_attack_physics_state>") > 0)
            {
                tEntity->state->attack.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_attack_physics_state>"));
            }
            tEntity->state->attack.tileCollision = (xmlEntityFile.getInteger("<state_attack_tile_state>") > 0);
            tEntity->state->attack.animation     = xmlEntityFile.getVec3("<state_attack_animation>");

            // Defend
            if (xmlEntityFile.getInstanceCount("<state_defend_audio_name>") > 0)
            {
                tEntity->state->defend.audio.name   = xmlEntityFile.getString("<state_defend_audio_name>");
                tEntity->state->defend.audio.number = xmlEntityFile.getInteger("<state_defend_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->defend.audio.name, tEntity->state->defend.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->defend.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->defend.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_defend_physics_state>") > 0)
            {
                tEntity->state->defend.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_defend_physics_state>"));
            }
            tEntity->state->defend.tileCollision = (xmlEntityFile.getInteger("<state_defend_tile_state>") > 0);
            tEntity->state->defend.animation     = xmlEntityFile.getVec3("<state_defend_animation>");

            // Die
            if (xmlEntityFile.getInstanceCount("<state_die_audio_name>") > 0)
            {
                tEntity->state->die.audio.name   = xmlEntityFile.getString("<state_die_audio_name>");
                tEntity->state->die.audio.number = xmlEntityFile.getInteger("<state_die_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->die.audio.name, tEntity->state->die.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->die.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->die.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_die_physics_state>") > 0)
            {
                tEntity->state->die.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_die_physics_state>"));
            }
            tEntity->state->die.tileCollision = (xmlEntityFile.getInteger("<state_die_tile_state>") > 0);
            tEntity->state->die.animation     = xmlEntityFile.getVec3("<state_die_animation>");

            // Idle
            if (xmlEntityFile.getInstanceCount("<state_idle_audio_name>") > 0)
            {
                tEntity->state->idle.audio.name   = xmlEntityFile.getString("<state_idle_audio_name>");
                tEntity->state->idle.audio.number = xmlEntityFile.getInteger("<state_idle_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->idle.audio.name, tEntity->state->idle.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->idle.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->idle.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_idle_physics_state>") > 0)
            {
                tEntity->state->idle.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_idle_physics_state>"));
            }
            tEntity->state->idle.tileCollision = (xmlEntityFile.getInteger("<state_idle_tile_state>") > 0);
            tEntity->state->idle.animation     = xmlEntityFile.getVec3("<state_idle_animation>");

            // Interact
            if (xmlEntityFile.getInstanceCount("<state_interact_audio_name>") > 0)
            {
                tEntity->state->interact.audio.name   = xmlEntityFile.getString("<state_interact_audio_name>");
                tEntity->state->interact.audio.number = xmlEntityFile.getInteger("<state_interact_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->interact.audio.name, tEntity->state->interact.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->interact.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->interact.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_interact_physics_state>") > 0)
            {
                tEntity->state->interact.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_interact_physics_state>"));
            }
            tEntity->state->interact.tileCollision = (xmlEntityFile.getInteger("<state_interact_tile_state>") > 0);
            tEntity->state->interact.animation     = xmlEntityFile.getVec3("<state_interact_animation>");

            // Move
            if (xmlEntityFile.getInstanceCount("<state_move_audio_name>") > 0)
            {
                tEntity->state->move.audio.name   = xmlEntityFile.getString("<state_move_audio_name>");
                tEntity->state->move.audio.number = xmlEntityFile.getInteger("<state_move_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->move.audio.name, tEntity->state->move.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->move.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->move.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_move_physics_state>") > 0)
            {
                tEntity->state->move.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_move_physics_state>"));
            }
            tEntity->state->move.tileCollision = (xmlEntityFile.getInteger("<state_move_tile_state>") > 0);
            tEntity->state->move.animation     = xmlEntityFile.getVec3("<state_move_animation>");

            // Spawn
            if (xmlEntityFile.getInstanceCount("<state_spawn_audio_name>") > 0)
            {
                tEntity->state->spawn.audio.name   = xmlEntityFile.getString("<state_spawn_audio_name>");
                tEntity->state->spawn.audio.number = xmlEntityFile.getInteger("<state_spawn_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->spawn.audio.name, tEntity->state->spawn.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->spawn.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->spawn.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_spawn_physics_state>") > 0)
            {
                tEntity->state->spawn.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_spawn_physics_state>"));
            }
            tEntity->state->spawn.tileCollision = (xmlEntityFile.getInteger("<state_spawn_tile_state>") > 0);
            tEntity->state->spawn.animation     = xmlEntityFile.getVec3("<state_spawn_animation>");

            // Open
            if (xmlEntityFile.getInstanceCount("<state_open_audio_name>") > 0)
            {
                tEntity->state->open.audio.name   = xmlEntityFile.getString("<state_open_audio_name>");
                tEntity->state->open.audio.number = xmlEntityFile.getInteger("<state_open_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->open.audio.name, tEntity->state->open.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->open.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->open.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_open_physics_state>") > 0)
            {
                tEntity->state->open.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_open_physics_state>"));
            }
            tEntity->state->open.tileCollision = (xmlEntityFile.getInteger("<state_open_tile_state>") > 0);
            tEntity->state->open.animation     = xmlEntityFile.getVec3("<state_open_animation>");

            // Close
            if (xmlEntityFile.getInstanceCount("<state_close_audio_name>") > 0)
            {
                tEntity->state->close.audio.name   = xmlEntityFile.getString("<state_close_audio_name>");
                tEntity->state->close.audio.number = xmlEntityFile.getInteger("<state_close_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->close.audio.name, tEntity->state->close.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->close.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->close.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_close_physics_state>") > 0)
            {
                tEntity->state->close.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_close_physics_state>"));
            }
            tEntity->state->close.tileCollision = (xmlEntityFile.getInteger("<state_close_tile_state>") > 0);
            tEntity->state->close.animation     = xmlEntityFile.getVec3("<state_close_animation>");

            // Level Up
            if (xmlEntityFile.getInstanceCount("<state_levelUp_audio_name>") > 0)
            {
                tEntity->state->levelUp.audio.name   = xmlEntityFile.getString("<state_levelUp_audio_name>");
                tEntity->state->levelUp.audio.number = xmlEntityFile.getInteger("<state_levelUp_audio_number>");
                fileName = m_databaseManager->getDatabaseEntryFileName(tEntity->state->levelUp.audio.name, tEntity->state->levelUp.audio.number, eDatabaseType::databaseTypeSound);
                tEntity->state->levelUp.audio.sound = m_audioEngine->getNewSoundPointer();
                m_audioEngine->loadSound(fileName, tEntity->state->levelUp.audio.sound->data);
            }
            if (xmlEntityFile.getInstanceCount("<state_levelUp_physics_state>") > 0)
            {
                tEntity->state->levelUp.physicsState  = static_cast<ePhysicsType>(xmlEntityFile.getInteger("<state_levelUp_physics_state>"));
            }
            tEntity->state->levelUp.tileCollision = (xmlEntityFile.getInteger("<state_levelUp_tile_state>") > 0);
            tEntity->state->levelUp.animation     = xmlEntityFile.getVec3("<state_levelUp_animation>");

            // Set initial state
            if (tEntity->state->stateInitial != 0)
            {
                tEntity->state->stateCurrent = tEntity->state->stateInitial;
                switch (tEntity->state->stateCurrent)
                {
                    case eEntityState::entityState_attack:
                        m_setAnimationState(tEntity, tEntity->state->attack.animation);
                    break;
                    case eEntityState::entityState_defend:
                        m_setAnimationState(tEntity, tEntity->state->defend.animation);
                    break;
                    case eEntityState::entityState_die:
                        m_setAnimationState(tEntity, tEntity->state->die.animation);
                    break;
                    case eEntityState::entityState_idle:
                        m_setAnimationState(tEntity, tEntity->state->idle.animation);
                    break;
                    case eEntityState::entityState_interact:
                        m_setAnimationState(tEntity, tEntity->state->interact.animation);
                    break;
                    case eEntityState::entityState_spawn:
                        m_setAnimationState(tEntity, tEntity->state->spawn.animation);
                    break;
                    case eEntityState::entityState_open:
                        m_setAnimationState(tEntity, tEntity->state->open.animation);
                    break;
                    case eEntityState::entityState_close:
                        m_setAnimationState(tEntity, tEntity->state->close.animation);
                    break;
                    default:
                    case eEntityState::entityState_none:
                    break;
                }
            }
        }

        // Tile Collision
        if (xmlEntityFile.getInstanceCount("<tile_collision>") > 0)
        {
            if (tEntity->tileCollision == nullptr)
            {
                tEntity->tileCollision = new sEntityTileCollision;
            }
            // Get size
            tEntity->tileCollision->size = xmlEntityFile.getInteger("<tile_collision_size>");

            // Allocate memory
            tEntity->tileCollision->data = new std::uint32_t[tEntity->tileCollision->size * tEntity->tileCollision->size];

            // Load collision data
            std::uint32_t dataNum   = 0;
            std::uint32_t dataCount = xmlEntityFile.getInstanceCount("<tile_collision_data>");
            for (std::uint32_t i = 0; i < dataCount; ++i)
            {
                // Get next collision data
                std::string collisionData = xmlEntityFile.getString("<tile_collision_data>", 1 + i);

                // Process the collision data string
                collisionData += " ";
                std::uint64_t collisionDataLength = collisionData.length();
                std::string tString = "";
                if (collisionDataLength > 2)
                {
                    for (std::uint64_t j = 0; j < collisionDataLength; ++j)
                    {
                        if ((j > 0) && (collisionData[j] == ' ') && (collisionData[j-1] != ' '))
                        {
                            tEntity->tileCollision->data[dataNum] = std::stoi(tString);
                            dataNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += collisionData[j];
                        }
                    }
                }
            }
        }

    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    xmlEntityFile.free();
    return tEntity;
}

std::uint32_t cEntityManager::m_nearestFreeTile(const std::uint32_t &_tile)
{
    auto clearTile = [](sMap* &_map, const std::uint32_t &_tileNumber)
    {
        return ((_map->tile[_tileNumber].entity.type == eTileEntityType::tileEntityNone) &&
               ((_map->tile[_tileNumber].type == eTileType::tileFloor) ||
                (_map->tile[_tileNumber].type == eTileType::tilePath)));
    };

    // First try to use the position provided
    if (clearTile(m_mapPointer, _tile))
    {
        return _tile;
    }
    else
    {
        // Initial tile position
        std::uint32_t tile_x = _tile % m_mapPointer->info.size_x;
        std::uint32_t tile_y = _tile / m_mapPointer->info.size_x;

        // Second try random placement
        std::uint32_t radius = 1;
        for (std::uint32_t i = 0; i < m_mapPointer->numTiles; ++i)
        {
            std::uint32_t rand_x = (rand() % (radius * 2) - radius) + tile_x + 1;
            std::uint32_t rand_y = (rand() % (radius * 2) - radius) + tile_y + 1;

            if (rand_x > m_mapPointer->info.size_x - 2)
                rand_x = m_mapPointer->info.size_x - 2;
            if (rand_y > m_mapPointer->info.size_y - 2)
                rand_y = m_mapPointer->info.size_y - 2;

            std::uint32_t tTile = (rand_y * m_mapPointer->info.size_x) + rand_x;
            if (clearTile(m_mapPointer, tTile))
                return tTile;

            radius++;
        }

        // Third a very iterative approach
        std::uint32_t itterations = (m_mapPointer->info.size_x > m_mapPointer->info.size_y) ? m_mapPointer->info.size_x : m_mapPointer->info.size_y;

        for (radius = 1; radius < itterations; ++radius)
        {
            std::uint32_t tile_xStart = tile_x - radius;
            std::uint32_t tile_yStart = tile_y - radius;
            std::uint32_t tile_xEnd = ((tile_x + radius) > m_mapPointer->info.size_x) ? m_mapPointer->info.size_x : (tile_x + radius);
            std::uint32_t tile_yEnd = ((tile_y + radius) > m_mapPointer->info.size_y) ? m_mapPointer->info.size_y : (tile_y + radius);
            for (std::uint32_t y = tile_yStart; y < tile_yEnd; ++y)
            {
                for (std::uint32_t x = tile_xStart; x < tile_xEnd; ++x)
                {
                    std::uint32_t tTile = (y * m_mapPointer->info.size_x) + x;
                    if (clearTile(m_mapPointer, tTile))
                        return tTile;
                }
            }
        }
    }

    // If no free tile is found, just spawn it on top.
    return _tile;
}

void cEntityManager::deleteEntity(sEntity*& _pointer)
{
    // remove the entity from the map
    if ((m_mapPointer != nullptr) && (m_mapPointer->tile != nullptr))
    {
        std::uint32_t tileCount = m_mapPointer->info.size_x * m_mapPointer->info.size_y;
        for (std::uint32_t i = 0; i < tileCount; ++i)
        {
            if (m_mapPointer->tile[i].entity.UID == _pointer->UID)
            {
                // Remove the Entity
                m_mapPointer->tile[i].entity.UID  = 0;
                m_mapPointer->tile[i].entity.type = eTileEntityType::tileEntityNone;

                // Set tiles passable
                gSetTileCollision(m_mapPointer, _pointer->base.tileOnMap, false);
            }
        }
    }

    // Disable (possible future entity reuse), set to dying so the audio can finish playing before freeing data
    _pointer->base.enabled = false;
    if (_pointer->base.dying == false)
    {
        freeData(_pointer);
    }
};

void cEntityManager::deleteParticleEntity(sEntity*& _pointer)
{
    // Free data and disable (possible future entity reuse)
    freeData(_pointer);
    _pointer->base.enabled = false;
    _pointer->base.dying   = false;
};

sEntity* cEntityManager::spawnEntity(const std::string &_name, const std::uint32_t &_number, const eDatabaseType &_type, const glm::vec3 &_position)
{
    std::string fileName = m_databaseManager->getDatabaseEntryFileName(_name, _number, _type);
    sEntity* tEntity = load(fileName);

    if (tEntity != nullptr)
    {
        std::uint32_t tile = m_nearestFreeTile(gMapPositionToTile(m_mapPointer, _position));

        glm::vec3 position = gMapTileToPosition(m_mapPointer, tile);
        position.y = _position.y;

        // AI spawn tile
        if (tEntity->ai != nullptr)
        {
            tEntity->ai->spawnTile = tile;
        }

        // Map tile position
        tEntity->base.tileOnMap = tile;
        m_mapPointer->tile[tEntity->base.tileOnMap].entity.UID = tEntity->UID;

        // Tile entity data
        if ((_type == eDatabaseType::databaseTypeObject) || (_type == eDatabaseType::databaseTypeItem))
        {
            if (tEntity->physics != nullptr)
            {
                if (tEntity->physics->type == ePhysicsType::physicsTypeDynamic)
                {
                    m_mapPointer->tile[tEntity->base.tileOnMap].entity.type = eTileEntityType::tileEntityObjectDynamic;
                    tEntity->base.type  = eEntityType::entityType_objectDynamic;
                }
                else
                {
                    m_mapPointer->tile[tEntity->base.tileOnMap].entity.type = eTileEntityType::tileEntityObjectStatic;
                    tEntity->base.type  = eEntityType::entityType_objectStatic;
                }
            }
        }
        else if (_type == eDatabaseType::databaseTypeNpc)
        {
            m_mapPointer->tile[tEntity->base.tileOnMap].entity.type = eTileEntityType::tileEntityNPC;
        }

        // Ownership
        tEntity->base.owner = eEntityOwner::entityOwner_map;

        // position relative to tile
        tEntity->base.position = position;

        // update model matrix
        updateModelMatrix(tEntity);

        // Play spawn audio
        if ((tEntity->state != nullptr) && (tEntity->state->spawn.audio.sound != nullptr))
            m_audioEngine->playSound(tEntity->state->spawn.audio.sound->data);

        // Push spawn entity event
        sEntityManagerEvent* event = new sEntityManagerEvent;
        event->type = sEntityManagerEventType::entityManagerEventType_spawnEntity;
        event->data = tEntity->UID; // Entity UID
        m_event.push(event);
    }

    return tEntity;
}

void cEntityManager::spawnMinionEntities(void)
{
    // Temp entity to hold newly spawned minions
    sEntity *tEntity = nullptr;

    // Iterate over all entities and spawn entities for leader NPCs
    for (sEntity* _leaderEntity = getHead(); _leaderEntity != nullptr; _leaderEntity = _leaderEntity->next)
    {
        // Only process entities with required components
        if ((_leaderEntity->ai != nullptr) && (_leaderEntity->ai->leader != nullptr) && (_leaderEntity->ai->leader->minionMax > 0))
        {
            for (std::uint32_t i = 0; i < _leaderEntity->ai->leader->minionCurrent; ++i)
            {
                // If slot available, spawn new
                if (_leaderEntity->ai->leader->minion[i].entity == nullptr)
                {
                    // calculate spawn position
                    glm::vec3 position = gMapTileToPosition(m_mapPointer, gClosestFreeTile(m_mapPointer, gMapPositionToTile(m_mapPointer, _leaderEntity->base.position)));
                    position.y = _leaderEntity->base.position.y;

                    // spawn entity
                    tEntity = spawnEntity(_leaderEntity->ai->leader->minionName, _leaderEntity->ai->leader->minionNumber, eDatabaseType::databaseTypeNpc, position);

                    if (tEntity != nullptr)
                    {
                        if (tEntity->ai == nullptr)
                        {
                            tEntity->ai = new sEntityAI;
                        }

                        tEntity->ai->leaderEntity = _leaderEntity;
                        _leaderEntity->ai->leader->minion[i].entity = tEntity;
                        _leaderEntity->ai->leader->minion[i].UID    = tEntity->UID;
                    }
                }
            }
        }
    }
}

void cEntityManager::m_setAnimationState(sEntity*& _entity, const glm::vec3& _animation)
{
    if (_entity->animation != nullptr)
    {
        // Set animation data
        _entity->animation->currentAnimTime   = _animation.x;
        _entity->animation->startAnimTime     = _animation.x;
        _entity->animation->stopAnimTime      = _animation.y;
        _entity->animation->repeatAnimation   = (_animation.z > 0.001);
        _entity->animation->finishedAnimation = false;
    }
};

void cEntityManager::m_physicsState(sEntity*& _entity, const ePhysicsType& _physicsType)
{
    if ((_entity->physics != nullptr) && (_physicsType != ePhysicsType::physicsTypeIgnore))
    {
        _entity->physics->type = _physicsType;
    }
}

void cEntityManager::m_tileCollisionState(sEntity*& _entity, const bool& _tilecollision)
{
    // Recalculate entity tile
    _entity->base.tileOnMap = gMapPositionToTile(m_mapPointer, _entity->base.position);

    if (_entity->tileCollision != nullptr)
    {
        // Calculate half width and half height
        std::uint32_t r = _entity->tileCollision->size / 2;

        // Transfer tile collision data to the map
        for (std::uint32_t h = 0; h < _entity->tileCollision->size; ++h)
        {
            for (std::uint32_t w = 0; w < _entity->tileCollision->size; ++w)
            {
                if (_entity->tileCollision->data[(h * _entity->tileCollision->size) + w] > 0)
                {
                    std::uint32_t tileNum = _entity->base.tileOnMap + ((h - r) * m_mapPointer->info.size_x) + (w - r);

                    // Add default tile object data to the map
                    if (_tilecollision == true)
                    {
                        // Set tiles impassable
                        if (m_mapPointer->tile[tileNum].type == eTileType::tileFloor)
                            m_mapPointer->tile[tileNum].type = eTileType::tileFloorNoGo;
                        else if (m_mapPointer->tile[tileNum].type == eTileType::tilePath)
                            m_mapPointer->tile[tileNum].type = eTileType::tilePathNoGo;
                        else if (m_mapPointer->tile[tileNum].type == eTileType::tileDoorway)
                            m_mapPointer->tile[tileNum].type = eTileType::tileDoorwayNoGo;

                        // Set as impassable entity type;
                        m_mapPointer->tile[tileNum].entity.type = eTileEntityType::tileEntityObjectStatic;
                    }
                    else
                    {
                        // Set tiles passable
                        if (m_mapPointer->tile[tileNum].type == eTileType::tileFloorNoGo)
                            m_mapPointer->tile[tileNum].type = eTileType::tileFloor;
                        else if (m_mapPointer->tile[tileNum].type == eTileType::tilePathNoGo)
                            m_mapPointer->tile[tileNum].type = eTileType::tilePath;
                        else if (m_mapPointer->tile[tileNum].type == eTileType::tileDoorwayNoGo)
                            m_mapPointer->tile[tileNum].type = eTileType::tileDoorway;

                        // Set as passable entity type;
                        m_mapPointer->tile[tileNum].entity.type = eTileEntityType::tileEntityNone;
                    }
                }
            }
        }
    }
    else
    {
        if (_tilecollision == true)
        {
            // Set tiles impassable
            if (m_mapPointer->tile[_entity->base.tileOnMap].type == eTileType::tileFloor)
                m_mapPointer->tile[_entity->base.tileOnMap].type = eTileType::tileFloorNoGo;
            else if (m_mapPointer->tile[_entity->base.tileOnMap].type == eTileType::tilePath)
                m_mapPointer->tile[_entity->base.tileOnMap].type = eTileType::tilePathNoGo;
            else if (m_mapPointer->tile[_entity->base.tileOnMap].type == eTileType::tileDoorway)
                m_mapPointer->tile[_entity->base.tileOnMap].type = eTileType::tileDoorwayNoGo;

            // Set as impassable entity type;
            m_mapPointer->tile[_entity->base.tileOnMap].entity.type = eTileEntityType::tileEntityObjectStatic;
        }
        else
        {
            // Set tiles passable
            if (m_mapPointer->tile[_entity->base.tileOnMap].type == eTileType::tileFloorNoGo)
                m_mapPointer->tile[_entity->base.tileOnMap].type = eTileType::tileFloor;
            else if (m_mapPointer->tile[_entity->base.tileOnMap].type == eTileType::tilePathNoGo)
                m_mapPointer->tile[_entity->base.tileOnMap].type = eTileType::tilePath;
            else if (m_mapPointer->tile[_entity->base.tileOnMap].type == eTileType::tileDoorwayNoGo)
                m_mapPointer->tile[_entity->base.tileOnMap].type = eTileType::tileDoorway;

            // Set as passable entity type;
            m_mapPointer->tile[_entity->base.tileOnMap].entity.UID = _entity->UID;
            m_mapPointer->tile[_entity->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;
        }
    }

    // Push event, so NPCs will recalculate path finding
    if (_tilecollision == true)
    {
        sEntityManagerEvent* event = new sEntityManagerEvent;
        event->type = sEntityManagerEventType::entityManagerEventType_modCollisions;
        event->data = _entity->UID; // Entity UID
        m_event.push(event);
    }
}

void cEntityManager::stateSet(sEntity*& _entity, const eEntityState &_state_1)
{
    //std::cout << "Setting state: " << _state_1 << std::endl;
    if (_entity->state != nullptr)
    {
        _entity->state->stateCurrent = _state_1;
        switch (_entity->state->stateCurrent)
        {
            case eEntityState::entityState_attack:
                m_setAnimationState(_entity, _entity->state->attack.animation);
                if (_entity->state->attack.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->attack.audio.sound->data);
                m_physicsState(_entity, _entity->state->attack.physicsState);
                m_tileCollisionState(_entity, _entity->state->attack.tileCollision);
            break;
            case eEntityState::entityState_defend:
                m_setAnimationState(_entity, _entity->state->defend.animation);
                if (_entity->state->defend.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->defend.audio.sound->data);
                m_physicsState(_entity, _entity->state->defend.physicsState);
                m_tileCollisionState(_entity, _entity->state->defend.tileCollision);
            break;
            case eEntityState::entityState_die:
                m_setAnimationState(_entity, _entity->state->die.animation);
                if (_entity->state->die.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->die.audio.sound->data);
                m_physicsState(_entity, _entity->state->die.physicsState);
                m_tileCollisionState(_entity, _entity->state->die.tileCollision);
            break;
            case eEntityState::entityState_idle:
                m_setAnimationState(_entity, _entity->state->idle.animation);
                if (_entity->state->idle.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->idle.audio.sound->data);
                m_physicsState(_entity, _entity->state->idle.physicsState);
                m_tileCollisionState(_entity, _entity->state->idle.tileCollision);
            break;
            case eEntityState::entityState_interact:
                m_setAnimationState(_entity, _entity->state->interact.animation);
                if (_entity->state->interact.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->interact.audio.sound->data);
                m_physicsState(_entity, _entity->state->interact.physicsState);
                m_tileCollisionState(_entity, _entity->state->interact.tileCollision);
            break;
            case eEntityState::entityState_move:
                m_setAnimationState(_entity, _entity->state->move.animation);
                if (_entity->state->move.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->move.audio.sound->data);
                m_physicsState(_entity, _entity->state->move.physicsState);
                m_tileCollisionState(_entity, _entity->state->move.tileCollision);
            break;
            case eEntityState::entityState_spawn:
                m_setAnimationState(_entity, _entity->state->spawn.animation);
                if (_entity->state->spawn.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->spawn.audio.sound->data);
                m_physicsState(_entity, _entity->state->spawn.physicsState);
                m_tileCollisionState(_entity, _entity->state->spawn.tileCollision);
            break;
            case eEntityState::entityState_open:
                m_setAnimationState(_entity, _entity->state->open.animation);
                if (_entity->state->open.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->open.audio.sound->data);
                m_physicsState(_entity, _entity->state->open.physicsState);
                m_tileCollisionState(_entity, _entity->state->open.tileCollision);
            break;
            case eEntityState::entityState_close:
                m_setAnimationState(_entity, _entity->state->close.animation);
                if (_entity->state->close.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->close.audio.sound->data);
                m_physicsState(_entity, _entity->state->close.physicsState);
                m_tileCollisionState(_entity, _entity->state->close.tileCollision);
            break;
            case eEntityState::entityState_levelUp:
                m_setAnimationState(_entity, _entity->state->levelUp.animation);
                if (_entity->state->levelUp.audio.sound != nullptr)
                    m_audioEngine->playSound(_entity->state->levelUp.audio.sound->data);
                m_physicsState(_entity, _entity->state->levelUp.physicsState);
                m_tileCollisionState(_entity, _entity->state->levelUp.tileCollision);
            break;
            default:
            case eEntityState::entityState_none:
            break;
        }
    }
}

void cEntityManager::stateToggle(sEntity*& _entity, const eEntityState &_state_1, const eEntityState &_state_2)
{
    if (_entity->state != nullptr)
    {
        if (_entity->state->stateCurrent == _state_1)
            stateSet(_entity, _state_2);
        else
            stateSet(_entity, _state_1);
    }
}

void cEntityManager::stateActivate(sEntity*& _entity, const eEntityState &_state_1)
{
    if (_entity->state != nullptr)
    {
        if (_entity->state->stateCurrent != _state_1)
        {
            stateSet(_entity, _state_1);
        }
    }
}

void cEntityManager::m_triggerEntity(sEntity*& _entity)
{
    // Early exit
    if (_entity == nullptr)
        return;

    // Handle custom interaction states
    if (_entity->interaction != nullptr)
    {
        // Handle state switch
        switch (_entity->interaction->type)
        {
            case eEntityInteraction::entityInteraction_set:
                stateSet(_entity, _entity->interaction->state_1);
            break;
            case eEntityInteraction::entityInteraction_toggle:
                stateToggle(_entity, _entity->interaction->state_1, _entity->interaction->state_2);
            break;
            case eEntityInteraction::entityInteraction_activate:
                stateActivate(_entity, _entity->interaction->state_1);
            break;
            default:
            case eEntityInteraction::entityInteraction_none:
            break;
        }

        // Trigger tile
        if (_entity->interaction->triggerTile > 0)
        {
            sEntity* tEntity = getEntityOnTile(_entity->interaction->triggerTile);
            m_triggerEntity(tEntity);
        }

        // Trigger event
        if (_entity->interaction->triggerEvent > 0)
        {
            m_mapPointer->event[_entity->interaction->triggerEvent - 1].triggered = true;;
        }

        // Loot:
        if (_entity->loot != nullptr)
        {
            // Determine spawn position
            glm::vec3 spawnPosition = _entity->base.position;
            spawnPosition.y = m_mapPointer->info.terrainHeight - 1.0f;

            // Gold
            if (_entity->loot->gold)
            {
                _entity->loot->gold = false;

                std::uint32_t gold = _entity->loot->gold_min;
                gold += rand() % (_entity->loot->gold_max - _entity->loot->gold_min);

                sEntity* tEntity = nullptr;
                tEntity = spawnEntity("coins", 0, eDatabaseType::databaseTypeItem, spawnPosition);
                tEntity->base.textActive = true;
                tEntity->base.textData = std::to_string(gold);
                tEntity->base.collectable = true;
                if (tEntity->loot == nullptr)
                {
                    tEntity->loot = new sEntityLoot;
                }
                tEntity->loot->gold     = true;
                tEntity->loot->gold_min = gold;
                tEntity->loot->gold_max = gold;
            }
        }
    }
}
