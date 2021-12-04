#include "graphics.hpp"

namespace System {
  void Graphics::Clear() const noexcept {
    SDL_RenderClear(Video::VR().get());
  }

  void Graphics::SetColor(const IColor &col) const noexcept {
    SDL_SetRenderDrawColor(Video::VR().get(), col.r, col.g, col.b, col.a);
  }

  void Graphics::Present() const noexcept {
    SDL_RenderPresent(Video::VR().get());
  }

  void Graphics::SetViewportSize(int w, int h) const noexcept {
    SDL_RenderSetLogicalSize(Video::VR().get(), w, h);
  }

  int Graphics::DrawCircleF(IRenderer *ren, const vec2i &val, int radius, const IColor &col) noexcept {
      // 125 microseconds @ 10 draw calls
      // replace with SDL_RenderGeometry
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx) {
      SDL_SetRenderDrawColor(ren, 0xFF, 0x0, 0x2F, 0xFF);
      status += SDL_RenderDrawLine(ren, val.x - offsety, val.y + offsetx, val.x + offsety, val.y + offsetx);
      status += SDL_RenderDrawLine(ren, val.x - offsetx, val.y + offsety, val.x + offsetx, val.y + offsety);
      status += SDL_RenderDrawLine(ren, val.x - offsetx, val.y - offsety, val.x + offsetx, val.y - offsety);
      status += SDL_RenderDrawLine(ren, val.x - offsety, val.y - offsetx, val.x + offsety, val.y - offsetx);

      if (status < 0) {
        status = -1;
        break;
      }

      if (d >= 2 * offsetx) {
        d -= 2 * offsetx + 1;
        offsetx += 1;
      } else if (d < 2 * (radius - offsety)) {
        d += 2 * offsety - 1;
        offsety -= 1;
      } else {
        d += 2 * (offsety - offsetx - 1);
        offsety -= 1;
        offsetx += 1;
      }
    }

    return status;
  }

  // wrap these in smart pointers
  ITexture *Graphics::LoadTexture(const std::string_view &filePath) {
    ITexture *tex {};
    ISurface *surf = IMG_Load(filePath.data());

    if (!filePath.data()) {
      std::cout << "failed to load path\n";
    }

    SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 0xFF, 0xFF, 0xFF));

    tex = SDL_CreateTextureFromSurface(Video::VR().get(), surf);

    SDL_FreeSurface(surf);

    return tex;
  }

  void Graphics::DrawTexture(ITexture *tex, int x, int y, IRect *clip) {
    IRect dst {};
    dst.x = x;
    dst.y = y;
    if (clip != nullptr) {
      dst.w = clip->w;
      dst.h = clip->h;
    } else {
      SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
    }

    SDL_RenderCopy(Video::VR().get(), tex, clip, &dst);
  }

  void Graphics::DrawTexture(ITexture *tex, const vec2i &val, IRect *clip, double angle,
                            IPoint *center, IRendererFlip flip) {
    IRect dst {};
    dst.x = val.x;
    dst.y = val.y;
    if (clip != nullptr) {
      dst.w = clip->w;
      dst.h = clip->h;
    } else {
      SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
    }

    SDL_RenderCopyEx(Video::VR().get(), tex, clip, &dst, angle, center, flip);
  }

  ITexture *Graphics::LoadText(const std::string_view &msg, const std::string_view &fontFile,
                                 const IColor &col, int fontSize) {
    TTF_Font *font = TTF_OpenFont(fontFile.data(), fontSize);
    if (font == nullptr) {
      std::cout << "TTF_OpenFont error " << TTF_GetError() << "\n";
      return nullptr;
    }

    // TTF requires a surface, create one and then create a texture to pass it to
    ISurface *surf = TTF_RenderText_Blended(font, msg.data(), col);
    if (surf == nullptr) {
      TTF_CloseFont(font);
      std::cout << "TTF_RenderText error " << TTF_GetError() << "\n";
      return nullptr;
    }
    ITexture *texture = SDL_CreateTextureFromSurface(Video::VR().get(), surf);
    if (texture == nullptr) {
      std::cout << "Text texture failed to be created\n";
    }

    // Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
  }

  float Graphics::SetRGBA(const Object &obj, IColor &col) noexcept {
   // std::get<1>(obj.type);
    // change std::get<(num)>(obj.type) to obj.type(T args)
      return 0;
  }

  float Graphics::SetHSL(const Object &obj, IColor &col) noexcept {
    return 0;
  }

  float Graphics::SetHSV(const Object &obj, IColor &col) noexcept {
    return 0;
  }
} // namespace System