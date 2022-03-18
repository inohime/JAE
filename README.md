
# Just Another Engine

[![Codacy](https://app.codacy.com/project/badge/Grade/67346cc33a5e479495c5f9d87cd29cde)](https://www.codacy.com/gh/inohime/JAE/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=inohime/JAE&amp;utm_campaign=Badge_Grade)

![Example Image](example/assets/JAE_Test_Image.png)

## Currently In Active Development
  - Non-production beta builds released infrequently

## How-to-Build
  This project utilizes Makefile (change to CMake later)
  To build a fresh project, please follow the following:
  1. `mkdir build && cd build`
  2. `cd .. && make`
  3. Put all /x64/ dlls into the build folder (excluding optional)
  
  **required**: all dependencies not labled optional put into deps.
  

`Dependencies:`
  - SDL2 2.0.16+ (soon 2.0.20)
  - SDL_Mixer 2.0.4
  - SDL_TTF 2.0.15
  - SDL_Image 2.0.5

`Features to be added:`
  - [ ] Entity Component System
  - [ ] Scripting ([WREN](https://www.wren.io))
  - [ ] Verbose Logging
  - [ ] Multiple gamepad support
  - [ ] ImGui
  - [ ] Emscripten
  - [ ] Tiled Maps
  - [ ] C89 support
  - [ ] A smile on your face

`Examples to be added:`
  - [ ] Window Creation
  - [ ] Entity (loading, animations, interaction)
  - [ ] Shapes (triangles, rectangles, circles, polygons)
  - [ ] GUI 
  - [ ] Input 
  - [ ] Audio (loading, playing, altering (audio data & volume) 
  - [ ] Tiled Maps
