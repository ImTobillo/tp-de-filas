#include "Fila.h"

void inicListaF (Fila* f)
{
    f->prim = NULL;
    f->ult = NULL;
}

nodoD* crearNodoD (elemento dato)
{
    nodoD* aux = (nodoD*)malloc(sizeof(nodoD));
    aux->dato = dato;
    aux->sig = NULL;
    aux->ant = NULL;
    return aux;
}

void agregar (Fila* f, elemento dato)
{
    nodoD* aux = crearNodoD(dato);

    if (f->prim) // si fila tiene datos, entonces el primer dato es != null
    {
        f->ult->sig = aux;
        aux->ant = f->ult;
        f->ult = aux;
    }
    else // si no hay ningun dato en fila
    {
        f->prim = aux;
        f->ult = aux;
    }
}

elemento extraer (Fila* f)
{
    elemento ret = f->prim->dato;

    nodoD* aux = f->prim;

    if (f->prim->sig) // si la fila tiene mas de un dato
    {
        f->prim = f->prim->sig;
        f->prim->ant = NULL;
    }
    else
        inicListaF(f);

    free(aux);
    return ret;
}

elemento primero (Fila f)
{
    return f.prim->dato;
}

int filavacia (Fila f)
{
    return (f.prim == NULL);
}


