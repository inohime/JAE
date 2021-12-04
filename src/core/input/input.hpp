 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <SDL.h>
#include <unordered_map>
#include <array>
#include "../../shared/sharedtypes.hpp"

// create key mappings
namespace System {
  // find a way to shorten this list

  enum Keys {
    KEY_LSHIFT,
    KEY_RSHIFT,
    KEY_LCTRL,
    KEY_RCTRL,
    KEY_RIGHT,
    KEY_DOWN,
    KEY_LEFT,
    KEY_UP,
    KEY_ESC,
    KEY_LGUI,
    KEY_MINUS,
    KEY_RGUI,
    KEY_PLUS,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
  };

  enum class KeyState : uint8_t {
    UP = 0x00,
    DOWN = 0x01
  };

  class Input {
  public:
    Input() = default;
    ///
    void OpenInput();
    void CloseInput() const;
    void ReopenInput();
    // keyboard
    bool KeyDown(uint8_t key) noexcept;
    bool KeyReleased(uint8_t key) noexcept;
    // useful for scenes where you don't want the player to move or application to receive input
    void SetKeyState(uint8_t key) noexcept;
    void SetKeyBind(uint8_t currKey, uint8_t newKey);
    // mouse
    bool MouseButtonDown(uint32_t button) noexcept;
    bool MouseButtonReleased(uint32_t button) noexcept;
    // gamepad
    void JoySetDeadZone(IJoystickID id, Sint16 sensitivity);
    void JoyGetDeadZone(IJoystickID id) noexcept;
    // input update
    void Update() const noexcept;

  private:
    std::array<KeyState, 512> _keyStates;
    std::unordered_map<Keys, IKey> _keyBind;
    IController *_controller;
  };
} // namespace System