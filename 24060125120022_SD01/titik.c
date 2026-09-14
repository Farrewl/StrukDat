/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus*/
/* Tanggal   : 24 Agustus 2026*/
/***********************************/
#include <stdio.h>
#include "titik.h"

void makeTitik(Titik *T, int x, int y) {
    T->absis = x;
    T->ordinat = y;
}

void makeTitik0(Titik *T) {
    T->absis = 0;
    T->ordinat = 0;
}

int getAbsis(Titik T) {
    return T.absis;
}

int getOrdinat(Titik T) {
    return T.ordinat;
}

void setAbsis(Titik *T, int x) {
    T->absis = x;
}

void setOrdinat(Titik *T, int y) {
    T->ordinat = y;
}

boolean isOrigin(Titik T) {
    return T.absis == 0 && T.ordinat == 0;
}

boolean isOnSumbuX(Titik T) {
    return T.ordinat == 0;
}

boolean isOnSumbuY(Titik T) {
    return T.absis == 0;
}

boolean isEqual(Titik T1, Titik T2) {
    return T1.absis == T2.absis && T1.ordinat == T2.ordinat;
}

void geser(Titik *T, int x, int y) {
    T->absis = T->absis + x;
    T->ordinat = T->ordinat + y;
}

void refleksiX(Titik *T) {
    T->ordinat = -(T->ordinat);
}

void refleksiY(Titik *T) {
    T->absis = -(T->absis);
}

void dilatasi(Titik *T, float k) {
    T->absis = T->absis * k;
    T->ordinat = T->ordinat * k;
}

void dilatasiX(Titik *T, Titik X, float k) {
    T->absis = X.absis + k * (T->absis - X.absis);
    T->ordinat = X.ordinat + k * (T->ordinat - X.ordinat);
}

int kuadran(Titik T) {
    if (T.absis > 0 && T.ordinat > 0)
        return 1;
    else if (T.absis < 0 && T.ordinat > 0)
        return 2;
    else if (T.absis < 0 && T.ordinat < 0)
        return 3;
    else
        return 4;
}
