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

#include "map_loader.hpp"
#include "../RoboEngine/roboengine.hpp"

/*

void fnf_map::load(const std::string &_fileName, RoboEngine::re_cEntityManager *_entityManager)
{
    std::string mapFile = _fileName + ".map";
    RoboEngine::re_sxmlData* xml_data = nullptr;
    RoboEngine::re_xml_parse(mapFile, xml_data);
    if (xml_data != nullptr)
    {
        uint64_t count_e = RoboEngine::re_xml_get_count(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "entity");
        std::cout << "Entity count : " << std::to_string(count_e) << std::endl;
        for (uint64_t i = count_e; i > 0; i--)
        {
            uint32_t entity = _entityManager->getNew()->ID;
            _entityManager->addPhysics(entity);
            _entityManager->addRender(entity);
            _entityManager->addTexture(entity, "data/texture/" + RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "texture", i, "name"));
            _entityManager->addMesh(entity, "data/mesh/" + RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "model", i, "name"));
            _entityManager->addShader(entity, "data/shader/" + RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "shader", i, "name"));
            _entityManager->setScale(entity, glm::vec3(std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "dimension", i, "x")), std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "dimension", i, "y")), std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "dimension", i, "z"))));
            _entityManager->setRotation(entity, glm::vec3(std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "orientation", i, "x")), std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "orientation", i, "y")), std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "orientation", i, "z"))));
            _entityManager->setPosition(entity, glm::vec3(std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "position", i, "x")), std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "position", i, "y")), std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "position", i, "z"))));
            if (RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "entity", i, "type").compare("static") != 0)
                _entityManager->setDynamic(m_playerID, true);
            if (RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "entity", i, "type").compare("player_character") == 0)
            {
                m_playerID = entity;
                glm::vec3 entityPosition = getEntityPosition(m_playerID);
                glm::vec3 cameraPosition = getCameraPosition();
                setCameraPosition(glm::vec3(entityPosition.x, entityPosition.y, cameraPosition.z), entityPosition);
            }
            setEntityState(entity, false); // delete me, should be set in xml file
            RoboEngine::re_logWrite("Added Entity ID: " + std::to_string(entity), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
        }
    }
    re_xml_delete(xml_data);
}

void fnf_map::generate(uint32_t _size)
{
    uint32_t entity = getNewEntity();
    addEntityPhysics(entity);
    addEntityRender(entity);
    addEntityTexture(entity, "data/texture/default");
    addEntityShader(entity, "data/shader/default");
    genEntityMesh(entity, _size);
    RoboEngine::re_logWrite("Added Entity ID: " + std::to_string(entity), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
}

*/
