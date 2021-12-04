 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <vector>
#include "../../../utils/timer.hpp"
#include "../../../shared/sharedtypes.hpp"

namespace System {
  class Animation {
  public:
    Animation();
    ~Animation();
    void Update(double deltaTime) noexcept;

  private:
    Utility::Timer _animTimer;
    std::vector<IRect> _animClips;
    int32_t _currFrame;
  };
} // namespace System