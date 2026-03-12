#include "Engine.h"
#include <iostream>

Engine::Engine(const std::string& titulo, int largura, int altura) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    janela = SDL_CreateWindow(
        titulo.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        largura, altura,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    texto = new Texto(renderer, "C:/Windows/Fonts/arial.ttf", 32);
    rodando = true;
}

Engine::~Engine() {
    delete texto;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(janela);
    TTF_Quit();
    SDL_Quit();
}

void Engine::rodar() {
    while (rodando) {
        processar_eventos();
        renderizar();
    }
}

void Engine::processar_eventos() {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        if (evento.type == SDL_QUIT) rodando = false;
        if (evento.type == SDL_KEYDOWN && evento.key.keysym.sym == SDLK_ESCAPE) rodando = false;
    }
}

void Engine::renderizar() {
    SDL_SetRenderDrawColor(renderer, 15, 10, 20, 255);
    SDL_RenderClear(renderer);
    texto->desenhar(texto_atual, 100, 100);
    SDL_RenderPresent(renderer);
}