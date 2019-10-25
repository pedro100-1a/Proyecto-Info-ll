#include <SFML/Graphics.hpp>
#include <iostream>

#include "Caracol.h"

using namespace sf;


void texto(RenderWindow * w){
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }
    // select the font
    text.setFont(font); // font is a sf::Font
    
    // set the string to display
    text.setString("xdrtxhcr");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    
    // set the color
    text.setFillColor(sf::Color::Black);
    
    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(40,20);

        // inside the main loop, between window.clear() and window.display()
        w->draw(text);
    
}

int main() {
	
	
	RenderWindow w(VideoMode(640, 480), "Caracol SFML");
	Texture tCaracol;
	Sprite sCaracol;
    
	tCaracol.loadFromFile("caracol.png");
	Caracol player(&tCaracol, 640/ 2, 480 / 2);


    
    Texture tFondo;
    Sprite sFondo;
    
    tFondo.loadFromFile("pasto.jpg");
    sFondo.setTexture(tFondo);
	
	w.setFramerateLimit(60);
	
	while (w.isOpen()) {
		Event e;
		while (w.pollEvent(e)) {
			if (e.type == Event::Closed)
				w.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player.girar('i');
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player.girar('d');
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			player.arriba();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			player.abajo();
		}
		
		
		w.clear(Color(255, 255, 255, 255));
        // de aca en adelante dibujo
        
        w.draw(sFondo);
        
		player.dibujar(&w);
        texto(&w);
        
		w.display();
	}
	return 0;
}
