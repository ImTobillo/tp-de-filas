#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int prioridad;
    char categoria;
}peticion;

typedef struct
{
    int id;
    int duracion;
}StProceso;

typedef peticion elemento;

typedef struct nodoD
{
    elemento dato;
    struct nodoD* sig;
    struct nodoD* ant;
}nodoD;

typedef struct
{
    struct nodoD* prim;
    struct nodoD* ult;
}Fila;

void inicListaF (Fila*);
nodoD* crearNodoD (elemento dato);
void agregar (Fila*, elemento dato);
elemento extraer (Fila*);
elemento primero (Fila);
int filavacia (Fila);

#endif // FILA_H_INCLUDED
