/* Program   : mtqueue2.c */
/* Deskripsi : file DRIVER modul tabel queue 2 */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 21 September 2026 */
/***********************************/ 

#include <stdio.h>
#include "tqueue2.h"

int main()
{
    // Kamus Main
    tqueue2 Q;      
    tqueue2 Qa, Qb; 
    char e;       

    /*Algoritma*/
    createQueue2(&Q);
    printQueue2(Q);
    viewQueue2(Q);
    printf("isEmpty=%d isFull=%d isOne=%d size=%d\n\n",
           isEmptyQueue2(Q), isFullQueue2(Q), isOneElement2(Q), sizeQueue2(Q));

    enqueue2N(&Q, 3);
    printQueue2(Q);
    viewQueue2(Q);
    printf("head=%d tail=%d infoHead=%c infoTail=%c size=%d\n\n",
           head2(Q), tail2(Q), infoHead2(Q), infoTail2(Q), sizeQueue2(Q));

    enqueue2(&Q, 'D');
    enqueue2(&Q, 'E');
    printQueue2(Q);
    viewQueue2(Q);
    printf("isFull=%d tailStop=%d head=%d tail=%d\n\n",
           isFullQueue2(Q), isTailStop(Q), head2(Q), tail2(Q));

    dequeue2(&Q, &e);
    printf("e=%c\n", e);
    dequeue2(&Q, &e);
    printf("e=%c\n", e);
    viewQueue2(Q);
    printf("head=%d tail=%d \n\n",
           head2(Q), tail2(Q));

    enqueue2(&Q, 'F');
    printQueue2(Q);
    viewQueue2(Q);
    printf("head=%d tail=%d size=%d\n\n", head2(Q), tail2(Q), sizeQueue2(Q));

    while (!isEmptyQueue2(Q)) {
        dequeue2(&Q, &e);
        printf("e=%c\n", e);
    }
    dequeue2(&Q, &e);
    printf("e=%c\n", e);
    printf("head=%d tail=%d isEmpty=%d\n\n", head2(Q), tail2(Q), isEmptyQueue2(Q));

    createQueue2(&Qa);
    createQueue2(&Qb);
    enqueue2(&Qa, 'M');
    enqueue2(&Qa, 'N');
    enqueue2(&Qb, 'M');
    enqueue2(&Qb, 'N');
    printf("Qa(head=%d) : ", head2(Qa));
    viewQueue2(Qa);
    printf("Qb(head=%d) : ", head2(Qb));
    viewQueue2(Qb);
    printf("isEqualQueue2(Qa,Qb)=%d \n\n", isEqualQueue2(Qa, Qb));

    dequeue2(&Qb, &e);            
    enqueue2(&Qb, 'O');           
    printf("Qa(head=%d) : ", head2(Qa));
    viewQueue2(Qa);
    printf("Qb(head=%d) : ", head2(Qb));
    viewQueue2(Qb);
    printf("isEqualQueue2(Qa,Qb)=%d \n", isEqualQueue2(Qa, Qb));

    createQueue2(&Qa);
    createQueue2(&Qb);
    enqueue2(&Qa, 'P');
    enqueue2(&Qa, 'Q');
    enqueue2(&Qb, 'P');
    enqueue2(&Qb, 'Q');
    dequeue2(&Qb, &e);         
    enqueue2(&Qb, 'R');         
    enqueue2(&Qb, 'S');
    printf("\nQa(head=%d) : ", head2(Qa));
    viewQueue2(Qa);
    printf("Qb(head=%d) : ", head2(Qb));
    viewQueue2(Qb);
    printf("isEqualQueue2(Qa,Qb)=%d \n", isEqualQueue2(Qa, Qb));

    return 0;
}