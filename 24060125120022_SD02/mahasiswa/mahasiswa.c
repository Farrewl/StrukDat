#ifndef MAHASISWA_C
#define MAHASISWA_C
/* Program   : mahasiswa.c */
/* Deskripsi : realisasi modul ADT Mahasiswa */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus */
/* Tanggal   : 31 Agustus 2026 */

#include "mahasiswa.h"
#include <string.h>

void makeMahasiswa(Mahasiswa *M, long long nim, const char *nama, float tugas, float kuis, float uts, float uas) {
    M->nim = nim;
    setNama(M, nama);
    M->tugas = tugas;
    M->kuis = kuis;
    M->uts = uts;
    M->uas = uas;
    hitungNilai(M);
}

long long getNIM(Mahasiswa M) { 
    return M.nim; }
const char *getNama(const Mahasiswa *M) { 
    return M->nama; }
float getTugas(Mahasiswa M) { 
    return M.tugas; }
float getKuis(Mahasiswa M) { 
    return M.kuis; }
float getUTS(Mahasiswa M) { 
    return M.uts; }
float getUAS(Mahasiswa M) { 
    return M.uas; }
float getNilaiAkhir(Mahasiswa M) { 
    return M.nilaiAkhir; }
char getNilaiHuruf(Mahasiswa M) { 
    return M.nilaiHuruf; }

void setNIM(Mahasiswa *M, long long nim) { 
    M->nim = nim; }

void setNama(Mahasiswa *M, const char *nama) {
    strncpy(M->nama, nama, PANJANG_NAMA - 1);
    M->nama[PANJANG_NAMA - 1] = '\0';
}

void setTugas(Mahasiswa *M, float nilai) { 
    M->tugas = nilai; hitungNilai(M); }
void setKuis(Mahasiswa *M, float nilai) { 
    M->kuis = nilai; hitungNilai(M); }
void setUTS(Mahasiswa *M, float nilai) { 
    M->uts = nilai; hitungNilai(M); }
void setUAS(Mahasiswa *M, float nilai) { 
    M->uas = nilai; hitungNilai(M); }

char konversiNilai(float nilaiAkhir) {
    if (nilaiAkhir >= 80.0f) return 'A';
    if (nilaiAkhir >= 70.0f) return 'B';
    if (nilaiAkhir >= 60.0f) return 'C';
    if (nilaiAkhir >= 50.0f) return 'D';
    return 'E';
}

void hitungNilai(Mahasiswa *M) {
    M->nilaiAkhir = M->tugas * 0.40f + M->kuis * 0.10f + M->uts * 0.25f + M->uas * 0.25f;
    M->nilaiHuruf = konversiNilai(M->nilaiAkhir);
}

void bacaMahasiswa(Mahasiswa *M) {
    char nama[PANJANG_NAMA];
    printf("NIM: "); 
    scanf("%lld", &M->nim);
    printf("Nama: "); 
    scanf(" %49[^\n]", nama);
    printf("Nilai tugas, kuis, UTS, UAS: ");
    scanf("%f %f %f %f", &M->tugas, &M->kuis, &M->uts, &M->uas);
    setNama(M, nama);
    hitungNilai(M);
}

void tulisMahasiswa(Mahasiswa M) {
    printf("%-12lld %-20s %6.2f %6.2f %6.2f %6.2f %8.2f %5c\n",
           M.nim, M.nama, M.tugas, M.kuis, M.uts, M.uas,
           M.nilaiAkhir, M.nilaiHuruf);
}

#endif
