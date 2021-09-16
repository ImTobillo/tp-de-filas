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

void mostrarDesdeUltimo (Fila* f)
{
    Fila aux;
    inicListaF(&aux);


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



    return 0;
}
