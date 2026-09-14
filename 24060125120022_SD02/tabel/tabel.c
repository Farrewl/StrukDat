#ifndef TABEL_C
#define TABEL_C
/* Program   : tabel.c */
/* Deskripsi : realisasi modul ADT Koleksi Mahasiswa */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus */
/* Tanggal   : 31 Agustus 2026 */

#include "tabel.h"

void makeTable(Tabel *T) {
    T->size = 0; 
}
int getSize(Tabel T) { 
    return T.size; 
}
int getMaxSize(Tabel T) { 
    (void) T; 
    return KAPASITAS_TABEL; 
}
int getMinSize(Tabel T) { 
    (void) T; 
    return 0; 
}
boolean isEmptyTable(Tabel T) { 
    return T.size == 0; 
}
boolean isFullTable(Tabel T) { 
    return T.size == KAPASITAS_TABEL; 
}

void addMahasiswa(Tabel *T, Mahasiswa M) {
    if (!isFullTable(*T)) T->wadah[T->size++] = M;
}

void printTable(Tabel T) {
    int i;
    printf("%-12s %-20s %6s %6s %6s %6s %8s %5s\n",
           "NIM", "Nama", "Tugas", "Kuis", "UTS", "UAS", "Akhir", "Huruf");
    for (i = 0; i < T.size; i++) tulisMahasiswa(T.wadah[i]);
}

void populateTable(Tabel *T, int N) {
    int i;
    for (i = 0; i < N && !isFullTable(*T); i++) {
        Mahasiswa M;
        printf("\nData mahasiswa ke-%d\n", i + 1);
        bacaMahasiswa(&M);
        addMahasiswa(T, M);
    }
}

int jumlahLulus(Tabel T) {
    int i, jumlah = 0;
    for (i = 0; i < T.size; i++)
        if (getNilaiHuruf(T.wadah[i]) == 'A' ||
            getNilaiHuruf(T.wadah[i]) == 'B' ||
            getNilaiHuruf(T.wadah[i]) == 'C') jumlah++;
    return jumlah;
}

Mahasiswa getMahasiswaTertinggi(Tabel T) {
    int i, posisi = 0;
    if (isEmptyTable(T)) {
        Mahasiswa kosong = {0};
        return kosong;
    }
    for (i = 1; i < T.size; i++)
        if (getNilaiAkhir(T.wadah[i]) > getNilaiAkhir(T.wadah[posisi])) posisi = i;
    return T.wadah[posisi];
}

float averageNilaiAkhir(Tabel T) {
    int i;
    float total = 0.0f;
    if (isEmptyTable(T)) return 0.0f;
    for (i = 0; i < T.size; i++) total += getNilaiAkhir(T.wadah[i]);
    return total / T.size;
}

int jumlahNilaiHuruf(Tabel T, char huruf) {
    int i, jumlah = 0;
    for (i = 0; i < T.size; i++) {
        if (getNilaiHuruf(T.wadah[i]) == huruf) jumlah++;
    }
    return jumlah;
}

int cariNIM(Tabel T, long long nim) {
    int i;
    for (i = 0; i < T.size; i++) {
        if (getNIM(T.wadah[i]) == nim) return i;
    }
    return -1;
}

void tampilLulus(Tabel T) {
    int i;
    for (i = 0; i < T.size; i++) {
        if (getNilaiHuruf(T.wadah[i]) == 'A' ||
            getNilaiHuruf(T.wadah[i]) == 'B' ||
            getNilaiHuruf(T.wadah[i]) == 'C') {
            tulisMahasiswa(T.wadah[i]);
        }
    }
}

void tampilTidakLulus(Tabel T) {
    int i;
    for (i = 0; i < T.size; i++) {
        if (getNilaiHuruf(T.wadah[i]) == 'D' ||
            getNilaiHuruf(T.wadah[i]) == 'E') {
            tulisMahasiswa(T.wadah[i]);
        }
    }
}

#endif
