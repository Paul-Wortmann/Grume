/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libRMG"
 *
 * "libRMG" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libRMG" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libRMG" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#ifndef LIBRMG_MAP_HPP
#define LIBRMG_MAP_HPP

#include "libRMG_defines.hpp"
#include "libRMG_includes.hpp"
#include "libRMG_generator_C1.hpp"
#include "libRMG_generator_C2.hpp"
#include "libRMG_generator_D1.hpp"
#include "libRMG_generator_D2.hpp"
#include "libRMG_generator_M1.hpp"
#include "libRMG_generator_T1.hpp"
#include "libRMG_utils.hpp"

class cLibRMGMap
{
    public:
        sLibRMGMapData data = {};
        
        cLibRMGMap(void) = default;
        ~cLibRMGMap(void) = default;
        void init(void);
        void free(void);
        void generate(void);

        void draw(void);
        
    protected:
    private:
};

#endif // LIBRMG_MAP_HPP

