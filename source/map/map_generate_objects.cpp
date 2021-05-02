
#include "map_manager.hpp"

void cMapManager::m_generateMap_objects(sMap*& _map)
{
    for (uint32 h = 1; h < _map->height-1; ++h)
    {
        for (uint32 w = 1; w < _map->width-1; ++w)
        {
            uint32 t = (h * _map->width) + w;
            if ((_map->tile[t].object == 0) && (_map->tile[t].base == eTileBase::tileFloor))
            {
                // WARNING!!!! This should be based on the biome objects
                /*
                if ((rand() % 200) == 0)
                {
                    _map->tile[t].object = 0;
                }
                else if ((rand() % 1000) == 0)
                {
                    _map->tile[t].object = 0;
                }
                */
            }
        }
    }

}
