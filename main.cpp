#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow(
        "Wari'",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 32);
    if (!font) {
        std::cout << "Erro fonte: " << TTF_GetError() << std::endl;
        return 1;
    }

    SDL_Color branco = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, "Wari' Engine", branco);
    SDL_Texture* textoTextura = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int textoW, textoH;
    SDL_QueryTexture(textoTextura, nullptr, nullptr, &textoW, &textoH);
    SDL_Rect textoRect = {640 - textoW/2, 360 - textoH/2, textoW, textoH};

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 15, 10, 20, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, textoTextura, nullptr, &textoRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(textoTextura);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}