#ifndef MAHASISWA_H
#define MAHASISWA_H
/* Program   : mahasiswa.h */
/* Deskripsi : Spesifikasi ADT Tunggal Mahasiswa yang menyimpan identitas, */
/*             komponen nilai, nilai akhir, dan nilai huruf mahasiswa.     */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus */
/* Tanggal   : 31 Agustus 2026 */

#include <stdio.h>
#include "boolean.h"

#define PANJANG_NAMA 50

typedef struct {
    long long nim;
    char nama[PANJANG_NAMA];
    float tugas;
    float kuis;
    float uts;
    float uas;
    float nilaiAkhir;
    char nilaiHuruf;
} Mahasiswa;

/* NOTASI ALGORITMIK:
   type Mahasiswa = <NIM:integer, nama:string, tugas:real,
                     kuis:real, UTS:real, UAS:real,
                     nilaiAkhir:real, nilaiHuruf:character>
   Nilai akhir = 40% tugas + 10% kuis + 25% UTS + 25% UAS.
   Konversi nilai: A untuk [80,100], B untuk [70,80),
   C untuk [60,70), D untuk [50,60), dan E untuk nilai < 50.
*/

/* ** KONSTRUKTOR ** */
/* procedure makeMahasiswa(output M:Mahasiswa, input nim:integer, nama:string, tugas, kuis, UTS, UAS:real) */
/* {I.S.: nim, nama, dan seluruh komponen nilai terdefinisi} */
/* {F.S.: M terdefinisi, nilai akhir dan nilai huruf telah dihitung} */
/* {proses: mengisi identitas dan komponen nilai M, lalu menghitung nilai} */
void makeMahasiswa(Mahasiswa *M, long long nim, const char *nama, float tugas, float kuis, float uts, float uas);

/* ** SELEKTOR ** */
/* function getNIM(input M:Mahasiswa)->integer */
/* {Mengembalikan NIM mahasiswa M} */
long long getNIM(Mahasiswa M);
/* function getNama(input M:Mahasiswa)->string */
/* {Mengembalikan nama mahasiswa M} */
const char *getNama(const Mahasiswa *M);
/* function getTugas(input M:Mahasiswa)->real */
/* {Mengembalikan nilai tugas M} */
float getTugas(Mahasiswa M);
/* function getKuis(input M:Mahasiswa)->real */
/* {Mengembalikan nilai kuis M} */
float getKuis(Mahasiswa M);
/* function getUTS(input M:Mahasiswa)->real */
/* {Mengembalikan nilai UTS M} */
float getUTS(Mahasiswa M);
/* function getUAS(input M:Mahasiswa)->real */
/* {Mengembalikan nilai UAS M} */
float getUAS(Mahasiswa M);
/* function getNilaiAkhir(input M:Mahasiswa)->real */
/* {Mengembalikan nilai akhir M} */
float getNilaiAkhir(Mahasiswa M);
/* function getNilaiHuruf(input M:Mahasiswa)->character */
/* {Mengembalikan nilai huruf M} */
char getNilaiHuruf(Mahasiswa M);

/* ** MUTATOR ** */
/* Setiap mutator: {I.S.: M terdefinisi} dan mengubah satu komponen M
   sesuai parameter masukan. {F.S.: komponen yang dipilih bernilai baru}. */
/* {proses: mengganti nilai komponen NIM M} */
void setNIM(Mahasiswa *M, long long nim);
/* {Mengubah nama mahasiswa M menjadi nama masukan} */
void setNama(Mahasiswa *M, const char *nama);
/* {Mengubah nilai tugas M menjadi nilai masukan} */
void setTugas(Mahasiswa *M, float nilai);
/* {Mengubah nilai kuis M menjadi nilai masukan} */
void setKuis(Mahasiswa *M, float nilai);
/* {Mengubah nilai UTS M menjadi nilai masukan} */
void setUTS(Mahasiswa *M, float nilai);
/* {Mengubah nilai UAS M menjadi nilai masukan} */
void setUAS(Mahasiswa *M, float nilai);

/* ** OPERASI PERHITUNGAN ** */
/* procedure hitungNilai(input/output M:Mahasiswa) */
/* {I.S.: M terdefinisi dan komponen tugas, kuis, UTS, UAS terisi} */
/* {F.S.: nilaiAkhir dan nilaiHuruf M terdefinisi sesuai bobot nilai} */
/* {proses: menghitung jumlah berbobot dan mengonversinya menjadi huruf} */
void hitungNilai(Mahasiswa *M);

/* function konversiNilai(input nilaiAkhir:real)->character */
/* {Mengembalikan nilai huruf berdasarkan rentang nilai akhir} */
char konversiNilai(float nilaiAkhir);

/* ** KELOMPOK INTERAKSI DENGAN I/O DEVICE ** */
/* procedure bacaMahasiswa(output M:Mahasiswa) */
/* {F.S.: data mahasiswa dibaca dari keyboard dan nilai dihitung} */
void bacaMahasiswa(Mahasiswa *M);

/* procedure tulisMahasiswa(input M:Mahasiswa) */
/* {I.S.: M terdefinisi} */
/* {F.S.: seluruh data M ditampilkan ke layar} */
void tulisMahasiswa(Mahasiswa M);

#endif
