#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void mostrarOrdenLlegada (Fila* f)
{
    Fila aux;
    inicListaF(&aux);

    while (!filavacia(*f)) /// mientras haya dnis en la fila
    {
        printf("%i\t", primero(*f));  /// mostrar dni
        agregar(&aux, extraer(f));   /// agregar dni en aux
    }

    while (!filavacia(aux))
        agregar (f, extraer(&aux));  /// devolver dnis a fila
}

void mostrarDesdeUltimoRec2 (Fila* f, Fila* aux)
{
    if (!filavacia(*f))
    {
        int dato = primero(*f);
        agregar(aux, extraer(f));
        mostrarDesdeUltimoRec2(f, aux);
        printf("%i\t", dato);
    }
}

void mostrarDesdeUltimoRec (Fila* f)
{
    Fila aux;
    inicListaF(&aux);

    mostrarDesdeUltimoRec2(f, &aux);

    while (!filavacia(aux))
        agregar(f, extraer(&aux));
}

void atenderSoloDniPar (Fila* f)
{
    Fila aux;
    inicListaF(&aux);

    int basura;

    while (!filavacia(*f))
    {
        if (primero(*f) % 2 == 0)
            agregar(&aux, extraer(f));
        else
            basura = extraer(f);
    }

    while (!filavacia(aux))
        agregar(f, extraer(&aux));
}

int main()
{
    Fila dnis;
    inicListaF(&dnis);

    agregar(&dnis, 44562987);
    agregar(&dnis, 44493787);
    agregar(&dnis, 43456954);
    agregar(&dnis, 41454265);
    agregar(&dnis, 40493094);
    agregar(&dnis, 38494034);

    mostrarOrdenLlegada(&dnis);

    printf("\n");
    mostrarDesdeUltimoRec(&dnis);

    atenderSoloDniPar(&dnis);

    printf("\n");
    mostrarOrdenLlegada(&dnis);

    return 0;
}
