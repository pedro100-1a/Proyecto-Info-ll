#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Caracol.h"
#include "Fruta.h"
#include "Verdura.h"
#include "Vida.h"
#include "Queue.h"
#include "Nodo.h"
#include "Stack.h"
#include <stdlib.h>
#include <time.h>


using namespace sf;

/////TEXTO PUNTAJE

void textopuntaje(RenderWindow * g, int a){
    sf::Text text2;
    sf::Font font2;
    std::stringstream txt;
    txt<< "PUNTAJE : " << a;
    
    if (!font2.loadFromFile("arial.ttf"))
    {}
    text2.setFont(font2); 
    text2.setString(txt.str());
    text2.setCharacterSize(15); 
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold );
    text2.setPosition(220,20);
    g->draw(text2);
}
    /////TEXTO VIDA

    void textovida(RenderWindow * s, int v){
        sf::Text text3;
        sf::Font font3;
        std::stringstream txt;
        txt<< "VIDA : " << v;
    
        if (!font3.loadFromFile("arial.ttf"))
        {}
        text3.setFont(font3); 
        text3.setString(txt.str());
        text3.setCharacterSize(15); 
        text3.setFillColor(sf::Color::Black);
        text3.setStyle(sf::Text::Bold );
        text3.setPosition(420,20);
        s->draw(text3);
        
        if (!font3.loadFromFile("arial.ttf"))
        {}
        text3.setFont(font3);
        text3.setString(txt.str());
        text3.setCharacterSize(15); 
        text3.setFillColor(sf::Color::Black);
        text3.setStyle(sf::Text::Bold );
        text3.setPosition(450,20);
        s->draw(text3);
}
///////TEXTO TIEMPO
        
        void textotiempo(RenderWindow * w, int t){
            sf::Text text;
            sf::Font font;
            std::stringstream txt;
            txt << "TIEMPO: " << t;
            if (!font.loadFromFile("arial.ttf"))
            {}
            text.setFont(font);
            text.setString(txt.str());
            text.setCharacterSize(15); 
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Bold );
            text.setPosition(10,20);
            w->draw(text);
        }
//////////////////////////////////MAIN///////////////////////////////////
            
