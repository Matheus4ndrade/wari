#include "Texto.h"

Texto::Texto(SDL_Renderer* renderer, const std::string& caminho_fonte, int tamanho) 
: renderer(renderer) {
    fonte = TTF_OpenFont(caminho_fonte.c_str(), tamanho);
}

Texto::~Texto() {
        TTF_CloseFont(fonte);
}   

void Texto ::desenhar(const std::string& texto, int x, int y, SDL_Color cor) {
    SDL_Surface* surface = TTF_RenderUTF8_Blended(fonte, texto.c_str(), cor);
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    int w, h;
    SDL_QueryTexture(textura, nullptr, nullptr, &w, &h);
    SDL_Rect rect = {x, y, w, h};

    SDL_RenderCopy(renderer, textura, nullptr, &rect);
    SDL_DestroyTexture(textura);
}