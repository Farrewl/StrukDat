/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul tabel queue */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 21 September 2026 */
/***********************************/ 

#include <stdio.h>
#include "tqueue.h"

int main(){
    // Kamus Main
    tqueue Q;
    tqueue Q1, Q2;
    char e;       
    int i;        

    // Algoritma
    createQueue(&Q);
    printQueue(Q);
    viewQueue(Q);
    printf("isEmpty=%d isFull=%d isOne=%d size=%d\n\n",
           isEmptyQueue(Q), isFullQueue(Q), isOneElement(Q), sizeQueue(Q));

    scanf(" %c", &e);
    enqueue(&Q, e);

    printQueue(Q);
    viewQueue(Q);
    printf("head=%d tail=%d infoHead=%c infoTail=%c size=%d\n\n",
           head(Q), tail(Q), infoHead(Q), infoTail(Q), sizeQueue(Q));

    enqueue(&Q, 'D');
    enqueue(&Q, 'E');
    viewQueue(Q);
    printf("isFull=%d\n", isFullQueue(Q));
    enqueue(&Q, 'F');  
    viewQueue(Q);
    printf("size=%d\n\n", sizeQueue(Q));

    dequeue(&Q, &e);
    printf("e=%c\n", e);
    dequeue(&Q, &e);
    printf("e=%c\n", e);
    viewQueue(Q);
    printf("head=%d tail=%d \n\n",
           head(Q), tail(Q));

    while (!isEmptyQueue(Q)) {
        dequeue(&Q, &e);
        printf("e=%c\n", e);
    }
    dequeue(&Q, &e);
    printf("e=%c\n", e);
    printf("head=%d tail=%d isEmpty=%d\n\n", head(Q), tail(Q), isEmptyQueue(Q));

    createQueue(&Q1);
    createQueue(&Q2);
    enqueue2(&Q1, &Q2, 'X');
    enqueue2(&Q1, &Q2, 'Y');
    enqueue2(&Q1, &Q2, 'Z');
    enqueue2(&Q1, &Q2, 'W');
    printf("Q1 : ");
    viewQueue(Q1);
    printf("Q2 : ");
    viewQueue(Q2);

    dequeue2(&Q1, &Q2, &e);
    printf("e=%c\n", e);
    dequeue2(&Q1, &Q2, &e);
    printf("e=%c\n", e);
    dequeue2(&Q1, &Q2, &e);
    printf("e=%c\n", e);
    printf("Q1 : ");
    viewQueue(Q1);
    printf("Q2 : ");
    viewQueue(Q2);

    return 0;
}