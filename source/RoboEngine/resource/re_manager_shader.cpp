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

#include "re_manager_shader.hpp"
#include "../graphics/re_shader.hpp"

namespace RoboEngine
{

    void re_cManagerShader::freeAll(void)
    {
        re_sShader* t_shader = m_head;
        while (t_shader != nullptr)
        {
            m_head = m_head->next;
            if (t_shader->ID != 0)
                freeShader(t_shader->ID);
            delete  t_shader;
            t_shader = m_head;
        }
        m_head = nullptr;
        m_tail = nullptr;
    }

    re_sShader *re_cManagerShader::getNew(std::string _fileName)
    {
        if (m_head == nullptr)
        {
            m_head = new re_sShader;
            m_tail = m_head;
            m_tail->next = nullptr;
            m_tail->fileName = _fileName;
            loadShader(_fileName, m_tail->ID, m_tail->numAttributes);
            return m_tail;
        }
        else
        {
            for (re_sShader *tempShader = m_head; tempShader != nullptr; tempShader = tempShader->next)
            {
                 if (_fileName.compare(tempShader->fileName.c_str()) == 0)
                    return(tempShader);
            }
            m_tail->next = new re_sShader;
            m_tail = m_tail->next;
            m_tail->next = nullptr;
            m_tail->fileName = _fileName;
            loadShader(_fileName, m_tail->ID, m_tail->numAttributes);
            return m_tail;
        }
        return nullptr;
    }

}
