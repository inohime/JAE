 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

#include "../../shared/sharedtypes.hpp"

namespace System {
  class Event {
  public:
    void HandleEvents();
    // user must request PollEvent or WaitEvent from application start
    int SetPollEvent(IEvent *ev);
    int SetWaitEvent(IEvent *ev);

    /**
    ** send whatever event the user wants
    ** should easily integrate into the HandleEvents
    **/
    template<typename T>
    inline void AddEvent(T *ev) {
    }

  private:
    IEvent _ev;
  };
} // namespace System