#include <cassert>
#include <fstream>
#include "video.hpp"

namespace System {
  std::shared_ptr<IWindow> Video::_window = nullptr;
  std::shared_ptr<IRenderer> Video::_renderer = nullptr;

  System::Video::Video(const std::string_view &title, uint32_t width, uint32_t height, uint32_t flags) {
    assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);

    _window = std::shared_ptr<IWindow>(
        SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags),
        SDL_DestroyWindow);

    if (!_window) {
      _window = nullptr;
      std::ofstream errorLog;
      errorLog.open("ErrorLog.txt");
      errorLog << "Failed to create window.\n"; // add verbose logging info later
      errorLog.close();
      SDL_DestroyWindow(_window.get());
      SDL_Quit();
    }

    _renderer = std::shared_ptr<IRenderer>(SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED),
                                           SDL_DestroyRenderer);

    if (!_renderer) {
      // if (Graphics::RecreateRenderer() != 0)
#ifdef _DEBUG
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create renderer");
#endif
#ifdef NDEBUG
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Video Exception", "Failed to load renderer", _window.get());
      _renderer = nullptr;
      _window = nullptr;
#endif
    }
  }

  std::shared_ptr<IWindow> Video::VW() noexcept {
    return _window;
  }

  std::shared_ptr<IRenderer> Video::VR() noexcept {
    return _renderer;
  }
} // namespace System
