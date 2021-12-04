#include "timer.hpp"

namespace System {
  namespace Utility {
    Timer::Timer() : _baseTicks(), _stopTicks(steady_clock::now()), _deltaTime(0.0f), _timeState(1) {
      SDL_Delay(1); // terrible hack
      Start();
      Update();
    }

    void Timer::Start() {
      _timeState = 1;
      _baseTicks = steady_clock::now();
    }

    void Timer::Update() {
      if (_timeState == 0) {
        _deltaTime = duration<double>(0.0f);
      } else {
        _deltaTime = duration<double, std::milli>(_baseTicks - _stopTicks); // steady_clock::now() - _baseTicks;
      }
    }

    void Timer::Stop() {
      _timeState = 0;
      _deltaTime = duration<double>(0.0f);
      //_stopTicks = steady_clock::now() - _baseTicks;
    }

    void Timer::Reset() {
      _deltaTime = duration<double>(0.0f);
      _timeState = 1;
      // get the current ticks and subtract them to get the newest time (resetting)
     // _baseTicks = steady_clock::now() - _stopTicks;
    }
    double Timer::DeltaTime() {
      //std::cout << "DT: " << _deltaTime.count() << " ms\n";
      return _deltaTime.count();
    }
  } // namespace Utility
} // namespace System