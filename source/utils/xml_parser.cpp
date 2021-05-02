

#include "xml_parser.hpp"

void cXML::load(const std::string &_fileName)
{
    m_lineCount = 0;
    std::ifstream fileIn(_fileName.c_str());
    if(fileIn.is_open())
    {
        std::string lineData;
        while (std::getline(fileIn, lineData))
        {
            m_lineCount++;
        }
        fileIn.clear();
        fileIn.seekg (0, std::ios::beg);
        m_line = new std::string[m_lineCount];
        uint32 lineNum = 0;
        while (std::getline(fileIn, lineData))
        {
            m_line[lineNum] = lineData.c_str();
            lineNum++;
        }
        fileIn.close();
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}

uint32 cXML::getInstanceCount(const std::string &_key)
{
    uint32 instanceCount = 0;
    for (uint32 i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
        }
    }
    return instanceCount;
}

std::string cXML::getString(const std::string &_key, const uint32 _instance)
{
    uint32 instanceCount = 0;
    std::string rString = "";
    for (uint32 i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
            if (instanceCount == _instance)
            {
                uint32 start = m_line[i].find(_key) + _key.length();
                for(uint32 j = start; j < m_line[i].length(); ++j)
                {
                    if (m_line[i][j] == '<')
                    {
                        j = m_line[i].length();
                    }
                    else
                    {
                        if (m_line[i][j] != '>')
                        {
                            rString += m_line[i][j];
                        }
                    }
                }
                return rString;
            }
        }
    }
    return rString;
}

uint32 cXML::getInteger(const std::string &_key, const uint32 _instance)
{
    std::string value = getString(_key, _instance);
    if (value.length() < 1)
    {
        return 0;
    }
    return std::stoi(value);
}

float cXML::getFloat(const std::string &_key, const uint32 _instance)
{
    std::string value = getString(_key, _instance);
    if (value.length() < 1)
    {
        return 0;
    }
    return std::stof(value);
}

glm::vec3 cXML::getVec3(const std::string &_key, const uint32 _instance)
{
    uint32 instanceCount = 0;
    glm::vec3 rVec;
    for (uint32 i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
            if (instanceCount == _instance)
            {
                std::string v[3];
                uint16 pos = 0;
                uint32 start = m_line[i].find(_key) + _key.length();
                for(uint32 j = start; j < m_line[i].length(); ++j)
                {
                    if (m_line[i][j] == '<')
                    {
                        j = m_line[i].length();
                    }
                    else
                    {
                        if (m_line[i][j] != '>')
                        {
                            if (m_line[i][j] == ' ')
                            {
                                pos++;
                            }
                            else
                            {
                                v[pos] += m_line[i][j];
                            }
                        }
                    }
                }
                rVec = glm::vec3(std::stof(v[0]), std::stof(v[1]), std::stof(v[2]));
                return rVec;
            }
        }
    }
    return rVec;
}

glm::vec2 cXML::getVec2(const std::string &_key, const uint32 _instance)
{
    uint32 instanceCount = 0;
    glm::vec2 rVec;
    for (uint32 i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
            if (instanceCount == _instance)
            {
                std::string v[2];
                uint16 pos = 0;
                uint32 start = m_line[i].find(_key) + _key.length();
                for(uint32 j = start; j < m_line[i].length(); ++j)
                {
                    if (m_line[i][j] == '<')
                    {
                        j = m_line[i].length();
                    }
                    else
                    {
                        if (m_line[i][j] != '>')
                        {
                            if (m_line[i][j] == ' ')
                            {
                                pos++;
                            }
                            else
                            {
                                v[pos] += m_line[i][j];
                            }
                        }
                    }
                }
                rVec = glm::vec2(std::stof(v[0]), std::stof(v[1]));
                return rVec;
            }
        }
    }
    return rVec;
}
