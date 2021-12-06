 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

namespace System {
  using IMMusic = Mix_Music;
  using IMChunk = Mix_Chunk;

  // switch to cute sound

  class Audio {
  public:
    void OpenAudio();

    void CloseAudio() const;

    // To restart the audio device
    void ReopenAudio();

    int SetVolume(int volume) noexcept;

    // change to T GetAudioData()
    static void GetMusicData() noexcept;
    static void GetChunkData() noexcept; 
    
    /**
    ** example:
    ** Mix_Music *sound = LoadAudio("music.wav");
    ** PlayMusic(sound);
   **/

    template<typename T>
    inline static T *LoadAudio(const std::string_view &fileName) {
      T *sound = nullptr;
      if constexpr (std::is_same_v<T, IMMusic>) {
        sound = Mix_LoadMUS(fileName.data());
        if (!fileName.data()) {
          std::cout << "Failed to load path\n";
        } else {
          std::cout << "Loaded path, preparing music..\n";
        }
      } else if constexpr (std::is_same_v<T, IMChunk>) {
        sound = Mix_LoadWAV(fileName.data());
        if (!fileName.data()) {
          std::cout << "Failed to load path\n";
        } else {
          std::cout << "Loaded path, preparing chunk samples..\n";
        }
      }
      return sound;
    }

    template<typename T>
    inline static void PlayAudio(T *sound) noexcept {
      if constexpr (std::is_same_v<T, IMMusic>) {
        Mix_PlayMusic(sound, 0);
        if (sound == nullptr) {
          std::cout << "Failed to play audio \n";
        }
      } else if constexpr (std::is_same_v<T, IMChunk>) {
        Mix_PlayChannel(-1, sound, NULL);
        if (sound == nullptr) {
          std::cout << "Failed to play audio \n";
        }
      }
    }

    template<typename T>
    inline void CloneAudio(T *sound) noexcept {
    }

  private:
    // IMMusic *_wave;
    // IMChunk *_chunk;
  };
} // namespace System