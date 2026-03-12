#include "src/core/Engine.h"
#include "src/cena/Cena.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Cena cena = carregarCena("teste.json");
    Engine engine("Wari'", 1280, 720);
    
    if (!cena.textos.empty()) {
        engine.setTextoAtual(cena.textos[0]);
    }
    
    engine.rodar();
    return 0;
}