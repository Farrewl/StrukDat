/* Program   : mtqueue3.c */
/* Deskripsi : file DRIVER modul tabel queue 3 */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 28 September 2026 */
/***********************************/ 

#include <stdio.h>
#include "tqueue3.h"

int main(){
    // Kamus Main
    tqueue3 Q;
    char e;

    // Algoritma
    createQueue3(&Q);
    printQueue3(Q);
    viewQueue3(Q);
    printf("isEmpty=%d isFull=%d isOne=%d size=%d\n\n",
           isEmptyQueue3(Q), isFullQueue3(Q), isOneElement3(Q), sizeQueue3(Q));

    scanf(" %c", &e);
    enqueue3(&Q, e);
    enqueue3(&Q, 'B');
    enqueue3(&Q, 'C');

    printQueue3(Q);
    viewQueue3(Q);
    printf("head=%d tail=%d infoHead=%c infoTail=%c size=%d\n\n",
           head3(Q), tail3(Q), infoHead3(Q), infoTail3(Q), sizeQueue3(Q));

    enqueue3(&Q, 'D');
    enqueue3(&Q, 'E');
    printQueue3(Q);
    viewQueue3(Q);
    printf("isFull=%d isOne=%d size=%d\n\n",
           isFullQueue3(Q), isOneElement3(Q), sizeQueue3(Q));

    // coba enqueue saat penuh, harusnya tidak masuk
    enqueue3(&Q, 'F');
    viewQueue3(Q);
    printf("size=%d (tetap 5)\n\n", sizeQueue3(Q));

    dequeue3(&Q, &e);
    printf("e=%c\n", e);
    dequeue3(&Q, &e);
    printf("e=%c\n", e);
    printQueue3(Q);
    viewQueue3(Q);
    printf("head=%d tail=%d size=%d\n\n",
           head3(Q), tail3(Q), sizeQueue3(Q));

    // uji head dan tail memutar searah jarum jam
    enqueue3(&Q, 'F');
    enqueue3(&Q, 'G');
    printQueue3(Q);
    viewQueue3(Q);
    printf("head=%d tail=%d size=%d tailOverHead=%d\n\n",
           head3(Q), tail3(Q), sizeQueue3(Q), isTailOverHead(Q));

    while (!isEmptyQueue3(Q)) {
        dequeue3(&Q, &e);
        printf("e=%c\n", e);
    }
    dequeue3(&Q, &e);
    printf("e='%c'\n", e);
    printf("head=%d tail=%d isEmpty=%d\n", head3(Q), tail3(Q), isEmptyQueue3(Q));

    return 0;
}
