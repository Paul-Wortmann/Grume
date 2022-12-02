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

#include "model_obj.hpp"

void model_obj_import(sEntityModel *&_model, const std::string &_fileName)
{
    // Load using the standalone obj importer
    sOBJ *obj = nullptr;
    gLoadOBJ(obj, _fileName);

    // if load failed, early exit
    if (obj == nullptr)
        return;

    // convert obj data to to game engine specific format
    sEntityModel* tModel = new sEntityModel;
    tModel->fileName = _fileName;
    tModel->numMesh = obj->numMesh;
    tModel->mesh = new sEntityModelMesh[tModel->numMesh];
    for (std::uint32_t m = 0; m < tModel->numMesh; ++m)
    {
        tModel->mesh[m].numVertex = obj->numMesh;
        tModel->mesh[m].vertex = new sEntityModelVertex[tModel->mesh[m].numVertex];

        for (std::uint32_t v = 0; v < tModel->mesh[m].numVertex; ++v)
        {

        }

    }




    // Free the temporary obj data
    gFreeOBJ(obj);




}
