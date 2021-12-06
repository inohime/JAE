 /**
 ** Created by: Inohime @ 12/5/2021
**/

#pragma once

#include "../../src/shared/shared.hpp"

namespace Example {
  struct Shapes {
    Shapes() = default;

    // create shapes to draw (triangle, circle, polygon, square)
    static void CreateShape(System::IRenderer *ren, System::ITexture *tex, const System::IVertex *vert, int num_vert,
                            const int *indices, int num_indicies) noexcept;

    static void CreateTriangle(System::IRenderer *ren, System::ITexture *tex, const System::IVertex *vert);

    static void CreateCircleF(System::IRenderer *ren, const System::IVertex *vert, int radius,
                              const System::IColor &col);

    static void CreatePolygon(System::IRenderer *ren, System::ITexture *tex, const System::IVertex *vert);

    static void CreateSquare(System::IRenderer *ren, System::ITexture *tex);

    void Draw();

  private:
    System::IVertex *_vert;
  };
} // namespace Example