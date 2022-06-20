#include <stdio.h>
#include "Supermercado.h"

int main() {

    printf("\n\nCAJA 1\n");

    Cola *caja1 = crearCola();
    encolarPersona(caja1, crearPersona(12));
    encolarPersona(caja1, crearPersona(24));
    encolarPersona(caja1, crearPersona(5));
    encolarPersona(caja1, crearPersona(6));
    encolarPersona(caja1, crearPersona(34));
    encolarPersona(caja1, crearPersona(76));
    imprimirCola(caja1);
    printf("\n");
    calcularTiempoAtencion(caja1);
    desencolarPersona(caja1);
    printf("\nSale una persona.\n");
    imprimirCola(caja1);

    printf("\n\nCAJA 2\n");

    Cola *caja2 = crearCola();
    encolarPersona(caja2, crearPersona(43));
    encolarPersona(caja2, crearPersona(2));
    encolarPersona(caja2, crearPersona(54));
    encolarPersona(caja2, crearPersona(65));
    imprimirCola(caja2);
    printf("\n");
    calcularTiempoAtencion(caja2);
    desencolarPersona(caja2);
    printf("\nSale una persona.\n");
    imprimirCola(caja2);

    printf("\n\nCAJA 3\n");

    Cola *caja3 = crearCola();
    encolarPersona(caja3, crearPersona(3));
    encolarPersona(caja3, crearPersona(65));
    encolarPersona(caja3, crearPersona(1));
    imprimirCola(caja3);
    printf("\n");
    calcularTiempoAtencion(caja3);
    desencolarPersona(caja3);
    printf("\nSale una persona.\n");
    imprimirCola(caja3);

    liberarCola(caja1);
    liberarCola(caja2);
    liberarCola(caja3);

    return 0;
}
