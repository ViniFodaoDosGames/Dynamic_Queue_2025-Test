#include "Dynamic_Queue_Header.h"
#include <stdio.h>
#include <locale.h>

void __debug(DQueue* fila);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    DQueue* fila = Initialization(10);
    if(!fila)
    {
        printf("Existe NÃO Fila");
        return -1;
    }
    __debug(fila);
    lista_elementos(fila);
    Destruction(fila);
    fila=NULL;
    lista_elementos(fila);
    Destruction(fila);

    return 0;
}
void __debug(DQueue* fila)
{
    if(DQueue_is_empty(fila))
    {
        printf("\n\tVAZIA\n");
    }
    else
    {
        printf("\n\tNÃO Vazia\n");
    }

    if(DQueue_is_full(fila))
    {
        printf("\tCHEIA\n");
    }
    else
    {
        printf("\tNÃO Cheia\n");
    }
}
