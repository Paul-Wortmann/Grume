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

#include "model_loader_dae.hpp"

sEntityModel* loadModelDAE(const std::string &_fileName)
{
    // Check if the file exists
    if (fileExists(FILE_PATH_MODEL + _fileName))
    {
        // Data structure returning model
        sEntityModel* tModel = nullptr;

        // Open file
        std::ifstream daeFile (FILE_PATH_MODEL + _fileName, std::ios::binary);
        if(daeFile.is_open())
        {

            // Close the file
            daeFile.close();
        }
        else
        {
            gLogWrite(LOG_ERROR, "Failed to open file: " + std::string(FILE_PATH_MODEL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        }
        
        // return data
        return tModel;
    }
    else
    {
        // File not found
        gLogWrite(LOG_ERROR, "Failed to open file: " + std::string(FILE_PATH_MODEL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return nullptr;
    }
    return nullptr;
}


