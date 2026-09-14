/************************************/
/* Program   : mgaris.c */
/* Deskripsi : aplikasi driver modul Garis */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus*/
/* Tanggal   : 24 Agustus 2026*/
/* Note      : Mendemonstrasikan seluruh fungsi pada garis.h/garis.c */
/***********************************/

#include <stdio.h>
#include "titik.h"
#include "garis.h"

int main() {
    /* Kamus Main */
    Titik T1, T2;
    Garis G1, G2, G3, G4;

    makeGaris0(&G1);
    printf("G1   : "); tulisGaris(G1); printf("\n");

    makeTitik(&T1, 0, 4);
    makeTitik(&T2, 4, 0);
    makeGaris(T1, T2, &G2);
    printf("G2   : "); tulisGaris(G2); printf("\n");

    T1 = getPAw(G1);
    T2 = getPAkh(G1);
    printf("PAw G1  : (%d,%d)\n", getAbsis(T1), getOrdinat(T1));
    printf("PAkh G1 : (%d,%d)\n", getAbsis(T2), getOrdinat(T2));

    makeTitik(&T1, 2, 3);
    makeTitik(&T2, 5, 3);
    setPAw(&G1, T1);
    setPAkh(&G1, T2);
    printf("G1 setelah set   : "); tulisGaris(G1); printf("\n");

    printf("Panjang G1      : %.2f\n", panjang(G1));
    printf("Arah G1         : %.2f derajat\n", arah(G1));
    printf("Gradien G1      : %.2f\n", gradien(G1));
    printf("Persamaan G1    : "); persamaanGaris(G1); printf("\n");

    printf("isHorizontal G1 : %s\n", isHorizontal(G1) ? "true" : "false");
    printf("isOnSbX G1      : %s\n", isOnSbX(G1) ? "true" : "false");
    printf("isOnSbY G1      : %s\n", isOnSbY(G1) ? "true" : "false");

    makeGaris0(&G3);                          
    makeTitik(&T1, 0, 0);
    makeTitik(&T2, 2, 2);
    makeGaris(T1, T2, &G4);                  
    printf("G3   : "); tulisGaris(G3); printf("\n");
    printf("G4   : "); tulisGaris(G4); printf("\n");
    printf("EQ(G3,G4)          : %s\n", EQ(G3, G4) ? "true" : "false");
    printf("NEQ(G3,G4)         : %s\n", NEQ(G3, G4) ? "true" : "false");
    printf("isTegakLurus(G1,G4): %s\n", isTegakLurus(G1, G4) ? "true" : "false");
    printf("isSejajar(G3,G4)   : %s\n", isSejajar(G3, G4) ? "true" : "false");
    printf("Sudut G1 vs G2     : %.2f derajat\n", sudutGaris(G1, G2));

    printf("G1 sebelum geser  : "); tulisGaris(G1); printf("\n");
    geserGaris(&G1, 2, -1);
    printf("G1 setelah geser  : "); tulisGaris(G1); printf("\n");
    printf("G2 (salinan)      : "); tulisGaris(G2); printf("\n");
    printf("G2 hasil geser    : "); tulisGaris(hslGeser(G2, 3, 3)); printf("\n");

    printf("G2 mirrorOf SbX   : "); tulisGaris(mirrorOf(G2, true, false)); printf("\n");
    printf("G2 mirrorGaris SbY: "); tulisGaris(mirrorOf(mirrorOf(G2, true, false), false, true)); printf("\n");

    printf("G2 sebelum putar  : "); tulisGaris(G2); printf("\n");
    putarGaris(&G2, 90.0);
    printf("G2 setelah putar  : "); tulisGaris(G2); printf("\n");

    printf("\nBaca garis baru:\n");
    bacaGaris(&G3);
    printf("G3          : "); tulisGaris(G3); printf("\n");
    printf("Panjang G3  : %.2f\n", panjang(G3));

    return 0;
}
