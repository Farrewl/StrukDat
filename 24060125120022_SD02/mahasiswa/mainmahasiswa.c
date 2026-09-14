/************************************/
/* Program   : mainmahasiswa.c */
/* Deskripsi : driver pengujian ADT Mahasiswa */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus */
/* Tanggal   : 31 Agustus 2026 */
/***********************************/

#include <stdio.h>
#include "mahasiswa.h"

int main(void) {
    Mahasiswa M;
    makeMahasiswa(&M, 224243, "Dini", 90, 83, 85, 90);
    printf("Nilai mahasiswa:\n");
    tulisMahasiswa(M);
    setUAS(&M, 95);
    printf("Setelah nilai UAS diubah:\n");
    tulisMahasiswa(M);
    return 0;
}
