 /**
 ** Created by: Inohime @ 11/6/2021
**/

#pragma once

// implement logging
#include <stdio.h>

namespace System {
  namespace Utility {
#ifdef _DEBUG
  #define LOG(fmt, ...)                  \
    do {                                 \
      fprintf(stderr, fmt, __VA_ARGS__); \
    }
#endif
  } // namespace Utility
} // namespace System