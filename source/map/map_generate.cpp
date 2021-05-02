
#include "map_manager.hpp"

void cMapManager::generateMap(sMap*& _map)
{
    // Seed
    (_map->genData.seed == 0) ? srand(time(nullptr)) : srand(_map->genData.seed);

    // Generate based on algorithm
    switch (_map->genData.algorithm)
    {
        case 1: // Cave 1
            m_generateMap_C1(_map);
        break;
        default:
        break;
    }
}

