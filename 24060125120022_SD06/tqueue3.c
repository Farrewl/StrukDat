/* Program   : tqueue3.c */
/* Deskripsi : file BODY modul tabel queue 3 */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 28 September 2026 */
/***********************************/ 
#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    return (Q.head == 0) && (Q.tail == 0);
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    return sizeQueue3(Q) == 5;
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    return (Q.head != 0) && (Q.head == Q.tail);
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q){
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 1; i <= 5; i++) {
        Q->wadah[i] = '#';
    }
    Q->head = 0;
    Q->tail = 0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue3(Q)) {
        return '#';
    } 
    else {
        return Q.wadah[Q.head];
    }
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue3(Q)) {
        return '#';
    } 
    else {
        return Q.wadah[Q.tail];
    }
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue3(Q)) {
        return 0;
    } 
    else if (Q.tail >= Q.head) {
        return Q.tail - Q.head + 1;
    } 
    else {
        return (5 - Q.head + 1) + Q.tail;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q){
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 1; i <= 5; i++) {
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    // Kamus Lokal
    int i;

    // Algoritma
    if (isEmptyQueue3(Q)) {
        printf("-\n");
    } 
    else {
        for (i = 0; i < sizeQueue3(Q); i++) {
            printf("%c ", Q.wadah[Q.head]);
            if (Q.head == 5) {
                Q.head = 1;
            } 
            else {
                Q.head = Q.head + 1;
            }
        }
        printf("\n");
    }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E){
    // Kamus Lokal

    // Algoritma
    if (isFullQueue3(*Q)) {
        return;
    }
    if (isEmptyQueue3(*Q)) {
        Q->head = 1;
        Q->tail = 1;
    } 
    else {
        if (Q->tail == 5) {
            Q->tail = 1;
        } 
        else {
            Q->tail = Q->tail + 1;
        }
    }
    Q->wadah[Q->tail] = E;
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue3(*Q)) {
        *E = ' ';
    } 
    else {
        *E = Q->wadah[Q->head];

        if (isOneElement3(*Q)) {
            Q->wadah[Q->head] = '#';
            Q->head = 0;
            Q->tail = 0;
        } 
        else {
            Q->wadah[Q->head] = '#';
            if (Q->head == 5) {
                Q->head = 1;
            } 
            else {
                Q->head = Q->head + 1;
            }
        }
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q){
    // Kamus Lokal

    // Algoritma
    return Q.tail < Q.head;
}
