#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD
{
    int dato;
    struct nodoD* sig;
    struct nodoD* ant;
}nodoD;

typedef struct
{
    struct nodoD* prim;
    struct nodoD* ult;
}Fila;

void inicListaF (Fila*);
nodoD* crearNodoD (int dato);
void agregar (Fila*, int dato);
int extraer (Fila*);
int primero (Fila);
int filavacia (Fila);

#endif // FILA_H_INCLUDED
