#include "../src/shared/shared.hpp"

using namespace System;

// Window width & height
constexpr int W = 1024;
constexpr int H = 768;

int main(int argc, char *argv[]) 
{
    Graphics *g = nullptr;
    Audio *a = nullptr;

    // Init video
    Video v("JAE Example", W, H, resizable);

    // Initialize libs
    if (IMG_Init(IMG_INIT_PNG) != -1) {
        std::cout << "Failed to initialize SDL_Image " << IMG_GetError() << "\n";
    }

    if (TTF_Init() != 0) {
        std::cout << "Failed to intialize SDL_TTF " << TTF_GetError() << "\n";
    }

    // Set the application icon
    ISurface* icon = IMG_Load("assets/icon.png");
	SDL_SetWindowIcon(Video::VW().get(), icon);
	SDL_FreeSurface(icon);

    // Open the audio component & load a chunk
    a->OpenAudio();
    IMChunk *chunk = Audio::LoadAudio<IMChunk>("assets/8bit-kick.wav");

    // Load things to be rendered (text, textures)
    std::string msgStr = "assets/fonts/Silver.ttf";
    std::vector<IRect> mayClip;
    mayClip.push_back({21, 161, 28, 40});
    mayClip.push_back({129, 232, 28, 40});
    //mayClip.push_back({91, 57, 28, 40});
    ITexture *bg = Graphics::LoadTexture("assets/CloudsFront.png");
    ITexture *msgTex = Graphics::LoadText("Hello JAE!", msgStr, {0xFF, 0xFF, 0xFF, 0xFF}, 58);
    ITexture *may = Graphics::LoadTexture("assets/PK_MAY.png");
    // 21, 161, 28, 40 // may1
    // 91, 57, 28, 40 // may3
    // Change the viewport scale
    g->SetViewportSize(512, 385);
    
    // Event loop
    bool quit = false;
    while (!quit) {
        // Use a timer here
        IEvent e;
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                quit = true;
                break;

                case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_5:
                    Audio::PlayAudio<IMChunk>(chunk);
                    break;
                }
            }
        }
        // Set the colour of the renderer
        g->SetColor({0x4F, 0x4F, 0x4F, 0xFF});
        // Clear the screen
        g->Clear();

        // Draw text and textures
        Graphics::DrawTexture(bg, 0, 100);
        Graphics::DrawTexture(may, 190, 140, &mayClip[0]);
        Graphics::DrawTexture(may, 230, 140, &mayClip[1]);
        Graphics::DrawTexture(may, {270, 140}, &mayClip[0], NULL, NULL, SDL_FLIP_HORIZONTAL);
        Graphics::DrawTexture(msgTex, static_cast<int>(512 / 3), 60);

        // Present the renderer
        g->Present();
    }
    // Free all resources 
    SDL_DestroyTexture(bg);
    SDL_DestroyTexture(may);
    SDL_DestroyTexture(msgTex);
    Mix_FreeChunk(chunk);
    a->CloseAudio();
    SDL_Quit();
    return 0;
}