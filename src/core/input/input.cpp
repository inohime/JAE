#include <cassert>
#include <iostream>
#include "input.hpp"	

namespace System {

  void Input::OpenInput() {
    _controller = SDL_JoystickOpen(0);

    // assertions
    assert(SDL_NumJoysticks() > 0);
    assert(_controller != nullptr);

    std::cout << "Opened Controller \n";
  }

  void Input::CloseInput() const {
    SDL_JoystickClose(_controller);
    if (!_controller) {
      std::cout << "Closed controller \n";
    }
  }

  void Input::ReopenInput() {
    // close all input attached
    CloseInput();
    // open all input devices
    OpenInput();
  }

  bool Input::KeyDown(uint8_t key) noexcept {
    return ((key & 1) ? 1 : 0);
  }

  bool Input::KeyReleased(uint8_t key) noexcept {
    return ((key & 1) ? 1 : 0);
  }

  void Input::SetKeyState(uint8_t key) noexcept {
      // set the state of the key
      // keydown, keyreleased, key binded, key not active
  }

  void Input::SetKeyBind(uint8_t currKey, uint8_t newKey) {
      // set a keybind
      // the current key "acts" like the newkey
      // (a,b) -> a is now b
  }
} // namespace System