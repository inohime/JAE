#include "event.hpp"

// ideally, we should make this thread safe; thread-safety will not focused on atm.

namespace System {
  void Event::HandleEvents() {
    /*
    bool quit = false;
    while (!quit) {
      while (SDL_PollEvent(&_ev) != 0) {
        switch (_ev.type) {}
        
      }
    }
    */
  }

  // FOR BELOW
  // vvvvvvvvv
  // do all of the setting up and easily integrate it into HandleEvents
  // add type safety

  int Event::SetPollEvent(IEvent *ev) {
    SDL_PollEvent(ev);
    // do work here
    return 0;
  }

  int Event::SetWaitEvent(IEvent *ev) {
    SDL_WaitEvent(ev);
    // do work here
    return 0;
  }
} // namespace System