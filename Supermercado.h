#ifndef INC_23_1_HERRERAOCAMPOMARTIN_SUPERMERCADO_H
#define INC_23_1_HERRERAOCAMPOMARTIN_SUPERMERCADO_H

typedef struct persona {
    int cantElementos;
    struct persona *siguiente;
} Persona;

typedef struct cola {
    int cantPersonas;
    Persona *primera;
} Cola;

Cola *crearCola();
Persona *crearPersona(int cantElementos);
int calcularTiempoAtencion(Cola *cola);
void encolarPersona(Cola *cola, Persona *nueva);
void desencolarPersona(Cola *cola);
void imprimirCola(Cola *cola);
void liberarCola(Cola *cola);

#endif
