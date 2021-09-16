#include "Fila.h"

void inicListaF (Fila* f)
{
    f->prim = NULL;
    f->ult = NULL;
}

nodoD* crearNodoD (int dato)
{
    nodoD* aux = (nodoD*)malloc(sizeof(nodoD));
    aux->dato = dato;
    aux->sig = NULL;
    aux->ant = NULL;
    return aux;
}

void agregar (Fila* f, int dato)
{
    nodoD* aux = crearNodoD(dato);

    if (f->prim) // si fila tiene datos, entonces el primer dato es != null
    {

    }
    else // si no hay ningun dato en fila
    {
        f->prim = aux;
        f->ult = aux;
    }
}

void extraer (Fila*)
{

}

void primero (Fila)
{

}

void filavacia (Fila)
{

}


