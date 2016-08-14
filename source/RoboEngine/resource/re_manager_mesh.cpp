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

#include "re_manager_mesh.hpp"

namespace RoboEngine
{

    void re_cManagerMesh::freeAll(void)
    {
        re_sMesh* t_mesh = m_head;
        while (t_mesh != nullptr)
        {
            m_head = m_head->next;
            delete  [] t_mesh->index;
            t_mesh->index = nullptr;
            delete  t_mesh;
            t_mesh = nullptr;
            t_mesh = m_head;
        }
        m_head = nullptr;
        m_tail = nullptr;
    }

    re_sMesh *re_cManagerMesh::getNew(std::string _fileName)
    {
        if (m_head == nullptr)
        {
            m_head = new re_sMesh;
            m_head->fileName = _fileName;
            m_head->index = loadMesh(_fileName);
            m_tail = m_head;
            return m_head;
        }
        else
        {
            for (re_sMesh *tempMesh = m_head; tempMesh != nullptr; tempMesh = tempMesh->next)
            {
                 if (_fileName.compare(tempMesh->fileName.c_str()) == 0)
                    return(tempMesh);
            }
            m_tail->next = new re_sMesh;
            m_tail->fileName = _fileName;
            m_tail->index = loadMesh(_fileName);
            m_tail = m_tail->next;
            return m_tail;
        }
        return nullptr;
    }

    re_sIndex *re_cManagerMesh::loadMesh(std::string _fileName)
    {
        re_sdaeData *daeData = nullptr;
            daeImport(_fileName, daeData);
        daeDelete(daeData);
        /// incomplete!!!!
        /*
        re_sobjData *objData = nullptr;
        re_sdaeData *daeData = nullptr;
        const std::string fileExtention = "dae";
        if (fileExtention.compare("obj"))
        {
            objImport(_fileName, objData);
        }
        else if (fileExtention.compare("dae"))
        {
            daeImport(_fileName, daeData);
        }
        return nullptr;
        */
    }

}
