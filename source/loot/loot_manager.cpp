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

#include "loot_manager.hpp"
std::uint32_t cLootManager::initialize(void)
{
    return EXIT_SUCCESS;
}

void cLootManager::terminate(void)
{
    if (m_lootTable.entry != nullptr)
    {
        delete[] m_lootTable.entry;
        m_lootTable.entry = nullptr;
    }
}

void cLootManager::process(const float &_dt)
{
}

std::uint32_t cLootManager::loadLootTable(const std::string &_fileName)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    // Load the loot table file
    cXML xmlLootTableFile;
    xmlLootTableFile.load(FILE_PATH_CONFIG + _fileName);

    // If loot table database file contains data:
    if (xmlLootTableFile.lineCount() > 0)
    {
        // get a count of loot table loots
        m_lootTable.numEntry = xmlLootTableFile.getInstanceCount("<loot>");
        m_lootTable.entry = new sLootTableEntry[m_lootTable.numEntry];

        // load each loot table loot
        for (std::uint32_t i = 0; i < m_lootTable.numEntry; ++i)
        {
            // load loot data
            m_lootTable.entry[i].itemID = i + 1;
            m_lootTable.entry[i].entityName = xmlLootTableFile.getString("<entity_name>", i + 1);
            m_lootTable.entry[i].entityNumber = xmlLootTableFile.getInteger("<entity_number>", i + 1);
            m_lootTable.entry[i].value = xmlLootTableFile.getInteger("<value>", i + 1);
            m_lootTable.entry[i].dropOnce = (xmlLootTableFile.getInteger("<drop_once>", i + 1) > 0);
            m_lootTable.entry[i].itemType = static_cast<eLootTableEntryType>(xmlLootTableFile.getInteger("<item_type>", i + 1));

            // Update loot table value total
            m_lootTable.tableValue += m_lootTable.entry[i].value;
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to load file: " + std::string(FILE_PATH_CONFIG) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return_value = EXIT_FAILURE;
    }

    // Cleanup
    xmlLootTableFile.free();
    return return_value;
}

void cLootManager::getLoot(std::uint32_t &_itemID, std::string &_databaseName, std::uint32_t &_databaseNumber)
{
    // early exit
    if (m_lootTable.numEntry == 0)
    {
        _itemID = 0;
        return;
    }

    // if a drop once item has dropped already, drop random
    if ((_itemID > 0) &&
        (m_lootTable.entry[_itemID - 1].dropOnce == true) &&
        (m_lootTable.entry[_itemID - 1].dropCount > 0))
        _itemID = 0;

    // Random
    if (_itemID == 0)
    {
        _itemID = rand() % m_lootTable.numEntry;
        _itemID++;
    }

    if ((!m_lootTable.entry[_itemID - 1].dropOnce) ||
        ((m_lootTable.entry[_itemID - 1].dropOnce) && (m_lootTable.entry[_itemID - 1].dropCount == 0)))
    {
        _databaseName   = m_lootTable.entry[_itemID - 1].entityName;
        _databaseNumber = m_lootTable.entry[_itemID - 1].entityNumber;

        m_lootTable.entry[_itemID - 1].dropCount++;
    }

}
