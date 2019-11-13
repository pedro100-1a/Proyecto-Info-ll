#ifndef VERDURAS_H
#define VERDURAS_H
#include "Caracol.h"
#include "Stack.h"
#include "Nodo.h"
#include <SFML/Graphics.hpp>

using namespace sf;
class Verdura {
public:
    
    Verdura(int x, int y,int tipo, Texture *tex);
    void dibujar(RenderWindow *w);
    bool colicion(Caracol p);
    
private:
    
    int x;
    int y;
    int tipo;
    RectangleShape spt;  
    
};


#endif
