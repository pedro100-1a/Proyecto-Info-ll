#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Nodo.h"

template<typename T>
class LinkedList {
private:
    Nodo<T> *inicio;
    unsigned int tamanio;

    Nodo<T> *getNodo(int pos) const;

public:
    LinkedList();

    ~LinkedList();

    void put(T dato, int pos);

    T get(int pos);

    void remove(int pos);

    unsigned int size();

    void print();


    // Para recorrer con un for

    void begin();

    void next();

    bool ended();

};

template<typename T>
LinkedList<T>::LinkedList() {
    inicio = nullptr;
    tamanio = 0;
}

template<typename T>
void LinkedList<T>::put(T dato, int pos) {
    int posActual = 0;
    Nodo<T> *nuevo;

    if (pos == 0) {
        nuevo = new Nodo<T>(dato, inicio);
        tamanio++;
        inicio = nuevo;
    } else {
        Nodo<T> *aux = getNodo(pos - 1);
        nuevo = new Nodo<T>(dato, aux->next);
        tamanio++;
        aux->next = nuevo;
    }
}

template<typename T>
T LinkedList<T>::get(int pos) {

    Nodo<T> *aux = getNodo(pos);

    return aux->dato;
}

template<typename T>
Nodo<T> *LinkedList<T>::getNodo(int pos) const {
    int posActual = 0;
    Nodo<T> *aux = inicio;

    while (posActual < pos && aux != nullptr) {
        posActual++;
        aux = aux->next;
    }

    if (aux == nullptr)
        throw 404;

    return aux;
}

template<typename T>
void LinkedList<T>::remove(int pos) {
    Nodo<T> *aux;
    Nodo<T> *aBorrar;

    if (pos != 0) {
        aux = getNodo(pos - 1);
        aBorrar = aux->next;

        aux->next = aBorrar->next;

        delete aBorrar;
        tamanio--;
    } else {
        aBorrar = inicio;
        inicio = aBorrar->next;
        delete aBorrar;
        tamanio--;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (tamanio > 0) {
        remove(0);
    }
}

template<typename T>
unsigned int LinkedList<T>::size() {
    return tamanio;
}

template<typename T>
void LinkedList<T>::print() {
    Nodo<T> *aux = inicio;
    while (aux != nullptr) {
        std::cout << aux->dato << " -> ";
        aux = aux->next;
    }

    std::cout << std::endl;
}


#endif //LINKEDLIST_H
