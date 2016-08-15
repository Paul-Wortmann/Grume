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
            loadMesh(_fileName, m_head);
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
            loadMesh(_fileName, m_tail);
            m_tail = m_tail->next;
            return m_tail;
        }
        return nullptr;
    }

    void re_cManagerMesh:: loadMesh(std::string _fileName, re_sMesh *&_mesh)
    {
        const std::string fileExt = fileExtention(_fileName);
        if (fileExt.compare("dae") == 0)
        {
            re_sdaeData *daeData = nullptr;
            daeImport(_fileName, daeData);
            _mesh->indexCount = daeData->face_count;
            _mesh->index = new v8_f[_mesh->indexCount];
            for (uint16_t i = 0; i < _mesh->indexCount; i++)
            {
                _mesh->index[i].x = daeData->face[i].x;
                _mesh->index[i].y = daeData->face[i].y;
                _mesh->index[i].z = daeData->face[i].z;
                _mesh->index[i].nx = daeData->face[i].nx;
                _mesh->index[i].ny = daeData->face[i].ny;
                _mesh->index[i].nz = daeData->face[i].nz;
                _mesh->index[i].s = daeData->face[i].s;
                _mesh->index[i].t = daeData->face[i].t;
            }
            daeDelete(daeData);
        }
        else if (fileExt.compare("obj") == 0)
        {
            re_sobjData *objData = nullptr;
            objImport(_fileName, objData);
            _mesh->indexCount = objData->face_count * 3;
            _mesh->index = new v8_f[_mesh->indexCount];
            for (uint16_t i = 0; i < objData->face_count; i++)
            {
                for (uint16_t j = 0; j < 3; j++)
                {
                    _mesh->index[(i*3)+j].x = objData->vertex[objData->face[i].p[j].x].x;
                    _mesh->index[(i*3)+j].y = objData->vertex[objData->face[i].p[j].x].y;
                    _mesh->index[(i*3)+j].z = objData->vertex[objData->face[i].p[j].x].z;
                    _mesh->index[(i*3)+j].nx = objData->vertex_normal[objData->face[i].p[j].y].x;
                    _mesh->index[(i*3)+j].ny = objData->vertex_normal[objData->face[i].p[j].y].y;
                    _mesh->index[(i*3)+j].nz = objData->vertex_normal[objData->face[i].p[j].y].z;
                    _mesh->index[(i*3)+j].s = objData->vertex_texture[objData->face[i].p[j].z].x;
                    _mesh->index[(i*3)+j].t = objData->vertex_texture[objData->face[i].p[j].z].y;
                }
            }
            objDelete(objData);
        }
        else
        {
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> unsupported file type : " + _fileName);
        }
    }

}
