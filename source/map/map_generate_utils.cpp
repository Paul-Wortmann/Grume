
#include "map_manager.hpp"

void cMapManager::m_generatePerimeterWall(sMap*& _map)
{
    for (uint32 i = 0; i < _map->numTiles; ++i)
    {
        if ((i < _map->width) ||
            (i > (_map->numTiles - _map->width - 1)) ||
            ((i % _map->width) == 0) ||
            ((i % _map->width) == (_map->width - 1)))
        {
            _map->tile[i].base = eTileBase::tileWall;
        }
    }
}
