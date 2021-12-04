 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include <SDL.h>
#include <chrono>
#include <iostream>

using namespace std::chrono;

namespace System {
  namespace Utility {
    class Timer {
    public:
      Timer();
      // start the timer (runs in ctor)
      void Start();
      // update current deltaTime
      void Update();
      // stop all time
      void Stop();
      // reset the time
      void Reset();
      // gets the delta time
      double DeltaTime();

    private:
      steady_clock::time_point _baseTicks, _stopTicks;
      // duration<double> _stopTicks;
      duration<double, std::milli> _deltaTime;
      int _timeState;
    };
  } // namespace Utility
} // namespace System