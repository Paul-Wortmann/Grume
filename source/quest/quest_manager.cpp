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

#include "quest_manager.hpp"

std::uint32_t cQuestManager::initialize(void)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    return return_value;
}

void cQuestManager::freeData(sQuest*& _pointer)
{
}

void cQuestManager::terminate(void)
{
    freeAll();
}

void cQuestManager::process(const float &_dt)
{

}

void cQuestManager::setQuest(const std::string &_questName, const std::uint32_t &_state)
{
    bool questFound = false;
    for (sQuest* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if (temp->name.compare(_questName) == 0)
        {
            temp->state = _state;
            questFound = true;
        }
    }

    // Add the quest if it doesn't exist
    if (!questFound)
    {
        sQuest* temp = getNew();
        temp->name   = _questName;
        temp->state  = _state;
    }
}

std::uint32_t cQuestManager::getQuest(const std::string &_questName)
{
    // Return quest state
    for (sQuest* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if (temp->name.compare(_questName) == 0)
        {
            return temp->state;
        }
    }

    // If not found return 0
    return 0;
}

std::uint32_t cQuestManager::load(const std::string &_fileName)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    cXML xmlQuestFile;
    xmlQuestFile.load(std::string(FILE_PATH_CONFIG) + _fileName);

    // Only continue if we can load the game startup file
    if (xmlQuestFile.lineCount() > 0)
    {
        std::uint32_t questCount = xmlQuestFile.getInstanceCount("<quest>");
        for (std::uint32_t i = 0; i < questCount; ++i)
        {
            std::string tQuestData = xmlQuestFile.getString("<quest>", 1 + i);
            tQuestData += "    ";
            std::uint64_t tQuestDataLength = tQuestData.length();
            std::string tQuestName       = "";
            std::uint32_t tQuestState    = 0;
            std::uint32_t tStringNum = 0;
            std::string tString = "";
            if (tQuestDataLength > 6)
            {
                for (std::uint64_t j = 0; j < tQuestDataLength; ++j)
                {
                    if (tQuestData[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tQuestName = tString;
                        }
                        else if (tStringNum == 1)
                        {
                            tQuestState = std::stoi(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tQuestData[j];
                    }
                }
                setQuest(tQuestName, tQuestState);
            }
        }
    }
    else
    {
        // Log error, failed to load file
        gLogWrite(LOG_ERROR, "Failed to load file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);

        return_value = EXIT_FAILURE;
    }

    return return_value;
}
