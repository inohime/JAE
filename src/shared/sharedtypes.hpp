 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <SDL.h>
#include <chrono>

#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wmissing-declarations"
#pragma clang diagnostic ignored "-Wuninitialized"

namespace System {
  using namespace std::chrono; // to be removed
  using ITexture = SDL_Texture;
  using ISurface = SDL_Surface;
  using IColor = SDL_Color;
  using IRect = SDL_Rect;
  using IVertex = SDL_Vertex;
  using IWindow = SDL_Window;
  using IRenderer = SDL_Renderer;
  using IRendererFlip = SDL_RendererFlip;
  using IPoint = SDL_Point;
  using IEvent = SDL_Event;
  using IKey = SDL_KeyCode;
  using IController = SDL_GameController;
  using IJoystick = SDL_Joystick;
  using IJoystickID = SDL_JoystickID;
} // namespace System