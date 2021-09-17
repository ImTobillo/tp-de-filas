#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Fila.h"

/// ejercicio 1
/*void mostrarOrdenLlegada (Fila* f)
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
*/

/// ejercicio 2

/*void cargarProcesosRandom (Fila* filaProcesos, int cant)
{
    elemento proceso;

    for (int i = 0; i < cant; i++)
    {
        proceso.id = rand() % 255 + 1;
        proceso.duracion = rand() % 10 + 1;

        agregar(filaProcesos, proceso);
    }
}

void mostrarProcesos (Fila* filaProcesos)
{
    Fila aux;
    inicListaF(&aux);

    while (!filavacia(*filaProcesos))
    {
        printf("ID: %i\t", primero(*filaProcesos).id);
        printf("Duracion: %i", primero(*filaProcesos).duracion);
        printf("\n\n");

        agregar(&aux, extraer(filaProcesos));
    }

    while (!filavacia(aux))
        agregar(filaProcesos, extraer(&aux));
}

void cargarListos (Fila* listos, Fila* procesos)
{
    Fila aux;
    inicListaF(&aux);

    while (!filavacia(*procesos))
    {
        if (primero(*procesos).duracion < 5)
            agregar(listos, extraer(procesos));
        else
            agregar(&aux, extraer(procesos));
    }

    while (!filavacia(aux))
        agregar(procesos, extraer(&aux));
}

void cargarSuspListos (Fila* suspListos, Fila* procesos)
{
    Fila aux;
    inicListaF(&aux);

    while (!filavacia(*procesos))
    {
        if (primero(*procesos).duracion >= 5)
            agregar(suspListos, extraer(procesos));
        else
            agregar(&aux, extraer(procesos));
    }

    while (!filavacia(aux))
        agregar(procesos, extraer(&aux));
}

void ejecutarProcesos (Fila* listos, Fila* suspListos)
{
    elemento ejecutado;

    while (!filavacia(*listos))
        ejecutado = extraer(listos);

    while (!filavacia(*suspListos))
        agregar(listos, extraer(suspListos));

    while (!filavacia(*listos))
        ejecutado = extraer(listos);
}
*/
/// ejercicio 3

void cargarPeticion (Fila* peticiones, int prior, char categ)
{
    elemento peticion;
    peticion.categoria = categ;
    peticion.prioridad = prior;
    agregar(peticiones, peticion);
}

void mostrarPeticiones (Fila* peticiones)
{
    Fila aux;
    inicListaF(&aux);

    printf("\nPETICIONES\n");
    while (!filavacia(*peticiones))
    {
        printf("PRIORIDAD: %i\t", primero(*peticiones).prioridad);
        printf("CATEGORIA: %c", primero(*peticiones).categoria);
        printf("\n");

        agregar(&aux, extraer(peticiones));
    }

    while (!filavacia(aux))
        agregar(peticiones, extraer(&aux));
}

int contarPetCatC (Fila* peticiones)
{
    Fila aux;
    inicListaF(&aux);
    int cant = 0;

    while (!filavacia(*peticiones))
    {
        if (primero(*peticiones).categoria == 'c')
            cant++;
        agregar(&aux, extraer(peticiones));
    }

    while (!filavacia(aux))
        agregar(peticiones, extraer(&aux));

    return cant;
}

int menorPrioridad (Fila* peticiones)
{
    if (!filavacia(*peticiones))
    {
        Fila aux;
        inicListaF(&aux);

        int menorP = primero(*peticiones).prioridad;
        agregar(&aux, extraer(peticiones));

        while (!filavacia(*peticiones))
        {
            if (primero(*peticiones).prioridad < menorP)
                menorP = primero(*peticiones).prioridad;
            agregar(&aux, extraer(peticiones));
        }

        while (!filavacia(aux))
            agregar(peticiones, extraer(&aux));

        return menorP;
    }
    else
        return -1;
}

void contarPetMenPrior (Fila* peticiones)
{
    Fila aux;
    inicListaF(&aux);

    int menorP = menorPrioridad(peticiones), cantMenorP = 0;

    while (!filavacia(*peticiones))
    {
        if (primero(*peticiones).prioridad == menorP)
            cantMenorP++;
        agregar(&aux, extraer(peticiones));
    }
    while (!filavacia(aux))
        agregar(peticiones, extraer(&aux));

    printf("\n%i peticiones con prioridad %i en el servidor", cantMenorP, menorP);
}

int main()
{
    srand(time(NULL));

    /*Fila dnis;
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
    */

    /*Fila procesos;
    inicListaF(&procesos);

    cargarProcesosRandom(&procesos, 8);

    mostrarProcesos(&procesos);

    Fila listos, suspListos;
    inicListaF(&listos);
    inicListaF(&suspListos);

    cargarListos(&listos, &procesos);
    cargarSuspListos(&suspListos, &procesos);

    printf("\nLISTOS:\n");
    mostrarProcesos(&listos);
    printf("\nSUSP/LISTOS:\n");
    mostrarProcesos(&suspListos);

    ejecutarProcesos (&listos, &suspListos);

    printf("\nLISTOS:\n");
    mostrarProcesos(&listos);
    printf("\nSUSP/LISTOS:\n");
*/

    Fila peticiones;
    inicListaF(&peticiones);

    cargarPeticion (&peticiones, 1, 'a');
    cargarPeticion (&peticiones, 5, 'c');
    cargarPeticion (&peticiones, 3, 'b');
    cargarPeticion (&peticiones, 2, 'd');
    cargarPeticion (&peticiones, 1, 'b');
    cargarPeticion (&peticiones, 2, 'a');
    cargarPeticion (&peticiones, 3, 'c');

    mostrarPeticiones(&peticiones);

    printf("\nCANTIDAD CAT 'C': %i", contarPetCatC(&peticiones));

    contarPetMenPrior(&peticiones);

    return 0;
}
