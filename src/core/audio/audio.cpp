#include "audio.hpp"
#include "../video/video.hpp"

namespace System {
  void Audio::OpenAudio() {
    int result = 0;
    // add more flags if needed
    int flags = MIX_INIT_MP3;
    Mix_Init(flags);
#ifdef _DEBUG
    if (flags != (result = Mix_Init(flags))) {
      printf("Could not initialize mixer (result: %d).\n", result);
      printf("Mix_Init: %s\n", Mix_GetError());
      CloseAudio();
    }
#endif
#ifdef NDEBUG
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Audio Load Exception", "WASAPI: No audio device was selected.", Video::VW().get());
    CloseAudio();
#endif

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
  }

  void Audio::CloseAudio() const {
    Mix_CloseAudio();
    Mix_Quit();
  }

  void Audio::ReopenAudio() {
    CloseAudio();
    OpenAudio();
  }

  int Audio::SetVolume(int volume) noexcept {
    // do work here
    return 0;
  }
} // namespace System