
#ifndef RE_LIGHTS_HPP
#define RE_LIGHTS_HPP

#include "../core/re_common_headers.hpp"
#include "re_light_types.hpp"

namespace RoboEngine
{

    class c_lights
    {
        public:
            c_lights(void) = default;
            ~c_lights(void) = default;
            s_light *light = nullptr;
            void deleteLights(void) {delete [] light;}
        protected:
        private:
    };

}

#endif // RE_LIGHTS_HPP
