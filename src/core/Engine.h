#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include "../render/Texto.h"

enum class Estado {
    SPLASH,
    MENU,
    JOGO,
};

class Engine {
public:
    Engine(const std::string& titulo, int largura, int altura);
    ~Engine();

    void rodar();
    void setTextos(const std::vector<std::string>& t) { textos = t; }

private:
    void processar_eventos();
    void renderizar();
    void atualizar();

    SDL_Window*   janela      = nullptr;
    SDL_Renderer* renderer    = nullptr;
    Texto*        texto       = nullptr;
    bool          rodando     = false;
    Estado        estado      = Estado::SPLASH;
    std::vector<std::string> splash_frames = {
        "Wari'", "War'", "Wa'", "W'"
    };
    int splash_index = 0;
    Uint32 splash_timer = 0;
    Uint32 splash_delay = 300;

    std::vector<std::string> textos;
    int texto_index = 0;
};