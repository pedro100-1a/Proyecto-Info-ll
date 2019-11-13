#include "Vida.h"

Vida::Vida(int x, int y,int tipo, Texture *tex) {
    
    spt.setTexture(&tex[tipo]);
    spt.setSize (Vector2f (tex[tipo].getSize().x,tex[tipo].getSize().y));  
    
    this->x = x;
    this->y = y;
    this->tipo = tipo;
	
}

void Vida::dibujar(RenderWindow *w) {
    spt.setPosition(x, y);
    
    w->draw(spt);
}


