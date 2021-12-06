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

    // Set the size of the viewport
    void SetViewportSize(int w, int h) const noexcept;

    // Draw a texture at x/y coordinates
    static void DrawTexture(ITexture *tex, int x, int y, IRect *clip = nullptr);

    // Draw a texture at x/y coordinates
    static void DrawTexture(ITexture *tex, const vec2i &val, IRect *clip = nullptr, double angle = 0.0,
                            IPoint *center = nullptr, IRendererFlip flip = SDL_FLIP_NONE);

    static ITexture *LoadTexture(const std::string_view &filePath);

    static ITexture *LoadText(const std::string_view &msg, const std::string_view &fontFile, const IColor &col,
                              int fontSize);

    // Filled Circle
    int DrawCircleF(IRenderer *ren, const vec2i &val, int radius, const IColor &col) noexcept;

    // Modulate an object's color (renderer, texture, rectangle) with RGBA
    [[nodiscard]] float SetRGBA(const Object &obj, IColor &col) noexcept;

    // Modulate an object's color (renderer, texture, rectangle) with HSL (Hue, Saturation, Lightness)
    [[nodiscard]] float SetHSL(const Object &obj, IColor &col) noexcept;

    // Modulate an object's color (renderer, texture, rectangle) with HSV (Huse, Saturation, Value)
    [[nodiscard]] float SetHSV(const Object &obj, IColor &val) noexcept;
  };
} // namespace System