int main() {
    
    Queue<Fruta*> frutas;    
    Queue<Verdura*> verduras;
    
    //////CREA LA PILA
    
    Stack<int> pila_vida;
    pila_vida.push(1);
    pila_vida.push(1);
    pila_vida.push(1);
    
    
    srand(time(NULL));
    
    int seg = 0, contseg = 0, contfrutas = 0, contverduras = 0; 
    int puntaje = 0,vivi = pila_vida.size(); 
	
	////TAMAÑO DE LA PANTALLA Y NOMBRE DE LA MISMA
    
	RenderWindow w(VideoMode(640, 480), "Hungry Snail");
    
    ////TEXTURA Y SPRITE DEL CARACOL
    
	Texture tCaracol;
	RectangleShape sCaracol;
	tCaracol.loadFromFile("caracol.png");
    sCaracol.setSize (Vector2f (tCaracol.getSize().x,tCaracol.getSize().y));
	Caracol player(&tCaracol, 640/ 2, 480 / 2);

    ////TEXTURA Y SPRITE DEL FONDO
    
    Texture tFondo;
    Sprite sFondo;
    tFondo.loadFromFile("pasto.jpg");
    sFondo.setTexture(tFondo);
  
    ////TEXTURA Y SPRITE DEL GAME OVER  
    
    Texture tGO;
    Sprite sGO;
    tGO.loadFromFile("GameOver.jpg");
    sGO.setTexture(tGO);
    
    ////TEXTURA Y SPRITE DE FRUTAS
    
    Texture tFruta[2];
    std::string imgFruta[2] = {
        "banana.png",
        "manzana.png"
    };
    
    //// RECORRE ARREGLO DE FRUTAS
    
    for(int i =0; i<2 ;i++){ 
        tFruta[i].loadFromFile(imgFruta[i]);
    }
    ////CREA FRUTA DA LA POSICION RANDOM LIMITADA
    
    for(int i=0;i<2;i++){ 
        frutas.enqueue(new Fruta(rand()%400, rand()%400,rand()%2,tFruta));
    }
    
    //// TEXTURA Y SPRITE DE VERDURAS
    
    Texture tVerdura[2];
    std::string imgVerdura[2] = {
        "lechuga.png",
        "tomate.png"
    };
    
    //// RECORRE ARREGLO DE VERDURAS
    
    for(int i =0; i<2 ;i++){ 
        tVerdura[i].loadFromFile(imgVerdura[i]);
    }
    ////CREA VERDURA DA LA POSICION RANDOM LIMITADA
    
    for(int i=0;i<2;i++){ 
        verduras.enqueue(new Verdura(rand()%400, rand()%400,rand()%2,tVerdura));
    }
    
    w.setFramerateLimit(60);

	while (w.isOpen()) {
        
    /////CONTADOR TIEMPO
        
       contseg++;
        if (contseg==60){
            seg++;
            contseg=0;
        }
        
		Event e;
		while (w.pollEvent(e)) {
			if (e.type == Event::Closed)
				w.close();
		}
        
    ///// CONFIGURACION DE TECLAS 
        
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
		
        /////COLAS
        
        for(frutas.begin(); ! frutas.end(); frutas.next()){ 
            if(frutas.getActual()->colicion(player)){
                    delete frutas.getActual();
                    frutas.getActual() = new Fruta(rand()%400,rand()%400,rand()%2,tFruta);
                    
                    puntaje+=10;
            }
            
        } 
    
        for(verduras.begin(); ! verduras.end(); verduras.next()){ 
            if(verduras.getActual()->colicion(player)){
                delete verduras.getActual();
                verduras.getActual() = new Verdura(rand()%400,rand()%400,rand()%2,tVerdura);
                pila_vida.pop();
                vivi = pila_vida.size();
            }
        
        }
       
        
		//////LIMPIA PANTALLA
        
		w.clear(Color(255, 255, 255, 255));
        
        //////DE ACA EN ADELANTE DIBUJA TODO EN ORDEN PUESTO
        
        w.draw(sFondo);
        
        textopuntaje(&w, puntaje);
        textovida(&w,vivi);
        textotiempo(&w, seg);
         
        //////RECORRETA LA COLA DE FRUTTAS Y VERDURAS 
        
        for(frutas.begin(); ! frutas.end(); frutas.next()){ 
            frutas.getActual()->dibujar(&w,player.spt);
        } 

        for(verduras.begin(); ! verduras.end(); verduras.next()){ 
            verduras.getActual()->dibujar(&w);
        }
        
        player.dibujar(&w);
        
        if(pila_vida.empty()){ ////si la pila esta vacia dibuja GAME OVER
            
        w.draw(sGO); 
            
        }   
        
		w.display();
        
        contfrutas++;
        contverduras++;
        
        ////ARCHIVO PARA GUARDAR PUNTAJE
     
        std::ofstream archivo("ListaPuntajes.txt");
        
        if (archivo.bad()){
            std::cout << "Incapaz de crear/abrir el fichero." << std::endl;
        }

        else{
            archivo  <<"Puntaje: " << puntaje << std::endl;
            archivo.close();
        } 
        
       ////DESENCOLA PARA VOLVER A ENCOLAR EN NUEVA POSICION RANDOM 
        
        if(contfrutas == 100){
            Fruta *aBorrar = frutas.dequeue();
            delete aBorrar;
            frutas.enqueue(new Fruta((rand()%16) *40, (rand()%11+1)*40,rand()%2,tFruta)); 
            contfrutas=0;
        }
       
       if(contverduras == 100){
           Verdura *aBorrar = verduras.dequeue();
           delete aBorrar;
           verduras.enqueue(new Verdura((rand()%16) *40, (rand()%11+1)*40,rand()%2,tVerdura)); 
           contverduras=0;
       }
       
    
	}
	return 0;
}
