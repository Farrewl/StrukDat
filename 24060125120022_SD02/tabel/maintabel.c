/************************************/
/* Program   : maintabel.c */
/* Deskripsi : driver pengujian ADT Koleksi Mahasiswa */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus */
/* Tanggal   : 31 Agustus 2026 */
/***********************************/

#include <stdio.h>
#include "tabel.h"

int main(void) {
    Tabel T;
    Mahasiswa M, tertinggi;
    int posisi;
    char huruf;
    long long nim;

    // Konstruktor
    makeTable(&T);
    makeMahasiswa(&M, 224243, "Dini", 90, 83, 85, 90);
    addMahasiswa(&T, M);
    makeMahasiswa(&M, 224241, "Doni", 87, 90, 92, 93);
    addMahasiswa(&T, M);
    makeMahasiswa(&M, 224240, "Raka", 55, 60, 50, 48);
    addMahasiswa(&T, M);
    makeMahasiswa(&M, 224242, "Rizki Kebab", 100, 67, 67, 100);
    addMahasiswa(&T, M);

    // Selektor
    printf("Ukuran maksimum: %d\n", getMaxSize(T));
    printf("Ukuran minimum: %d\n", getMinSize(T));

    // Predikat
    printf("Tabel kosong: %s\n", isEmptyTable(T) ? "true" : "false");
    printf("Tabel penuh: %s\n", isFullTable(T) ? "true" : "false");

    // Tabel
    printf("\n");
    printTable(T);

    printf("\n=== Operasi ===\n");
    printf("Jumlah mahasiswa lulus: %d\n", jumlahLulus(T));

    tertinggi = getMahasiswaTertinggi(T);
    printf("Mahasiswa dengan nilai tertinggi:\n");
    tulisMahasiswa(tertinggi);

    printf("\nMasukkan nilai huruf yang ingin dihitung (A-E): ");
    scanf(" %c", &huruf);
    printf("Jumlah mahasiswa dengan nilai %c: %d\n", huruf, jumlahNilaiHuruf(T, huruf));

    printf("\nMasukkan NIM yang ingin dicari: ");
    scanf("%lld", &nim);
    posisi = cariNIM(T, nim);
    if (posisi == -1) {
        printf("Mahasiswa dengan NIM %lld tidak ditemukan.\n", nim);
    } else {
        printf("Data mahasiswa ditemukan:\n");
        tulisMahasiswa(T.wadah[posisi]);
    }

    printf("\nRata-rata nilai akhir: %.2f\n", averageNilaiAkhir(T));

    printf("\nMahasiswa yang lulus:\n");
    tampilLulus(T);

    printf("\nMahasiswa yang tidak lulus:\n");
    tampilTidakLulus(T);

    return 0;
}
