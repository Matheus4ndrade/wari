#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../render/Texto.h"

class Engine {
public:
    Engine(const std::string& titulo, int largura, int altura);
    ~Engine();

    void rodar();
    void setTextoAtual(const std::string& t) { texto_atual = t; }

private:
    void processar_eventos();
    void renderizar();

    SDL_Window*   janela      = nullptr;
    SDL_Renderer* renderer    = nullptr;
    Texto*        texto       = nullptr;
    std::string   texto_atual = "";
    bool          rodando     = false;
};