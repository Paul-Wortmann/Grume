


#ifndef MEMORY_MANAGER_HPP
#define MEMORY_MANAGER_HPP

#include "defines.hpp"
#include "includes.hpp"

class cMemoryManager
{
    private:
        
    protected:
        
    public:
        cMemoryManager(void) = default;
        ~cMemoryManager(void) = default;
        
        uint32_t* allocate(uint32_t _size);
        void free(uint32_t *_pointer, uint32_t _size);
};

#endif // MEMORY_MANAGER_HPP
