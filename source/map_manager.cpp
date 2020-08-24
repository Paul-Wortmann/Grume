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

#include "map_manager.hpp"


void cMapManager::initialize(void)
{
    std::string libRMGVersion = std::to_string(LIBRMG_VERSION_MAJOR) + "." + std::to_string(LIBRMG_VERSION_MINOR) + "." + std::to_string(LIBRMG_VERSION_PATCH);
    gLogWrite(LOG_INFO, "LibRMG version: " + libRMGVersion, __FILE__, __LINE__, __FUNCTION__);

    m_map.init();
}

void cMapManager::terminate(void)
{
    m_map.free();
}

void cMapManager::process(void)
{

}

void cMapManager::setEntityManagerHandle(cEntityManager *_entityManager)
{
    m_entityManager = _entityManager;
}
