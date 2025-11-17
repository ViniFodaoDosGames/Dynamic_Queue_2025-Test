#pragma once

typedef struct{
int *itens;
int first;
int last;
int quantity;
int scale;
} DQueue;


DQueue* Initialization(int sizeQueue); // done
void Destruction(DQueue* dq);// done
int DQueue_is_empty(DQueue* dq);// done
int DQueue_is_full(DQueue* dq);// done
void DQueue_enqueue(DQueue* dq, int value);// done
int DQueue_dequeue(DQueue* dq);// done
int DQueue_peek(DQueue* dq);// done
void lista_elementos(DQueue *dq);// done
