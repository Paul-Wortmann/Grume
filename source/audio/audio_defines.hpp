


#ifndef AUDIO_DEFINES_HPP
#define AUDIO_DEFINES_HPP

#include "../includes.hpp"

struct sListener
{
    glm::vec3 position       = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 velocity       = glm::vec3(0.0f, 0.0f, 0.0f);
    float     orientation[6] = {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    float     gain           = 1.0f;
};

struct sAudioData
{
    uint16_t audioFormat     = 0;
    uint16_t channels        = 2;
    uint32_t sampleRate      = 48000;
    uint16_t bitsPerSample   = 16;
    char*    buffer          = nullptr;
    uint64_t bufferSize      = 0;
};

struct sAudioBuffer
{
    sAudioBuffer* next       = nullptr;
    uint32_t      ID         = 0;
    std::string   name       = "";
};

struct sAudioSource
{
    sAudioSource* next       = nullptr;
    uint32_t      ID         = 0;
    int32_t       state      = 0;
    float         pitch      = 1;
    float         gain       = 1;
    bool          loopint    = false;
    glm::vec3     position   = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3     velocity   = glm::vec3(0.0f, 0.0f, 0.0f);
};

#endif //AUDIO_DEFINES_HPP


