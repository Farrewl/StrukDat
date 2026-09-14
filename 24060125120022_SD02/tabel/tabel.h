#ifndef TABEL_H
#define TABEL_H
/* Program   : tabel.h */
/* Deskripsi : Spesifikasi ADT Koleksi untuk menyimpan dan mengolah       */
/*             kumpulan data mahasiswa dalam tabel berukuran tetap.      */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus */
/* Tanggal   : 31 Agustus 2026 */

#include <stdio.h>
#include "../mahasiswa/boolean.h"
#include "../mahasiswa/mahasiswa.h"

#define KAPASITAS_TABEL 100

/* NOTASI ALGORITMIK:
   type Tabel = <wadah:array[1..KAPASITAS_TABEL] of Mahasiswa,
				 size:integer>
   Tabel menyimpan elemen pada indeks 0 sampai size-1.
*/
typedef struct {
    Mahasiswa wadah[KAPASITAS_TABEL];
    int size;
} Tabel;


/* ** KONSTRUKTOR ** */
/* procedure makeTable(output T:Tabel) */
/* {I.S.: T belum terdefinisi} */
/* {F.S.: T terdefinisi sebagai tabel kosong dengan size = 0} */
/* {proses: menginisialisasi ukuran tabel menjadi nol} */
void makeTable(Tabel *T);

/* ** SELEKTOR ** */
/* function getSize(input T:Tabel)->integer */
/* {Mengembalikan banyak elemen yang tersimpan di dalam T} */
int getSize(Tabel T);

/* function getMaxSize(input T:Tabel)->integer */
/* {Mengembalikan kapasitas maksimum tabel T} */
int getMaxSize(Tabel T);

/* function getMinSize(input T:Tabel)->integer */
/* {Mengembalikan ukuran minimum tabel, yaitu nol} */
int getMinSize(Tabel T);

/* ** PREDIKAT ** */
/* function isEmptyTable(input T:Tabel)->boolean */
/* {Menghasilkan true jika size T sama dengan nol} */
boolean isEmptyTable(Tabel T);
/* function isFullTable(input T:Tabel)->boolean */
/* {Menghasilkan true jika size T sama dengan KAPASITAS_TABEL} */
boolean isFullTable(Tabel T);

/* ** OPERASI DASAR ** */
/* procedure addMahasiswa(input/output T:Tabel, input M:Mahasiswa) */
/* {I.S.: T terdefinisi dan belum penuh} */
/* {F.S.: M menjadi elemen terakhir T dan size bertambah satu} */
/* {proses: menambahkan M ke wadah pada posisi size saat ini} */
void addMahasiswa(Tabel *T, Mahasiswa M);

/* procedure printTable(input T:Tabel) */
/* {I.S.: T terdefinisi} */
/* {F.S.: seluruh elemen T ditampilkan ke layar} */
void printTable(Tabel T);

/* procedure populateTable(input/output T:Tabel, input N:integer) */
/* {I.S.: T terdefinisi dan N berada pada rentang kapasitas tabel} */
/* {F.S.: T berisi N data mahasiswa yang dibaca dari masukan} */
/* {proses: membaca dan menambahkan data mahasiswa sebanyak N elemen} */
void tambahTable(Tabel *T, int N);

/* ** OPERASI PENGOLAHAN KOLEKSI ** */
/* function jumlahLulus(input T:Tabel)->integer */
/* {Mengembalikan jumlah mahasiswa dengan nilai huruf minimal C} */
int jumlahLulus(Tabel T);

/* function getMahasiswaTertinggi(input T:Tabel)->Mahasiswa */
/* {Mengembalikan mahasiswa dengan nilai akhir paling tinggi} */
Mahasiswa getMahasiswaTertinggi(Tabel T);

/* function averageNilaiAkhir(input T:Tabel)->real */
/* {Mengembalikan rata-rata nilai akhir seluruh mahasiswa dalam T} */
/* {Jika T kosong, hasil yang dikembalikan adalah 0} */
float averageNilaiAkhir(Tabel T);

/* function jumlahNilaiHuruf(input T:Tabel, input huruf:character)->integer */
/* {Mengembalikan jumlah mahasiswa dengan nilai huruf yang dicari} */
int jumlahNilaiHuruf(Tabel T, char huruf);

/* function cariNIM(input T:Tabel, input nim:integer)->integer */
/* {Mengembalikan posisi mahasiswa dengan NIM yang dicari} */
/* {Jika tidak ditemukan, hasilnya -1} */
int cariNIM(Tabel T, long long nim);

/* procedure tampilLulus(input T:Tabel) */
/* {Menampilkan semua mahasiswa yang mendapat nilai minimal C} */
void tampilLulus(Tabel T);

/* procedure tampilTidakLulus(input T:Tabel) */
/* {Menampilkan semua mahasiswa yang mendapat nilai D atau E} */
void tampilTidakLulus(Tabel T);

#endif
