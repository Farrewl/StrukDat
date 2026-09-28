/* Program   : tqueue.c */
/* Deskripsi : file BODY modul tabel queue */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 21 September 2026 */
/***********************************/ 
#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/
void createQueue(tqueue *Q){
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 1; i <= 5; i++) {
        Q->wadah[i] = '-';
    }
    Q->head = 0;
    Q->tail = 0;
}

/*function infoHead(Q:tQueue)-> character
{mengembalikan nilai elemen terdepan antrian Q}
{bila Q kosong, mengembalikan '-'}*/
int infoHead(tqueue Q){
    // Kamus Lokal
    
    // Algoritma
    if (isEmptyQueue(Q)) {
        return '-';
    } 
    else {
        return Q.wadah[Q.head];
    }
}

/*function infoTail(Q:tQueue)-> character
{mengembalikan nilai elemen terakhir antrian Q}
{bila Q kosong, mengembalikan '-'}*/
int infoTail(tqueue Q){
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue(Q)) {
        return '-';
    } 
    else {
        return Q.wadah[Q.tail];
    }
}

/*function sizeQueue(Q:tQueue)-> integer
{mengembalikan panjang antrian Q}
{bila Q kosong, mengembalikan 0}*/
int sizeQueue(tqueue Q){
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue(Q)) {
        return 0;
    } 
    else {
        return Q.tail - Q.head + 1;
    }
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 1; i <= 5; i++) {
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q){
    // Kamus Lokal
    int i;

    // Algoritma
    if (isEmptyQueue(Q)) {
        printf("kosong\n");
    } 
    else {
        for (i = head(Q); i <= tail(Q); i++) {
            printf("%c ", Q.wadah[i]);
        }
        printf("\n");
    }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    // Kamus Lokal

    // Algoritma
    return (head(Q) == 0) && (tail(Q) == 0);
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    // Kamus Lokal

    // Algoritma
    return (tail(Q) == 5);
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    // Kamus Lokal

    //Algoritma
    return (head(Q) != 0) && (head(Q) == tail(Q));
}

/*procedure enqueue( input/output Q:tQueue, input e: character )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char e){
    // Kamus Lokal

    // Algoritma
    if (!isFullQueue(*Q)) {
        if (isEmptyQueue(*Q)) {
            head(*Q) = 1;
        }
        tail(*Q) = tail(*Q) + 1;
        Q->wadah[tail(*Q)] = e;
    }
}

/*procedure deQueue( input/output Q:tQueue, output e: character )
{I.S.: -}
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *e){
    // Kamus Lokal
    int i;

    // Algoritma
    if (isEmptyQueue(*Q)) {
        *e = '-';
    } 
    else {
        *e = Q->wadah[head(*Q)];

        for (i = head(*Q); i < tail(*Q); i++) {
            Q->wadah[i] = Q->wadah[i + 1];
        }
        Q->wadah[tail(*Q)] = '-';
        tail(*Q) = tail(*Q) - 1;
        if (tail(*Q) == 0) {
            head(*Q) = 0;
        }
    }
}

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input e: character )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char e){
    // Kamus Lokal
    
    // Algoritma
    if (sizeQueue(*Q1) <= sizeQueue(*Q2)) {
        enqueue(Q1, e);
    } 
    else {
        enqueue(Q2, e);
    }
}

/*procedure dequeue2( input/output Q1:tQueue, input/output Q2:tQueue, output e: character )
{I.S.: -}
{F.S.: e=infohead Q1 atau Q2, e='-' bila Q1 dan Q2 kosong, elemen wadah Q1/Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, elemen di belakang head digeser }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *e){
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue(*Q1) && isEmptyQueue(*Q2)) {
        *e = '-';
    } 
    else if (sizeQueue(*Q1) >= sizeQueue(*Q2)) {
        dequeue(Q1, e);
    } 
    else {
        dequeue(Q2, e);
    }
}