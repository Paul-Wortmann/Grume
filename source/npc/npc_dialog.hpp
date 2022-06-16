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

#ifndef NPC_DIALOG_HPP
#define NPC_DIALOG_HPP

#include "../core/includes.hpp"
#include "../core/game_database.hpp"
#include "../entity/entity_manager.hpp"

enum class eDialogEffectType : std::uint16_t 
{
    effectNone       = 0, // None
    effectGiveEXP    = 1, // Give EXP
    effectTakeEXP    = 2, // Take EXP
    effectGiveGold   = 3, // Give gold
    effectTakeGold   = 4, // Take gold
    effectGiveHealth = 5, // Give health
    effectTakeHealth = 6  // Take health
};

struct sDialogResponse
{
    std::string        text              = {};
    std::uint32_t      nextNode          = 0;

    // Effect
    std::uint32_t      numEffect         = 0;
    eDialogEffectType* effectType        = nullptr;
    bool*              enabledEffects    = nullptr;
    bool*              repeatableEffects = nullptr;
};

struct sDialogText
{
    std::string      text        = {};
    std::uint32_t    numResponse = 0;
    sDialogResponse* response    = nullptr;
};

struct sDialogTree
{
    // ID
    std::uint32_t nodeID  = 0;

    // Node
    std::uint32_t numNode = 0;
    sDialogTree*  node    = nullptr;
    
    // Data
    sDialogText*  dialog  = nullptr;
};

class cNPCDialog
{
    public:
        void     initialize(void);
        void     terminate(void);
        void     load(const std::string &_fileName);
        void     process(const float &_dt);

    protected:

    private:
        std::uint32_t numDialogTree = 0;
        sDialogTree*  dialogTree    = nullptr;

        void          m_freeData(void);
};

#endif //NPC_DIALOG_HPP
