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

#include "model_loader_obj.hpp"

sEntityModel* loadModelOBJ(const std::string &_fileName)
{
    // Check if the file exists
    if (fileExists(FILE_PATH_MODEL+_fileName))
    {
        // Open file
        
        
        
        // return data
    }
    else
    {
        // File not found
        gLogWrite(LOG_ERROR, "Failed to open file: " + std::string(FILE_PATH_MODEL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return nullptr;
    }
    return nullptr;
}


