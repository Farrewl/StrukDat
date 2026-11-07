/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait sirkular */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus */
/* Tanggal : 02 November 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

void printChar(char c) {
    printf("%c", c);
}

int main()
{
    List2 L;
    address A;
    
    
    /* 1. Buat list kosong */
    CreateList(&L);
    printf("List setelah CreateList: ");
    PrintList(L);
    printf("\nIsEmptyList: %s\n", IsEmptyList(L) ? "true" : "false");
    
    /* 2. Insert elemen pertama */
    InsertVFirst(&L, 'A');
    printf("List setelah InsertVFirst('A'): ");
    printf("\n");
    PrintList(L);
    printf("\nIsEmptyList: %s\n", IsEmptyList(L) ? "true" : "false");
    printf("IsOneElm: %s\n", IsOneElm(L) ? "true" : "false");
    printf("NbElm: %d\n", NbElm(L));
    
    /* 3. Insert elemen terakhir */
    InsertVLast(&L, 'C');
    printf("List setelah InsertVLast('C'): ");
    printf("\n");
    PrintList(L);
    printf("\nNbElm: %d\n", NbElm(L));
    
    /* 4. Insert elemen di tengah */
    InsertVFirst(&L, 'B');
    printf("List setelah InsertVFirst('B'): ");
    printf("\n");
    PrintList(L);
    printf("\nNbElm: %d\n", NbElm(L));
    
    /* 5. Uji SearchX */
    SearchX(L, 'B', &A);
    if (A != NIL) {
        printf("SearchX('B') ditemukan: %c\n", info(A));
    } else {
        printf("SearchX('B') tidak ditemukan\n");
    }
    
    SearchX(L, 'Z', &A);
    if (A != NIL) {
        printf("SearchX('Z') ditemukan: %c\n", info(A));
    } else {
        printf("SearchX('Z') tidak ditemukan\n");
    }
    
    /* 6. Uji UpdateX */
    UpdateX(&L, 'C', 'D');
    printf("List setelah UpdateX('C', 'D'): \n");
    PrintList(L);
    printf("\n");
    
    /* 7. Uji Invers */
    Invers(&L);
    printf("List setelah Invers: \n");
    PrintList(L);
    printf("\n");
    
    /* 8. Uji penghapusan */
    infotype V;
    DeleteVFirst(&L, &V);
    printf("List setelah DeleteVFirst (Dihapus: %c): \n", V);
    PrintList(L);
    printf("\n");
    
    DeleteVLast(&L, &V);
    printf("List setelah DeleteVLast (Dihapus: %c): \n", V);
    PrintList(L);
    printf("\n");
    
    /* 9. Uji CountX */
    int countA = CountX(L, 'A');
    printf("CountX(L, 'A'): %d\n", countA);
    
    return 0;
}