/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait ganda */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus */
/* Tanggal : 9 November 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

int main()
{
    List3 L;
    CreateList(&L);
    
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'C');
    InsertVLast(&L, 'D');
    
    printf("List L: ");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));
    
    return 0;
}
