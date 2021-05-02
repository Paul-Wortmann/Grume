


#ifndef ENTITY_TEXTURE_HPP
#define ENTITY_TEXTURE_HPP

#include "../includes.hpp"

struct sEntityTexture
{
    sEntityTexture* next     = nullptr;
    std::string     fileName = {};
    uint32          ID       = 0;
};

#endif // ENTITY_TEXTURE_HPP