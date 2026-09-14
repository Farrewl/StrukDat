/************************************/
/* Program   : garis.c */
/* Deskripsi : realisasi modul Garis */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus*/
/* Tanggal   : 24 Agustus 2026*/
/***********************************/

#include <stdio.h>
#include <math.h>
#include "garis.h"

#define PI 3.14159265358979323846

void makeGaris(Titik P1, Titik P2, Garis *L) {
    L->PAw = P1;
    L->PAkh = P2;
}

Titik getPAw(Garis G) {
    return G.PAw;
}

Titik getPAkh(Garis G) {
    return G.PAkh;
}

void setPAw(Garis *G, Titik newPAw) {
    G->PAw = newPAw;
}

void setPAkh(Garis *G, Titik newPAkh) {
    G->PAkh = newPAkh;
}

void bacaGaris(Garis *L) {
    Titik P1, P2;
    int x, y;
    do {
        printf("Titik Awal (x y): ");
        scanf("%d %d", &x, &y);
        makeTitik(&P1, x, y);
        
        printf("Titik Akhir (x y): ");
        scanf("%d %d", &x, &y);
        makeTitik(&P2, x, y);
        
        if (isEqual(P1, P2)) {
            printf("Titik awal dan akhir tidak boleh sama!\n");
        }
    } 
    while (isEqual(P1, P2));
    
    makeGaris(P1, P2, L);
}

void tulisGaris(Garis L) {
    printf("((%d,%d) , (%d,%d))", getAbsis(L.PAw), getOrdinat(L.PAw), getAbsis(L.PAkh), getOrdinat(L.PAkh));
}

boolean EQ(Garis L1, Garis L2) {
    return isEqual(L1.PAw, L2.PAw) && isEqual(L1.PAkh, L2.PAkh);
}

boolean NEQ(Garis L1, Garis L2) {
    return !EQ(L1, L2);
}

boolean isOnSbX(Garis L) {
    return isOnSumbuX(L.PAw) && isOnSumbuX(L.PAkh);
}

boolean isOnSbY(Garis L) {
    return isOnSumbuY(L.PAw) && isOnSumbuY(L.PAkh);
}

boolean isTegakLurus(Garis L, Garis L1) {
    int dx1 = getAbsis(L.PAkh) - getAbsis(L.PAw);
    int dy1 = getOrdinat(L.PAkh) - getOrdinat(L.PAw);
    int dx2 = getAbsis(L1.PAkh) - getAbsis(L1.PAw);
    int dy2 = getOrdinat(L1.PAkh) - getOrdinat(L1.PAw);
    
    return (dy1 * dy2) + (dx1 * dx2) == 0;
}

boolean isSejajar(Garis L, Garis L1) {
    int dx1 = getAbsis(L.PAkh) - getAbsis(L.PAw);
    int dy1 = getOrdinat(L.PAkh) - getOrdinat(L.PAw);
    int dx2 = getAbsis(L1.PAkh) - getAbsis(L1.PAw);
    int dy2 = getOrdinat(L1.PAkh) - getOrdinat(L1.PAw);

    return (dy1 * dx2) == (dy2 * dx1);
}

void makeGaris0(Garis *L) {
    Titik P1, P2;
    makeTitik0(&P1);
    makeTitik(&P2, 1, 1);
    makeGaris(P1, P2, L);
}

float gradien(Garis L) {
    float dx = getAbsis(L.PAkh) - getAbsis(L.PAw);
    float dy = getOrdinat(L.PAkh) - getOrdinat(L.PAw);
    if (dx == 0) {
        if (dy == 0) 
            return 0;
        else 
            return (dy > 0) ? 10000 : -10000;
    }
    return dy / dx;
}

void persamaanGaris(Garis L) {
    float m = gradien(L);
    float c;
    if (getAbsis(L.PAw) == 0) {
        c = getOrdinat(L.PAw);
    } 
    else {
        c = getOrdinat(L.PAw) - m * getAbsis(L.PAw);
    }
    printf("y = %.2fx + %.2f", m, c);
}

boolean isHorizontal(Garis L) {
    return getOrdinat(L.PAw) == getOrdinat(L.PAkh);
}

Garis hslGeser(Garis L, int DX, int DY) {
    Garis G_baru;
    Titik P1 = getPAw(L);
    Titik P2 = getPAkh(L);
    
    geser(&P1, DX, DY);
    geser(&P2, DX, DY);
    
    makeGaris(P1, P2, &G_baru);
    return G_baru;
}

Garis mirrorOf(Garis L, boolean SbX, boolean SbY) {
    Garis G_baru = L;
    mirrorGaris(&G_baru, SbX, SbY);
    return G_baru;
}

float panjang(Garis L) {
    int dx = getAbsis(L.PAkh) - getAbsis(L.PAw);
    int dy = getOrdinat(L.PAkh) - getOrdinat(L.PAw);
    return sqrt((dx * dx) + (dy * dy));
}

float arah(Garis L) {
    int dx = getAbsis(L.PAkh) - getAbsis(L.PAw);
    int dy = getOrdinat(L.PAkh) - getOrdinat(L.PAw);
    return atan2(dy, dx) * 180.0 / PI;
}

float sudutGaris(Garis L, Garis L1) {
    float selisih = fabs(arah(L) - arah(L1));
    if (selisih > 180.0) {
        selisih = 360.0 - selisih;
    }
    return selisih;
}

void geserGaris(Garis *L, int DeltaX, int DeltaY) {
    geser(&(L->PAw), DeltaX, DeltaY);
    geser(&(L->PAkh), DeltaX, DeltaY);
}

void mirrorGaris(Garis *L, boolean SbX, boolean SbY) {
    if (SbX) {
        refleksiX(&(L->PAw));
        refleksiX(&(L->PAkh));
    }
    if (SbY) {
        refleksiY(&(L->PAw));
        refleksiY(&(L->PAkh));
    }
}

void putarGaris(Garis *L, float Sudut) {
    float rad = Sudut * PI / 180.0;
    
    float x1 = getAbsis(L->PAw);
    float y1 = getOrdinat(L->PAw);
    setAbsis(&(L->PAw), round(x1 * cos(rad) - y1 * sin(rad)));
    setOrdinat(&(L->PAw), round(x1 * sin(rad) + y1 * cos(rad)));
    
    float x2 = getAbsis(L->PAkh);
    float y2 = getOrdinat(L->PAkh);
    setAbsis(&(L->PAkh), round(x2 * cos(rad) - y2 * sin(rad)));
    setOrdinat(&(L->PAkh), round(x2 * sin(rad) + y2 * cos(rad)));
}