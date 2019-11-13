#include "Caracol.h"


Caracol::Caracol(Texture *tex, int x, int y) {
	spt.setTexture(tex);
	ancho = tex->getSize().x;
	alto = tex->getSize().y;
    spt.setSize(Vector2f(ancho,alto));
	
	this->x = x;
	this->y = y;
	
	velX = 0;
	velY = 0;
    spt.setScale (0.3, 0.3);
}

void Caracol::dibujar(RenderWindow *w) {
	spt.setPosition(x, y);
	w->draw(spt);
}

void Caracol::arriba() {
	y += -5;
    if (y == -45){
        y= 600;
    }
}

void Caracol::abajo() {
	y += 5;
    if (y == 600){
        y= -45;
    }
    
}

void Caracol::girar(char dire) {
	if (dire == 'i'){
		x += -5;
        if (x == -90 ){
            x=650;
        }
    }
    
	else if (dire == 'd'){
		x += 5;
        if (x == 650 ){
            x= -90;
        }
    }
}

int Caracol::getMedioX() {
	return x + ancho / 2;
}

int Caracol::getY() {
	return y;
}
