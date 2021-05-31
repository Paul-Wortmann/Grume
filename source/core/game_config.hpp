


#ifndef GAME_CONFIG_HPP
#define GAME_CONFIG_HPP

#define CONFIG_FILE "config.txt" // Default config file name.

#include "includes.hpp"
#include "../utils/xml_parser.hpp"

class cGameConfig
{
    public:
        void load(const std::string &_fileName = CONFIG_FILE);
        void save(const std::string &_fileName = CONFIG_FILE);

    protected:

    private:
    public:
        // These should all be set to low default values
        
        // Graphics
        std::uint32_t m_resolution_x = 1920;
        std::uint32_t m_resolution_y = 1080;
        bool          m_fullscreen   = true;
        
        // Audio
        std::uint32_t m_volume_master = 50;
        std::uint32_t m_volume_music  = 60;
        std::uint32_t m_volume_sfx    = 80;
};

#endif //GAME_CONFIG_HPP

