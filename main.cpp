#include "src/core/Engine.h"
#include "src/cena/Cena.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Cena cena = carregarCena("assets/teste.json");
    Engine engine("Wari'", 1280, 720);
    engine.setTextos(cena.textos);

    
    engine.rodar();
    return 0;
}