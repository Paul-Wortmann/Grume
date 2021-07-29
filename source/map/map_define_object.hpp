/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef MAP_DEFINE_OBJECT_HPP
#define MAP_DEFINE_OBJECT_HPP

enum class eMapObjectType : std::uint16_t 
{ 
    objectTypeNone               =   0, // None / empty
    objectTypeAltar              =   1, // Altar
    objectTypeArrow              =   2, // Arrow
    objectTypeBarrel             =   3, // Barrel
    objectTypeBasket             =   4, // Basket
    objectTypeBones              =   5, // Bones
    objectTypeBook               =   6, // Book
    objectTypeBridge             =   7, // Bridge
    objectTypeCastle             =   8, // Castle
    objectTypeCemetary_object    =   9, // Cemetary Object
    objectTypeChest              =   0, // Chest
    objectTypeCrate              =  11, // Crate
    objectTypeCrystal            =  12, // Crystal
    objectTypeDead_tree          =  13, // Dead Tree
    objectTypeDoor               =  14, // Door
    objectTypeFence_metal        =  15, // Fence Metal
    objectTypeFence_pole_metal   =  16, // Fence Metal Pole
    objectTypeGib                =  17, // Gib
    objectTypeGrass_patch        =  18, // Grass Patch
    objectTypeMausoleum          =  19, // Mausoleum
    objectTypeMedieval_building  =  20, // Medieval Building
    objectTypeMedieval_prop      =  21, // Medieval Prop
    objectTypeMushroom           =  22, // Mushroom
    objectTypeOld_wagon          =  23, // Old Wagon
    objectTypeRiver              =  24, // River
    objectTypeRock               =  25, // Rock
    objectTypeRock_small         =  26, // Rock Small
    objectTypeSack               =  27, // Sack
    objectTypeSkull              =  28, // Skull
    objectTypeStatue             =  29, // Statue
    objectTypeSwitch             =  30, // Switch
    objectTypeTorch              =  31, // Torch
    objectTypeTorture_device     =  32, // Torture Device
    objectTypeTower              =  33, // Tower
    objectTypeTown_prop          =  34, // Town Prop
    objectTypeTrap               =  35, // Trap
    objectTypeVase               =  36, // Vase
    objectTypeWeapon             =  37, // Weapon

    objectTypeTest               =  38, // Test
};

#endif // MAP_DEFINE_OBJECT_HPP