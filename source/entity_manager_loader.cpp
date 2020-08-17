
#include "entity_manager.hpp"

sEntity* cEntityManager::loadFile(const std::string &_fileName)
{
    /*
    std::ifstream file_pointer;
    file_pointer.open (_fileName, std::ifstream::in);
    if (!file_pointer.good())
        gLogWrite(LOG_ERROR, "Unable to open entity file :  " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    else
    {
        sEntity* entity = nullptr;
        entity = getNew();
        bool needAnimation = false;
        bool needAudio     = false;
        bool needEvent     = false;
        bool needLight     = false;
        bool needPhysics   = false;
        bool needRender    = false;
        bool needTransform = false;

        uint32_t s_temp_length = 0;
        std::string s_temp = "";
        while (std::getline(file_pointer, s_temp))
        {
            s_temp_length = s_temp.length();

            if (s_temp.find("default_position") < s_temp_length)
                needTransform = true;
            if (s_temp.find("default_scale") < s_temp_length)
                needTransform = true;
            if (s_temp.find("default_rotation") < s_temp_length)
                needTransform = true;
            if (needTransform)
                _entityManager.addTransformComponent(entity);

            if (s_temp.find("shader") < s_temp_length)
                needRender = true;
            if (s_temp.find("texture") < s_temp_length)
                needRender = true;
            if (s_temp.find("mesh") < s_temp_length)
                needRender = true;
            if (s_temp.find("shininess") < s_temp_length)
                needRender = true;
            if (needRender)
                _entityManager.addRenderComponent(entity);

            if (s_temp.find("ambient") < s_temp_length)
                needLight = true;
            if (s_temp.find("diffuse") < s_temp_length)
                needLight = true;
            if (s_temp.find("specular") < s_temp_length)
                needLight = true;
            if (s_temp.find("constant") < s_temp_length)
                needLight = true;
            if (s_temp.find("linear") < s_temp_length)
                needLight = true;
            if (s_temp.find("quadratic") < s_temp_length)
                needLight = true;
            if (needLight)
                _entityManager.addLightComponent(entity);

            //if (needPhysics)
            //    _entityManager.addPhysicsComponent(entity);
            //if (needAudio)
            //    _entityManager.addAudioComponent(entity);
            //if (needEvent)
            //    _entityManager.addEventComponent(entity);
        }
        file_pointer.clear();
        file_pointer.seekg(0, std::ios::beg);

        bool is_default_position = false;
        bool is_default_scale    = false;
        bool is_default_rotation = false;

        bool is_texture          = false;
        bool is_mesh             = false;
        bool is_shader           = false;

        bool is_light_ambient    = false;
        bool is_light_diffuse    = false;
        bool is_light_specular   = false;
        bool is_light_constant   = false;
        bool is_light_linear     = false;
        bool is_light_quadratic  = false;

        while (std::getline(file_pointer, s_temp))
        {
            s_temp_length = s_temp.length();

            if (s_temp.find("default_position") < s_temp_length)
                is_default_position = true;
            if (s_temp.find("default_scale") < s_temp_length)
                is_default_scale = true;
            if (s_temp.find("default_rotation") < s_temp_length)
                is_default_rotation = true;

            if (s_temp.find("ambient") < s_temp_length)
                is_light_ambient = true;
            if (s_temp.find("diffuse") < s_temp_length)
                is_light_diffuse = true;
            if (s_temp.find("specular") < s_temp_length)
                is_light_specular = true;

            if ((is_default_position) || (is_default_scale) || (is_default_rotation) || (is_light_ambient) || (is_light_diffuse) || (is_light_specular))
            {
                float       value_1 = 0.0f;
                float       value_2 = 0.0f;
                float       value_3 = 0.0f;
                uint16_t    sCount  = 0;
                bool        ready   = false;
                std::string temp    = "";
                for (uint64_t i = 0; i < s_temp.length(); i++)
                {
                    if (!ready)
                    {
                        if (s_temp[i] == '>')
                            ready = true;
                    }
                    else
                    {
                        if (s_temp[i] == ' ')
                        {
                            sCount++;
                            if (sCount == 1)
                                value_1 = stof(temp);
                            if (sCount == 2)
                                value_2 = stof(temp);
                            if (sCount == 3)
                                value_3 = stof(temp);
                            temp = "";
                        }
                        else
                            temp += s_temp[i];
                        if (s_temp[i] == '<')
                        {
                            ready = false;
                            value_3 = stof(temp);
                        }
                    }
                }
                // transform
                if (is_default_position)
                {
                    _entityManager.setTransformPosition(entity, glm::vec3(value_1, value_2, value_3));
                    is_default_position = false;
                }
                if (is_default_scale)
                {
                    _entityManager.setTransformScale(entity, glm::vec3(value_1, value_2, value_3));
                    is_default_scale = false;
                }
                if (is_default_rotation)
                {
                    _entityManager.setTransformRotation(entity, glm::vec3(value_1, value_2, value_3));
                    is_default_rotation = false;
                }
                // light
                if (is_light_ambient)
                {
                    _entityManager.setLightColorAmbient(entity, glm::vec3(value_1, value_2, value_3));
                    is_light_ambient = false;
                }
                if (is_light_diffuse)
                {
                    _entityManager.setLightColorDiffuse(entity, glm::vec3(value_1, value_2, value_3));
                    is_light_diffuse = false;
                }
                if (is_light_specular)
                {
                    _entityManager.setLightColorSpecular(entity, glm::vec3(value_1, value_2, value_3));
                    is_light_specular = false;
                }
                //std::cout << "Data: " << std::to_string(value_1) << " - " << std::to_string(value_2) << " - " << std::to_string(value_3) << std::endl;
            }

            if (s_temp.find("shader") < s_temp_length)
                is_shader = true;
            if (s_temp.find("mesh") < s_temp_length)
                is_mesh = true;
            if (s_temp.find("texture") < s_temp_length)
                is_texture = true;

            if (s_temp.find("constant") < s_temp_length)
                is_light_constant = true;
            if (s_temp.find("linear") < s_temp_length)
                is_light_linear = true;
            if (s_temp.find("quadratic") < s_temp_length)
                is_light_quadratic = true;

            if ((is_shader) || (is_mesh) || (is_texture) || (is_light_constant) || (is_light_linear) || (is_light_quadratic))
            {
                bool        ready   = false;
                std::string temp    = "";
                for (uint64_t i = 0; i < s_temp.length(); i++)
                {
                    if (!ready)
                    {
                        if (s_temp[i] == '>')
                            ready = true;
                    }
                    else
                    {
                        if (s_temp[i] == '<')
                            ready = false;
                        else
                            temp += s_temp[i];
                    }
                }
                // render
                if (is_shader)
                {
                    _entityManager.addRenderShader(entity, temp.c_str());
                    is_shader = false;
                }
                if (is_mesh)
                {
                    _entityManager.addRenderMesh(entity, temp.c_str());
                    is_mesh = false;
                    //if has animation data, create animation component
                    // import animations
                }
                if (is_texture)
                {
                    _entityManager.addRenderTexture(entity, temp.c_str());
                    is_texture = false;
                }

                //light
                if (is_light_constant)
                {
                    _entityManager.setLightAttenuationConstant(entity, std::stof(temp.c_str()));
                    is_light_constant = false;
                }
                if (is_light_linear)
                {
                    _entityManager.setLightAttenuationLinear(entity, std::stof(temp.c_str()));
                    is_light_linear = false;
                }
                if (is_light_quadratic)
                {
                    _entityManager.setLightAttenuationQuadratic(entity, std::stof(temp.c_str()));
                    is_light_quadratic = false;
                }

                //std::cout << "Data: " << temp << std::endl;
            }
        }
        file_pointer.close();
        return entity;
    }
     * */
    return nullptr;
}
