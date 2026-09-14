/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 14 September 2026 */
/***********************************/ 
#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    for(int i = 0; i < 11; i++){
        T->wadah[i]='#';
    }
    T->top=0;
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    if (!isFullStack(*T)) {
        T->top = T->top + 1;
        T->wadah[T->top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    if (!isEmptyStack(*T)) {
        *X = T->wadah[T->top];
        T->wadah[T->top] = '#';
        T->top = T->top - 1;
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    for (int i = 1; i <= 10; i++) {
        printf("%c", T.wadah[i]);
        if (i < 10) {
            printf(";");
        }
    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    if (!isEmptyStack(T)) {
        for (int i = 0; i <= T.top; i++) {
            printf("%c", T.wadah[i]);
            if (i > 1) {
                printf(";");
            }
        }
        printf("\n");
    }
    else {
        printf("Stack kosong\n");
    }
}

/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30]){
    Tstack T;
    int i, panjang = 0;
    boolean sama = true;
    char X;

    while (kata[panjang] != '\0') {
        panjang++;
    }

    createStack(&T);
    for (i = 0; i < panjang; i++) {
        push(&T, kata[i]);
    }

    for (i = 0; i < panjang; i++) {
        pop(&T, &X);
        if (kata[i] != X) {
            sama = false;
        }
    }

    return sama;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    char E;
    for (int i = 1; i <= N; i++) {
        if (!isFullStack(*T)) {
            printf("Masukkan karakter: ");
            scanf(" %c", &E);
            push(T, E);
        } else {
            printf("Stack penuh\n");
        }
    }
}
