/**
** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <SDL.h>

namespace System {
  namespace Utility {
    struct DM {
      void operator()(SDL_Window *x) const {
        SDL_DestroyWindow(x);
      }
      void operator()(SDL_Renderer *x) const {
        SDL_DestroyRenderer(x);
      }
      void operator()(SDL_Texture *x) const {
        SDL_DestroyTexture(x);
      }
      void operator()(SDL_Surface *x) const {
        SDL_FreeSurface(x);
      }
    };
  } // namespace Utility
} // namespace System