


#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity.hpp"

class cGraphicsEngine
{
    private:
        sEntity *m_entityFirst = nullptr;
        
    protected:
        
    public:
        cGraphicsEngine(void);
        ~cGraphicsEngine(void);
        
        void initialize(void);
        void terminate(void);
        void process(void);
        
        void setEntityHandle(sEntity *_entity);

};

#endif // GRAPHICS_ENGINE_HPP
