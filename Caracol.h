#ifndef CARACOL_H
#define CARACOL_H

#include <SFML/Graphics.hpp>

using namespace sf;


class Caracol{
private:
	int x;
	int y;
	int velX;
	int velY;
	int ancho;
	int alto;
	Sprite spt;
	
public:
	Caracol(Texture *tex, int x, int y);
	
	void mover();
	
	void dibujar(RenderWindow *w);
	
	void arriba();
	
	void abajo();
	
	void girar(char dire);
	
	
	// Agregadas
	
	int getMedioX();
	
	int getY();
	
	
};

#endif
