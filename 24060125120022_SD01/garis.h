#ifndef garis_H
#define garis_H
/************************************/
/* Program   : garis.h */
/* Deskripsi : header file modul Garis */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus*/
/* Tanggal   : 24 Agustus 2026*/
/***********************************/
#include "titik.h"

/* NOTASI ALGORITMIK : */
/* type Garis=<PAw:Titik, PAkh:Titik> */
typedef struct {Titik PAw; Titik PAkh;} Garis;

/* ** KONSTRUKTOR ** */
/* procedure MakeGARIS (Input P1,P2:POINT, Output L:GARIS) */
/* {I.S. P1 dan P2 terdefinisi, P1 != P2} */
/* {F.S. L terdefinisi dengan L.PAw= P1 dan L.Pakh=P2 } */
/* {Membentuk sebuah L dari komponen-komponennya} */
void makeGaris(Titik P1, Titik P2, Garis *L);

/* ** SELEKTOR ** */
/* function GetPAw(G:GARIS) -> POINT */
/* {Mengirimkan komponen Titik pertama dari L Garis} */
Titik getPAw(Garis G);

/* function GetPAkh(G:GARIS) -> POINT */
/* {Mengirimkan komponen Titik kedua dari L Garis} */
Titik getPAkh(Garis G);

/* ** Set nilai komponen ** */
/* procedure SetPAw(Input/Output G:GARIS, Input newPAw : POINT) */
/* {Mengubah nilai komponen PAw dari G} */
void setPAw(Garis *G, Titik newPAw);

/* procedure SetPAkh(Input/Output G:GARIS, Input newPAkh : POINT) */
/* {Mengubah nilai komponen PAkh dari G}*/
void setPAkh(Garis *G, Titik newPAkh);

/* ** Kelompok Interaksi dengan I/O device, BACA/TULIS ** */
/* procedure BacaGARIS (Output L: GARIS) */
/* {F.S. mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat membentuk GARIS yang valid (P1 != P2)} */
void bacaGaris(Garis *L);

/* procedure TulisGARIS (Input L: GARIS) */
/* {Nilai L ditulis ke layar dengan format ((x1,y1) , (x2,y2))} */
void tulisGaris(Garis L);

/* ** Kelompok operasi relasional terhadap GARIS ** */
/* function EQ(L1,L2: GARIS) -> boolean */
/* {Mengirimkan true jika L1 = L2 (PAw dan PAkh sama)} */
boolean EQ(Garis L1, Garis L2);

/* function NEQ(L1,L2: GARIS) -> boolean */
/* {Mengirimkan true jika L1 tidak sama dengan L2} */
boolean NEQ(Garis L1, Garis L2);

/* ** Kelompok menentukan di mana L berada ** */
/* function IsOnSbX (L:GARIS) -> boolean */
/* {Menghasilkan true jika L terletak Pada sumbu X} */
boolean isOnSbX(Garis L);

/* function IsOnSbY (L:GARIS) -> boolean */
/* {Menghasilkan true jika L terletak pada sumbu Y} */
boolean isOnSbY(Garis L);

/* ** Kelompok predikat lain ** */
/* function IsTegakLurus (L, L1: GARIS) -> boolean */
/* {Menghasilkan true jika L tegak lurus terhadap L1} */
boolean isTegakLurus(Garis L, Garis L1);

/* function IsSejajar (L, L1: GARIS) -> boolean */
/* {Menghasilkan true jika L "sejajar" terhadap L1} */
boolean isSejajar(Garis L, Garis L1);

/* procedure makeGaris0 (Output L:GARIS) */
/* {I.S.: -} */
/* {F.S.: L terdefinisi dengan PAw=(0,0) dan PAkh=(1,1)} */
/* {proses: menginisialisasi Garis L dengan titik awal (0,0) dan titik akhir (1,1)} */
void makeGaris0(Garis *L);

/* function gradien(L:GARIS) -> real */
/* {mengembalikan gradien garis L} */
float gradien(Garis L);

/* procedure persamaanGaris(GARIS) */
/* {menampilkan persamaan garis L dalam bentuk y = mx + c} */
void persamaanGaris(Garis L);

/* function isHorizontal(GARIS) -> boolean */
/* {mengembalikan true jika garis horizontal (ordinat kedua titik sama)} */
boolean isHorizontal(Garis L);

/* *** Kelompok operasi lain *** */
/* function HslGeser (L: GARIS, DX, DY:integer) -> GARIS */
/* {Menghasilkan salinan L yang titik awal dan akhirnya digeser sejauh DX dan DY} */
Garis hslGeser(Garis L, int DX, int DY);

/* function MirrorOf (L: GARIS, SbX, SbY:boolean) -> GARIS */
/* {Menghasilkan salinan L yang dicerminkan tergantung nilai SbX dan SBY} */
Garis mirrorOf(Garis L, boolean SbX, boolean SbY);

/* function Panjang (L:GARIS) -> real */
/* {Menghitung panjang garis L} */
float panjang(Garis L);

/* function Arah (L:GARIS) -> real */
/* {Menghitung arah dari garis L (sudut dalam derajat yang dibentuk dengan Sumbu X+)} */
float arah(Garis L);

/* function SudutGaris (L, L1:GARIS) -> real */
/* {Menghasilkan sudut perpotongan antara L dengan L1} */
float sudutGaris(Garis L, Garis L1);

/* procedure Geser ( Input/Output L:GARIS, Input DeltaX, DeltaY: integer) */
/* {I.S. L terdefinisi} */
/* {F.S. L digeser sebesar DeltaX dan ordinatnya sebesar DeltaY} */
void geserGaris(Garis *L, int DeltaX, int DeltaY);

/* procedure Mirror (Input/Output L:GARIS, Input SbX, SbY:boolean) */
/* {I.S. L terdefinisi} */ 
/* {F.S. L dicerminkan tergantung nilai SbX atau SBY} */
void mirrorGaris(Garis *L, boolean SbX, boolean SbY);

/* procedure Putar (Input/Output L:GARIS, Input Sudut: real) */
/* {I.S. L terdefinisi} */ 
/* {F.S. L diputar sebesar (Sudut) derajat} */
void putarGaris(Garis *L, float Sudut);

#endif