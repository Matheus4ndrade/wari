#pragma once 
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Texto {
    public:
    Texto(SDL_Renderer* renderer, const std::string& caminho_fonte, int tamanho);
    ~Texto();
    void desenhar(const std::string& texto, int x, int y, SDL_Color cor = {255, 255, 255});

    private:
    SDL_Renderer* renderer;
    TTF_Font* fonte;  
};