/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */


#include "graphics_engine_vao_manager.hpp"
#include "core.hpp"

extern core_struct core;

vao_manager_class::vao_manager_class(void)
{
    vao_manager_class::last               = NULL;
    vao_manager_class::root               = NULL;
    vao_manager_class::number_of_vaos     = 0;
};

vao_manager_class::~vao_manager_class(void)
{
    vao_type* temp_pointer;
    temp_pointer = vao_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            //delete [] temp_pointer->data.;
            temp_pointer = temp_pointer->next;
        }
    }
    //delete [] root;
    //delete [] last;
};

vao_type* vao_manager_class::add_vao(vao_data_type *vao_data_pointer)
{
    if (vao_manager_class::number_of_vaos == 0)
    {
        vao_manager_class::root = new vao_type;
        vao_manager_class::root->next = NULL;
        vao_manager_class::last = new vao_type;
        vao_manager_class::last = root;
        vao_manager_class::last->next = NULL;
    }
    else
    {
        vao_type* temp_pointer = vao_manager_class::root;
        if (temp_pointer != NULL) while (temp_pointer != NULL) temp_pointer = temp_pointer->next;
        vao_manager_class::last->next        = new vao_type;
        vao_manager_class::last              = vao_manager_class::last->next;
        vao_manager_class::last->next        = new vao_type;
        vao_manager_class::last->next        = NULL;
    }
    vao_manager_class::last->data        = *vao_data_pointer;
    vao_manager_class::last->data.loaded = vao_manager_class::load_vao(last);
    vao_manager_class::last->data.vao_id = vao_manager_class::number_of_vaos + 1;
    if (vao_manager_class::last->data.loaded) vao_manager_class::number_of_vaos++;
    return(vao_manager_class::last);
}

bool vao_manager_class::load_vao(vao_type *vao_pointer)
{
    bool return_value = true;
    glGenVertexArrays(1, &vao_pointer->data.vao_data);
    glBindVertexArray(vao_pointer->data.vao_data);
    glGenBuffers(vao_pointer->data.number_of_vbo, vao_pointer->data.vbo_data);
    glBindBuffer(GL_ARRAY_BUFFER, vao_pointer->data.vbo_data[0]);
    glBufferData(GL_ARRAY_BUFFER, 3*vao_pointer->data.number_of_vertex*sizeof(GLfloat), vao_pointer->data.vertex, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vao_pointer->data.vbo_data[1]);
    glBufferData(GL_ARRAY_BUFFER, 3*vao_pointer->data.number_of_vertex*sizeof(GLfloat), vao_pointer->data.color, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);
    return (return_value);
}




























