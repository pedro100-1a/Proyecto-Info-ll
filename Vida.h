#ifndef VIDA_H
#define VIDA_H
#include "Caracol.h"
#include "Stack.h"
#include <SFML/Graphics.hpp>

class Vida {
public:
	Vida(int x, int y,int tipo, Texture *tex);
    void dibujar(RenderWindow *w);
    
private:
    
    int x;
    int y;
    int tipo;
    RectangleShape spt;  
    
};

#endif

