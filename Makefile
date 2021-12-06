CORE = src/core/
SRC = example/*.cpp $(CORE)video/*.cpp $(CORE)graphics/*.cpp $(CORE)input/*.cpp $(CORE)events/*.cpp $(CORE)audio/*.cpp
BIN = build/JAE.exe
# includes
INC = -Ideps/SDL2/include/ -Ideps/SDL2img/include/ -Ideps/SDL2mix/include/ -Ideps/SDL2ttf/include/
LIB_SRC = -Ldeps/Libs/
LIB = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lShell32 -Xlinker /subsystem:windows

# If you are using Linux or MacOS, replace "$(INC) $(LIB)"
# with `sdl2-config --cflags --libs` // not tested
# remove -Xlinker /subsystem:windows and the extension ".exe"


$(BIN) : $(SRC)
	clang++ -std=c++17 $(SRC) $(INC) $(LIB_SRC) $(LIB) -o $(BIN)
	
clean:
	rm -f $(BIN)