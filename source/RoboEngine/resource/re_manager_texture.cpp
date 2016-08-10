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

#include "re_manager_texture.hpp"

namespace RoboEngine
{

    void re_cManagerTexture::freeAll(void)
    {
        re_sTexture* t_texture = m_head;
        while (t_texture != nullptr)
        {
            m_head = m_head->next;
            if (t_texture->ID != 0)
                freeTexture(t_texture->ID);
            delete  t_texture;
            t_texture = nullptr;
            t_texture = m_head;
        }
        m_head = nullptr;
        m_tail = nullptr;
    }

    re_sTexture *re_cManagerTexture::getNew(std::string _fileName)
    {
        if (m_head == nullptr)
        {
            m_head = new re_sTexture;
            m_head->fileName = _fileName;
            m_head->ID = loadTexture(_fileName);
            m_tail = m_head;
            return m_head;
        }
        else
        {
            for (re_sTexture *tempTex = m_head; tempTex != nullptr; tempTex = tempTex->next)
            {
                 if (_fileName.compare(tempTex->fileName.c_str()) == 0)
                    return(tempTex);
            }
            m_tail->next = new re_sTexture;
            m_tail->fileName = _fileName;
            m_tail->ID = loadTexture(_fileName);
            m_tail = m_tail->next;
            return m_tail;
        }
        return nullptr;
    }

}
