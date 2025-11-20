#include "Dynamic_Queue_Header.h"
#include <stdio.h>
#include <locale.h>

void __debug(DQueue* fila);
int main()
{
    /**AS FUNÇÕES __debug É SÓ PARA VER SE A FILA TÁ CEIA OU VAZIAAAAAA*/
    setlocale(LC_ALL, "Portuguese");

    int size_queue = 10;
    DQueue* fila = Initialization(size_queue);

    if(!fila)
    {
        printf("Existe NÃO Fila");
        return -1;
    }
    __debug(fila);

    int id_queue = 100;
    printf("PUTTING ITENS IN QUEUE:\n");
    for(int i =0; i<size_queue*2; i++){
        DQueue_enqueue(fila, id_queue);
        printf("\n\t---\n");
        printf("\tID %d allocate successfully!\n", id_queue);
        printf("\t---\n");
        id_queue+=1;
    }
    __debug(fila);
    printf("REMOVING THE ITENS IN QUEUE:\n");
    while(!DQueue_is_empty(fila)){
        id_queue = DQueue_dequeue(fila);
        printf("\n\t---\n");
        printf("\tID %d removed successfully!\n", id_queue);
        printf("\tThe fist ID is now %d!\n", DQueue_peek(fila));
        printf("\t---\n");
    }
    __debug(fila);

    Destruction(fila);
    fila = NULL;

    /**No teste, tá funcionando td certinho.......... blergh!!*/

    return 0;
}
void __debug(DQueue* fila)
{
    printf("\n=================DEBUG MENU=================\n");
    if(DQueue_is_empty(fila))
    {
        printf("\n\tEMPTY\n");
    }
    else
    {
        printf("\n\tNOT Empty\n");
    }

    if(DQueue_is_full(fila))
    {
        printf("\tFULL\n");
    }
    else
    {
        printf("\tNOT Full\n");
    }
    printf("\n============================================\n");
}
