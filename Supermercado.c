#include "Supermercado.h"
#include <stdlib.h>
#include <stdio.h>
#define __TIEMPO_POR_ELEMENTO__ 3

Cola *crearCola(){
    Cola *cola = (Cola*) malloc(sizeof (Cola));

    if(cola == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    cola->primera = NULL;
    cola->cantPersonas = 0;

    return cola;
}

Persona *crearPersona(int cantElementos){
    Persona *persona = (Persona*) malloc(sizeof (Persona));

    if(persona == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    persona->cantElementos = cantElementos;
    persona->siguiente = NULL;

    return persona;
}

void encolarPersona(Cola *cola, Persona *nueva){
    Persona *aux = cola->primera;

    if(aux == NULL){
        cola->primera = nueva;
        cola->cantPersonas++;
        return;
    }

    for(; aux->siguiente != NULL; aux = aux->siguiente){}

    aux->siguiente = nueva;
    cola->cantPersonas++;
}

void desencolarPersona(Cola *cola){
    Persona *aux = cola->primera;

    if(aux == NULL){
        return;
    }

    cola->primera = aux->siguiente;
    free(aux);
    cola->cantPersonas--;
}

int calcularTiempoAtencion(Cola *cola){
    int suma = 0, tiempo;

    Persona *aux = cola->primera;

    if(aux == NULL){
        printf("No hay personas en la cola.\n");
        return 0;
    }

    for(int i = 1; aux != NULL; aux = aux->siguiente, i++){
        tiempo = aux->cantElementos * __TIEMPO_POR_ELEMENTO__;
        suma += tiempo;
        printf("La persona en la posición %d va a tardar %d segundos.\n", i, tiempo);
    }

    printf("Tiempo total de atención: %d segundos.\n", suma);

    return suma;
}

void imprimirCola(Cola *cola){
    Persona *aux = cola->primera;

    if(aux == NULL){
        printf("No hay personas en la cola.\n");
        return;
    }

    for(int i = 1; aux != NULL; aux = aux->siguiente, i++){
        printf("La persona en la posición %d lleva %d elementos.\n", i, aux->cantElementos);
    }
}

void liberarCola(Cola *cola){
    Persona *act = cola->primera;

    while(act != NULL){
        Persona *sig = act->siguiente;
        free(act);
        act = sig;
    }

    free(cola);
}