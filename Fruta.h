#ifndef FRUTAS_H
#define FRUTAS_H
#include "Caracol.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Fruta {
    
public:
    
    Fruta(int x, int y,int tipo, Texture *tex);
    
    void dibujar(RenderWindow *w,RectangleShape sptCaracol);
    
    bool colicion(Caracol p);
    
    
private:
    
    int x;
    int y;
    int tipo;
    RectangleShape spt;  
};


#endif

