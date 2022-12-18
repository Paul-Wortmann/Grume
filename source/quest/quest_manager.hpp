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

#ifndef QUEST_MANAGER_HPP
#define QUEST_MANAGER_HPP

#include "quest_define.hpp"

class cQuestManager : public tcLinkedList<sQuest>
{
    public:
        std::uint32_t     initialize(void);
        void              terminate(void);
        void              setQuest(const std::string &_questName, const std::uint32_t &_state);
        std::uint32_t     getQuest(const std::string &_questName);
        std::uint32_t     load(const std::string &_fileName);

    protected:
    private:
        void freeData(sQuest *&_pointer) override;
};

#endif // QUEST_MANAGER_HPP
