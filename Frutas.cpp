#include "Fruta.h"


Fruta::Fruta(int x, int y, int tipo, Texture *tex) {
	
    spt.setTexture(&tex[tipo]);
    spt.setSize (Vector2f (tex[tipo].getSize().x,tex[tipo].getSize().y));   
    this->x = x;
    this->y = y;
    this->tipo = tipo;
    
}

void Fruta::dibujar(RenderWindow *w,RectangleShape sptCaracol) {
    spt.setPosition(x, y);
    

    w->draw(spt);
}

bool Fruta::colicion(Caracol p){
    
    // Esquina superior izquierda
    
    if (p.x > this->x && p.x < (x + 40 ) && p.y < y && p.y > (y + 40 ) ){
        
        return true;
    }

    // Esquina superior derecha  

if ((p.x + 70 ) > x && (p.x + 70 ) < (x + 40 ) && p.y > y && p.y < (y + 40 ) ){
    
    return true;
}

  // Esquina Inferior derecha  

if ((p.x + 70 ) > x && (p.x + 70 ) < (x + 40 ) && (p.y + 50) > y && (p.y + 50) < (y + 40 ) ){
    
    return true;
}

// Esquina Inferior izquierda  

if (p.x > x && p.x  < (x + 40) && (p.y + 50) > y && (p.y + 50) < (y + 40 ) ){
    
    return true;
}

else 
        return false;

}
