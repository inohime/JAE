CRE = src/core/
SRC = example/*.cpp $(CRE)video/*.cpp $(CRE)graphics/*.cpp $(CRE)input/*.cpp $(CRE)events/*.cpp $(CRE)audio/*.cpp
BIN = build/JAE.exe
# includes
INC = -Ideps/SDL2/include/ -Ideps/SDL2img/include/ -Ideps/SDL2mix/include/ -Ideps/SDL2ttf/include/
LIB = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lShell32 -Xlinker /subsystem:windows

# If you are using Linux or MacOS, replace "$(INC) $(LIB)"
# with `sdl2-config --cflags --libs` // not tested @ 12:17 am

$(BIN) : $(SRC)
	clang++ -std=c++17 $(SRC) $(INC) $(LIB) -o $(BIN)
	
clean:
	rm -f $(BIN)