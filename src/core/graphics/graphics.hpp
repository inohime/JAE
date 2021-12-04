 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <tuple>
#include "../video/video.hpp"
#include "../../shared/sharedtypes.hpp"
#include "../../utils/math/vector2.hpp"

namespace System {
 class Graphics {
  public:
    // graphics objects to be painted
    // use a template on here
    struct Object {
      // change std::get<(num)>(obj.type) to obj.type(T args)
      std::tuple<IRenderer *, ITexture *, IRect> type;
    };
    // Clear the Renderer
    void Clear() const noexcept;
    // Present the Renderer
    void Present() const noexcept;
    // Set Renderer's Draw Colour
    void SetColor(const IColor &col) const noexcept;

    void SetViewportSize(int w, int h) const noexcept;

    static void DrawTexture(ITexture *tex, int x, int y, IRect *clip = nullptr);

    // change this later so texture flipping is easy
    static void DrawTexture(ITexture *tex, const vec2i &val, IRect *clip = nullptr, double angle = 0.0, IPoint *center = nullptr, IRendererFlip flip = SDL_FLIP_NONE);

    static ITexture *LoadTexture(const std::string_view &filePath);

    static ITexture *LoadText(const std::string_view &msg, const std::string_view &fontFile, const IColor &col,
                                int fontSize);
    // Filled Circle
    int DrawCircleF(IRenderer *ren, const vec2i &val, int radius, const IColor &col) noexcept;
    // set an object (renderer, texture, rectangle) to a color or hue
    float SetRGBA(const Object &obj, IColor &col) noexcept;
    float SetHSL(const Object &obj, IColor &col) noexcept;
    float SetHSV(const Object &obj, IColor &val) noexcept;
  };
} // namespace System