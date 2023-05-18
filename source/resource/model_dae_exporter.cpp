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

#include "model_dae.hpp"

void model_dae_export(sEntityModel* &_model, const std::string &_fileName)
{
    // Early exit if no data
    if (_model == nullptr)
    {
        return;
    }

    // indent lambda
    auto _il = [](const std::uint32_t &_level)
    {
        std::string s(_level * 2, ' ');
        return s;
    };

    // mesh name generation lambda
    auto _genMeshID = [](const std::string &_data)
    {
        std::uint64_t dataLength = _data.length();
        std::string   returnData = "";
        for (std::uint64_t i = 0; i < dataLength; ++i)
        {
            if ((std::isalpha(_data[i]) != 0) || (std::isdigit(_data[i]) != 0))
            {
                returnData += _data[i];
            }
            else
            {
                returnData += "_";
            }
        }
        return returnData;
    };

    std::ofstream daeFile (_fileName, std::ofstream::out | std::ios::trunc);
    if(daeFile.is_open())
    {
        std::uint32_t il = 0;

        daeFile << _il(il) << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
        daeFile << _il(il) << "<COLLADA xmlns=\"http://www.collada.org/2005/11/COLLADASchema\" version=\"1.4.1\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">" << std::endl;
        il++;
        // Asset
        daeFile << _il(il) << "<asset>" << std::endl;
        il++;
        daeFile << _il(il) << "<contributor>" << std::endl;
        il++;
        daeFile << _il(il) << "<author>Grume User</author>" << std::endl;
        daeFile << _il(il) << "<authoring_tool>Grume game engine</authoring_tool>" << std::endl;
        il--;
        daeFile << _il(il) << "</contributor>" << std::endl;
        daeFile << _il(il) << "<created>2023-08-11T07:58:02</created>" << std::endl;
        daeFile << _il(il) << "<modified>2023-08-11T07:58:02</modified>" << std::endl;
        daeFile << _il(il) << "<unit name=\"meter\" meter=\"1\"/>" << std::endl;

        // Engine uses z up axis
        daeFile << _il(il) << "<up_axis>Z_UP</up_axis>" << std::endl;
/*
        // If we were to support multiple up axes
        daeFile << _il(il) << "<up_axis>";
        if (_model->upAxis == eUpAxis::xUp)
            daeFile << "X_UP";
        else if (_model->upAxis == eUpAxis::xDown)
            daeFile << "X_DOWN";
        else if (_model->upAxis == eUpAxis::yUp)
            daeFile << "Y_UP";
        else if (_model->upAxis == eUpAxis::yDown)
            daeFile << "Y_DOWN";
        else if (_model->upAxis == eUpAxis::zUp)
            daeFile << "Z_UP";
        else if (_model->upAxis == eUpAxis::zDown)
            daeFile << "Z_DOWN";
        daeFile << "</up_axis>" << std::endl;
*/
        il--;
        daeFile << _il(il) << "</asset>" << std::endl;

        // library_effects
        daeFile << _il(il) << "<library_effects>" << std::endl;
        il++;
        for (std::uint32_t m = 0; m < _model->numMesh; ++m)
        {
            std::string meshID = _genMeshID(_model->mesh[m].name);

            daeFile << _il(il) << "<effect id=\"Material_" << meshID << "-effect\">" << std::endl;
            il++;
            daeFile << _il(il) << "<profile_COMMON>" << std::endl;
            il++;
            daeFile << _il(il) << "<technique sid=\"common\">" << std::endl;
            il++;
            daeFile << _il(il) << "<lambert>" << std::endl;
            il++;
            daeFile << _il(il) << "<emission>" << std::endl;
            il++;
            daeFile << _il(il) << "<color sid=\"emission\">0 0 0 1</color>" << std::endl;
            il--;
            daeFile << _il(il) << "</emission>" << std::endl;
            daeFile << _il(il) << "<diffuse>" << std::endl;
            il++;
            daeFile << _il(il) << "<color sid=\"diffuse\">0.8 0.8 0.8 1</color>" << std::endl;
            il--;
            daeFile << _il(il) << "</diffuse>" << std::endl;
            daeFile << _il(il) << "<index_of_refraction>" << std::endl;
            il++;
            daeFile << _il(il) << "<float sid=\"ior\">1.45</float>" << std::endl;
            il--;
            daeFile << _il(il) << "</index_of_refraction>" << std::endl;
            il--;
            daeFile << _il(il) << "</lambert>" << std::endl;
            il--;
            daeFile << _il(il) << "</technique>" << std::endl;
            il--;
            daeFile << _il(il) << "</profile_COMMON>" << std::endl;
            il--;
            daeFile << _il(il) << "</effect>" << std::endl;
        }

        il--;
        daeFile << _il(il) << "</library_effects>" << std::endl;
        daeFile << _il(il) << "<library_images/>" << std::endl;

        // library_materials
        daeFile << _il(il) << "<library_materials>" << std::endl;
        il++;
        for (std::uint32_t m = 0; m < _model->numMesh; ++m)
        {
            std::string meshID = _genMeshID(_model->mesh[m].name);

            daeFile << _il(il) << "<material id=\"Material_" << meshID << "-material\" name=\"Material_" << meshID << "\">" << std::endl;
            il++;
            daeFile << _il(il) << "<instance_effect url=\"#Material_" << meshID << "-effect\"/>" << std::endl;
            il--;
            daeFile << _il(il) << "</material>" << std::endl;
        }
        il--;
        daeFile << _il(il) << "</library_materials>" << std::endl;


        // library_geometries
        daeFile << _il(il) << "<library_geometries>" << std::endl;
        il++;
        for (std::uint32_t m = 0; m < _model->numMesh; ++m)
        {
            std::string meshID = _genMeshID(_model->mesh[m].name);

            daeFile << _il(il) << "<geometry id=\"" << meshID << "-mesh\" name=\"" << _model->mesh[m].name << "\">" << std::endl;
            il++;
            daeFile << _il(il) << "<mesh>" << std::endl;
            il++;

            // Positions data
            daeFile << _il(il) << "<source id=\"" << meshID << "-mesh-positions\">" << std::endl;
            il++;
            daeFile << _il(il) << "<float_array id=\"" << meshID << "-mesh-positions-array\" count=\"" << _model->mesh[m].numVertex << "\">";
            for (std::uint32_t i = 0; i < _model->mesh[m].numVertex; ++i)
            {
                daeFile << std::to_string(_model->mesh[m].vertex[i].position.x) << " ";
                daeFile << std::to_string(_model->mesh[m].vertex[i].position.y) << " ";
                daeFile << std::to_string(_model->mesh[m].vertex[i].position.z);
                if (i < _model->mesh[m].numVertex - 1)
                    daeFile << " ";
            }
            daeFile << "</float_array>" << std::endl;
            daeFile << _il(il) << "<technique_common>" << std::endl;
            il++;
            daeFile << _il(il) << "<accessor source=\"#" << meshID << "-mesh-positions-array\" count=\"" << _model->mesh[m].numVertex / 3 << "\" stride=\"3\">" << std::endl;
            il++;
            daeFile << _il(il) << "<param name=\"X\" type=\"float\"/>" << std::endl;
            daeFile << _il(il) << "<param name=\"Y\" type=\"float\"/>" << std::endl;
            daeFile << _il(il) << "<param name=\"Z\" type=\"float\"/>" << std::endl;
            il--;
            daeFile << _il(il) << "</accessor>" << std::endl;
            il--;
            daeFile << _il(il) << "</technique_common>" << std::endl;
            il--;
            daeFile << _il(il) << "</source>" << std::endl;

            // Normals data
            daeFile << _il(il) << "<source id=\"" << meshID << "-mesh-normals\">" << std::endl;
            il++;
            daeFile << _il(il) << "<float_array id=\"" << meshID << "-mesh-normals-array\" count=\"" << _model->mesh[m].numVertex << "\">";
            for (std::uint32_t i = 0; i < _model->mesh[m].numVertex; ++i)
            {
                daeFile << std::to_string(_model->mesh[m].vertex[i].normal.x) << " ";
                daeFile << std::to_string(_model->mesh[m].vertex[i].normal.y) << " ";
                daeFile << std::to_string(_model->mesh[m].vertex[i].normal.z);
                if (i < _model->mesh[m].numVertex - 1)
                    daeFile << " ";
            }
            daeFile << "</float_array>" << std::endl;
            daeFile << _il(il) << "<technique_common>" << std::endl;
            il++;
            daeFile << _il(il) << "<accessor source=\"#" << meshID << "-mesh-normals-array\" count=\"" << _model->mesh[m].numVertex / 3 << "\" stride=\"3\">" << std::endl;
            il++;
            daeFile << _il(il) << "<param name=\"X\" type=\"float\"/>" << std::endl;
            daeFile << _il(il) << "<param name=\"Y\" type=\"float\"/>" << std::endl;
            daeFile << _il(il) << "<param name=\"Z\" type=\"float\"/>" << std::endl;
            il--;
            daeFile << _il(il) << "</accessor>" << std::endl;
            il--;
            daeFile << _il(il) << "</technique_common>" << std::endl;
            il--;
            daeFile << _il(il) << "</source>" << std::endl;

            // texture coordinate data
            daeFile << _il(il) << "<source id=\"" << meshID << "-mesh-map-0\">" << std::endl;
            il++;
            daeFile << _il(il) << "<float_array id=\"" << meshID << "-mesh-map-0-array\" count=\"" << _model->mesh[m].numVertex << "\">";
            for (std::uint32_t i = 0; i < _model->mesh[m].numVertex; ++i)
            {
                daeFile << std::to_string(_model->mesh[m].vertex[i].texcoord.x) << " ";
                daeFile << std::to_string(_model->mesh[m].vertex[i].texcoord.y);
                if (i < _model->mesh[m].numVertex - 1)
                    daeFile << " ";
            }
            daeFile << "</float_array>" << std::endl;
            daeFile << _il(il) << "<technique_common>" << std::endl;
            il++;
            daeFile << _il(il) << "<accessor source=\"#" << meshID << "-mesh-map-0-array\" count=\"" << _model->mesh[m].numVertex / 2 << "\" stride=\"2\">" << std::endl;
            il++;
            daeFile << _il(il) << "<param name=\"S\" type=\"float\"/>" << std::endl;
            daeFile << _il(il) << "<param name=\"T\" type=\"float\"/>" << std::endl;
            il--;
            daeFile << _il(il) << "</accessor>" << std::endl;
            il--;
            daeFile << _il(il) << "</technique_common>" << std::endl;
            il--;
            daeFile << _il(il) << "</source>" << std::endl;

            // Vertices data
            daeFile << _il(il) << "<vertices id=\"" << meshID << "-mesh-vertices\">" << std::endl;
            il++;
            daeFile << _il(il) << "<input semantic=\"POSITION\" source=\"#" << meshID << "-mesh-positions\"/>" << std::endl;
            il--;
            daeFile << _il(il) << "</vertices>" << std::endl;
            daeFile << _il(il) << "<triangles material=\"Material_" << meshID << "-material\" count=\"" << _model->mesh[m].numVertex / 3 << "\">" << std::endl;
            il++;
            daeFile << _il(il) << "<input semantic=\"VERTEX\" source=\"#" << meshID << "-mesh-vertices\" offset=\"0\"/>" << std::endl;
            daeFile << _il(il) << "<input semantic=\"NORMAL\" source=\"#" << meshID << "-mesh-normals\" offset=\"1\"/>" << std::endl;
            daeFile << _il(il) << "<input semantic=\"TEXCOORD\" source=\"#" << meshID << "-mesh-map-0\" offset=\"2\" set=\"0\"/>" << std::endl;
            daeFile << _il(il) << "<p>";
            for (std::uint32_t i = 0; i < _model->mesh[m].numIndex; ++i)
            {
                daeFile << std::to_string(_model->mesh[m].index[i]) << " ";
                daeFile << std::to_string(_model->mesh[m].index[i]) << " ";
                daeFile << std::to_string(_model->mesh[m].index[i]);
                if (i < _model->mesh[m].numIndex - 1)
                    daeFile << " ";
            }
            daeFile << "</p>" << std::endl;
            il--;
            daeFile << _il(il) << "</triangles>" << std::endl;
            il--;
            daeFile << _il(il) << "</mesh>" << std::endl;
            il--;
            daeFile << _il(il) << "</geometry>" << std::endl;
        }
        il--;
        daeFile << _il(il) << "</library_geometries>" << std::endl;

        // library_visual_scenes
        daeFile << _il(il) << "<library_visual_scenes>" << std::endl;
        il++;
        daeFile << _il(il) << "<visual_scene id=\"Scene\" name=\"Scene\">" << std::endl;
        il++;
        for (std::uint32_t m = 0; m < _model->numMesh; ++m)
        {
            std::string meshID = _genMeshID(_model->mesh[m].name);

            daeFile << _il(il) << "<node id=\"" << meshID << "\" name=\"" << _model->mesh[m].name << "\" type=\"NODE\">" << std::endl;
            il++;
            daeFile << _il(il) << "<matrix sid=\"transform\">1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1</matrix>" << std::endl;
            daeFile << _il(il) << "<instance_geometry url=\"#" << meshID << "-mesh\" name=\"" << _model->mesh[m].name << "\">" << std::endl;
            il++;
            daeFile << _il(il) << "<bind_material>" << std::endl;
            il++;
            daeFile << _il(il) << "<technique_common>" << std::endl;
            il++;
            daeFile << _il(il) << "<instance_material symbol=\"Material_" << meshID << "-material\" target=\"#Material_" << meshID << "-material\">" << std::endl;
            il++;
            daeFile << _il(il) << "<bind_vertex_input semantic=\"UVMap\" input_semantic=\"TEXCOORD\" input_set=\"0\"/>" << std::endl;
            il--;
            daeFile << _il(il) << "</instance_material>" << std::endl;
            il--;
            daeFile << _il(il) << "</technique_common>" << std::endl;
            il--;
            daeFile << _il(il) << "</bind_material>" << std::endl;
            il--;
            daeFile << _il(il) << "</instance_geometry>" << std::endl;
            il--;
            daeFile << _il(il) << "</node>" << std::endl;
        }

        il--;
        daeFile << _il(il) << "</visual_scene>" << std::endl;
        il--;
        daeFile << _il(il) << "</library_visual_scenes>" << std::endl;

        // Scene
        daeFile << _il(il) << "<scene>" << std::endl;
        il++;
        daeFile << _il(il) << "<instance_visual_scene url=\"#Scene\"/>" << std::endl;
        il--;
        daeFile << _il(il) << "</scene>" << std::endl;
        il--;
        daeFile << _il(il) << "</COLLADA>" << std::endl;

        // Clean up
        daeFile.close();
    }

}

