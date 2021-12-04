 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <memory>
#include <string_view>
#include "../../shared/sharedtypes.hpp"
#include "../../utils/mem.h"

namespace System {
  enum {
    fullscreen = SDL_WINDOW_FULLSCREEN,
    fullDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
    borderless = SDL_WINDOW_BORDERLESS,
    resizable = SDL_WINDOW_RESIZABLE,
    alwaysOnTop = SDL_WINDOW_ALWAYS_ON_TOP,
    allowHiDPI = SDL_WINDOW_ALLOW_HIGHDPI,
  }VideoFlags;

  class Video {
  public:
    Video() = default;
    Video(const std::string_view &title, uint32_t width, uint32_t height, uint32_t flags);

    // view window (this gets the window)
    static std::shared_ptr<IWindow> VW() noexcept;
    // view renderer (this gets the renderer)
    static std::shared_ptr<IRenderer> VR() noexcept;

  private:
    //std::unique_ptr<IWindow, Utility::DM> _window;
    static std::shared_ptr<IWindow> _window;
    static std::shared_ptr<IRenderer> _renderer;
  };
} // namespace System