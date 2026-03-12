#include "Cena.h"
#include "../json.hpp"
#include<fstream>
#include<iostream>

using json = nlohmann::json;

Cena carregarCena(const std::string& caminho) {
    Cena cena;

    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: nao foi possivel abrir: " << caminho << std::endl;
        return cena;
    }
    json j = json::parse(arquivo);

    cena.id = j.value("id", "");

    if (j.contains("text")) {
        for (auto& linha : j["text"]) {
            cena.textos.push_back(linha.get<std::string>());
        }
    }

    if (j.contains("choices")) {
        for (auto& escolha : j["choices"]) {
            Escolha e;
            e.label = escolha.value("label", "");
            e.destino = escolha.value("destino", "");
            cena.escolhas.push_back(e);
        }
    }
    if (j.contains("audio")) {
        cena.musica = j["audio"].value("music", "");
        cena.sfx = j["audio"].value("sfx", "");
    }
    return cena;
}