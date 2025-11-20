#include "Dynamic_Queue_Header.h"
#include <stdio.h>
#include <stdlib.h>

DQueue* Initialization(int sizeQueue)
{
    DQueue* p_queue = (DQueue*) malloc(sizeof(DQueue));
    int *p_itens = (int*) calloc(sizeQueue,sizeof(int)); // usando calloc só para tudo começar com 0
    if((!p_queue)||(!p_itens))
    {
        return NULL; // retorna NULL pro ponteiro se não for criada
    }
    else
    {
        p_queue->scale= sizeQueue; // define scale para p tamanho inserido
        p_queue->quantity=0;
        p_queue->first=0;
        p_queue->last=0;
        p_queue->itens=p_itens;
    }
    return p_queue; // return address where the queue was create
}

int DQueue_is_empty(DQueue* dq)
{
    if(dq->quantity==0)
        return 1;
    else
        return 0;
}

int DQueue_is_full(DQueue* dq)
{
    if(dq->quantity==dq->scale)
        return 1;
    else
        return 0;
}

int DQueue_dequeue(DQueue* dq)
{
    if(!DQueue_is_empty(dq))
    {
        int return_value = dq->itens[dq->first];
        int aux_first = dq->first;
        dq->first = (dq->first + 1)%dq->scale;
        dq->quantity-=1;
        dq->itens[aux_first] = 696969; //  Sim, é pra ser considerado LIXO DE MEMÓRIA os "MeIaS NoVeS" KkKkKk LOL (XD)
        return return_value;
    }
    else
        return -1;
}

void Destruction(DQueue* dq)
{
    if(dq)
    {
        free(dq->itens);
        free(dq);
    }
    else
    {
        printf("\n\n");
        printf("\tQueue doesn't exist!\n");
        printf("\n--------------------------\n");
    }

}

void DQueue_enqueue(DQueue* dq, int value)
{
    if(!DQueue_is_full(dq))
    {
        dq->itens[dq->last] = value;
        dq->last = (dq->last + 1)%dq->scale;
        dq->quantity+=1;
        return;
    }
    else
    {
        int aux_oldScale = dq->scale;
        dq->scale*=2;
        int* p_newItens = (int*) realloc(dq->itens,dq->scale*sizeof(int));
        if(!p_newItens)
        {
            printf("\n\tERROR: Itens not allocate\n");
            return;
        }
        int aux_last = (dq->last+1)%aux_oldScale; // old_last
        dq->last = (dq->last+1)%dq->scale; // new_last
        for(int i = 1; i<dq->quantity; i++)
        {
            int aux_value = *(p_newItens+aux_last);
            *(p_newItens+aux_last) = '\0';
            *(p_newItens+dq->last) = aux_value;
            aux_last = (dq->last+1)%aux_oldScale; // old_last
            dq->last = (dq->last+1)%dq->scale; // new_last
        }
        *(p_newItens+dq->last) = value;
        dq->last = (dq->last+1)%dq->scale; // new_last
        dq->itens= p_newItens;
        dq->quantity+=1;
        return;
    }
}

int DQueue_peek(DQueue* dq)
{
    if(dq)
        return dq->itens[dq->first];
    else
        return -1;
}

void lista_elementos(DQueue *dq)
{
    if(dq)
    {
        printf("\n==========FILA Atual==========\n");
        for(int i = 0; i < dq->scale; i++)
        {
            printf("-");
            printf("|%d|", dq->itens[i]);
            printf("-");
        }
        printf("\nFirst: %d", dq->first);
        printf("\nLast: %d", dq->last);
        printf("\nQuantity: %d", dq->quantity);
        printf("\nScale: %d", dq->scale);
        printf("\n\n");
        printf("\n\t--------------------------\n");
    }
    else
    {
        printf("\n\n");
        printf("\tQueue doesn't exist!\n");
        printf("\n--------------------------\n");
    }
}
