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
    texto = new Texto(renderer, "C:/Windows/Fonts/arial.ttf", 48);
    rodando = true;
    splash_timer = SDL_GetTicks();
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
        atualizar();
        renderizar();
        SDL_Delay(16);
    }
}

void Engine::processar_eventos() {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        if (evento.type == SDL_QUIT) rodando = false;
        if (evento.type == SDL_KEYDOWN) {
            if (evento.key.keysym.sym == SDLK_ESCAPE) rodando = false;
            if (evento.key.keysym.sym == SDLK_SPACE && estado == Estado::JOGO) {
                if (texto_index<(int)textos.size()-1) texto_index++; 
            }
        }
    }
}

void Engine::atualizar() {
    if (estado == Estado::SPLASH) {
        Uint32 agora = SDL_GetTicks();
        if (agora - splash_timer >= splash_delay) {
            splash_timer = agora;
            splash_index++;
            if (splash_index >= (int)splash_frames.size()) {
                estado = Estado::JOGO;
            }
        }
    }
}

void Engine::renderizar() {
    SDL_SetRenderDrawColor(renderer, 15, 10, 20, 255);
    SDL_RenderClear(renderer);

    if (estado == Estado::SPLASH){
        if (!textos.empty()){
            texto->desenhar(splash_frames[splash_index], 640 - 60, 360 - 24);
        }
    }else if (estado == Estado::JOGO){
        if (!textos.empty()){
            texto->desenhar(textos[texto_index], 100, 580);
        }
        Texto rodape(renderer, "C:/Windows/Fonts/arial.ttf", 16);
        rodape.desenhar("Pora Std.", 1180, 695);
    }
    SDL_RenderPresent(renderer);
}