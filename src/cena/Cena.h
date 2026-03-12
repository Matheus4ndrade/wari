#pragma once
#include <string>
#include <vector>

struct Escolha{
    std::string label;
    std::string destino;
};

struct Cena{
    std::string id;
    std::vector<std::string> textos;
    std::vector<Escolha> escolhas;
    std::string musica;
    std::string sfx;
};

Cena carregarCena(const std::string& caminho);