


#ifndef DEFINES_HPP
#define DEFINES_HPP

// Platform defines
#ifdef __linux__
#define PLATFORM_LINUX
#endif
#ifdef __ANDROID__
#define PLATFORM_ANDROID
#endif
#ifdef _WIN32
#define PLATFORM_WINDOWS
#endif
#ifdef _WIN64
#define PLATFORM_WINDOWS
#endif
#ifdef __APPLE__
#error "Platform not supported, upgrade to Linux!"
#endif

// Default files
#define DEFAULT_TEXTURE_D "default_d.png"
#define DEFAULT_TEXTURE_E "default_e.png"
#define DEFAULT_TEXTURE_N "default_n.png"
#define DEFAULT_TEXTURE_S "default_s.png"

#endif //DEFINES_HPP
