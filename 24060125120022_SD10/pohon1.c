/* File : pohon1.c */
/* Deskripsi : realisasi body ADT bintree berkait representasi fisik pointer */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus */
/* Tanggal : 16 November 2025 */

#include "pohon1.h"

/****************** Manajemen Memori ******************/
/* function AlokasiTree( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;

    //algoritma
    P = (bintree) malloc(sizeof(node));
    if (P != NIL) { //ruang memori tersedia
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

/* procedure DealokasiTree (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void DealokasiTree (bintree *P) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        left(*P) = NIL;
        right(*P) = NIL;
        free(*P); //memori elemen dikembalikan ke sistem
        *P = NIL;
    }
}

/********** PEMBUATAN bintree ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;

    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) { //alokasi berhasil
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
    //kamus lokal

    //algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
    //kamus lokal

    //algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree P kosong} */
boolean IsEmptyTree (bintree P) {
    //kamus lokal
    boolean kosong;

    //algoritma
    if (P == NIL) {
        kosong = true;
    } else {
        kosong = false;
    }
    return kosong;
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
    //kamus lokal
    boolean daun;

    //algoritma
    if (P == NIL) {
        daun = false;
    } else if (left(P) == NIL && right(P) == NIL) {
        daun = true;
    } else {
        daun = false;
    }
    return daun;
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
    //kamus lokal
    boolean biner;

    //algoritma
    if (P == NIL) {
        biner = false;
    } else if (left(P) != NIL && right(P) != NIL) {
        biner = true;
    } else {
        biner = false;
    }
    return biner;
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
    //kamus lokal
    boolean unerLeft;

    //algoritma
    if (P == NIL) {
        unerLeft = false;
    } else if (left(P) != NIL && right(P) == NIL) {
        unerLeft = true;
    } else {
        unerLeft = false;
    }
    return unerLeft;
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
    //kamus lokal
    boolean unerRight;

    //algoritma
    if (P == NIL) {
        unerRight = false;
    } else if (left(P) == NIL && right(P) != NIL) {
        unerRight = true;
    } else {
        unerRight = false;
    }
    return unerRight;
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. P terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
void PrintPrefix(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(", info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
    //kamus lokal
    int jumlah;
    int jumlahKiri, jumlahKanan;

    //algoritma
    if (P == NIL) {
        jumlah = 0;
    } else {
        jumlahKiri = NbElm(left(P));
        jumlahKanan = NbElm(right(P));
        jumlah = 1 + jumlahKiri + jumlahKanan;
    }
    return jumlah;
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
    //kamus lokal
    int jumlah;
    int jumlahKiri, jumlahKanan;

    //algoritma
    if (P == NIL) {
        jumlah = 0;
    } else if (IsDaun(P)) {
        jumlah = 1;
    } else {
        jumlahKiri = NbDaun(left(P));
        jumlahKanan = NbDaun(right(P));
        jumlah = jumlahKiri + jumlahKanan;
    }
    return jumlah;
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
    //kamus lokal
    int maksimal;

    //algoritma
    if (a > b) {
        maksimal = a;
    } else {
        maksimal = b;
    }
    return maksimal;
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
    //kamus lokal
    int hasil;
    int tinggiKiri, tinggiKanan;

    //algoritma
    if (P == NIL) {
        hasil = -1;
    } else if (IsDaun(P)) {
        hasil = 0;
    } else {
        tinggiKiri = Tinggi(left(P));
        tinggiKanan = Tinggi(right(P));
        hasil = 1 + max2(tinggiKiri, tinggiKanan);
    }
    return hasil;
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
    //kamus lokal
    boolean ketemu;

    //algoritma
    if (P == NIL) {
        ketemu = false;
    } else if (info(P) == X) {
        ketemu = true;
    } else {
        //cari ke subpohon kiri dulu, baru ke subpohon kanan
        ketemu = SearchX(left(P), X);
        if (!ketemu) {
            ketemu = SearchX(right(P), X);
        }
    }
    return ketemu;
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. P, X, Y terdefinisi }
{ F.S. P tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        if (info(*P) == X) { //elemen X ditemukan
            info(*P) = Y;
        }
        UpdateX(&(left(*P)), X, Y);
        UpdateX(&(right(*P)), X, Y);
    }
}

/*********** SOAL TAMBAHAN *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
    //kamus lokal
    int jumlah;
    int jumlahKiri, jumlahKanan;

    //algoritma
    if (P == NIL) {
        jumlah = 0;
    } else {
        jumlahKiri = CountX(left(P), X);
        jumlahKanan = CountX(right(P), X);
        if (info(P) == X) {
            jumlah = 1 + jumlahKiri + jumlahKanan;
        } else {
            jumlah = jumlahKiri + jumlahKanan;
        }
    }
    return jumlah;
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P) {
    //kamus lokal
    boolean condong;

    //algoritma
    if (P == NIL) {
        condong = true;
    } else if (IsDaun(P)) {
        condong = true;
    } else if (IsUnerLeft(P)) {
        condong = IsSkewLeft(left(P));
    } else {
        condong = false;
    }
    return condong;
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P) {
    //kamus lokal
    boolean condong;

    //algoritma
    if (P == NIL) {
        condong = true;
    } else if (IsDaun(P)) {
        condong = true;
    } else if (IsUnerRight(P)) {
        condong = IsSkewRight(right(P));
    } else {
        condong = false;
    }
    return condong;
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. P terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c", info(P));
        if (left(P) != NIL || right(P) != NIL) { //P bukan daun
            printf("(");
            if (left(P) != NIL) {
                PrintPrefixRingkas(left(P));
            } else {
                printf("()");
            }
            printf(",");
            if (right(P) != NIL) {
                PrintPrefixRingkas(right(P));
            } else {
                printf("()");
            }
            printf(")");
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
    //kamus lokal
    int level;
    int levelKiri, levelKanan;

    //algoritma
    if (P == NIL) {
        level = -1; //X tidak ditemukan
    } else if (info(P) == X) {
        level = 1;
    } else {
        levelKiri = LevelX(left(P), X);
        if (levelKiri > 0) { //X ada di subpohon kiri
            level = 1 + levelKiri;
        } else {
            levelKanan = LevelX(right(P), X);
            if (levelKanan > 0) { //X ada di subpohon kanan
                level = 1 + levelKanan;
            } else {
                level = -1; //X tidak ditemukan
            }
        }
    }
    return level;
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T) {
    //kamus lokal
    int jumlah;
    int jumlahKiri, jumlahKanan;

    //algoritma
    if (P == NIL) {
        jumlah = 0;
    } else if (T <= 0) {
        jumlah = 0;
    } else if (T == 1) {
        jumlah = 1;
    } else {
        jumlahKiri = CountLevel(left(P), T - 1);
        jumlahKanan = CountLevel(right(P), T - 1);
        jumlah = jumlahKiri + jumlahKanan;
    }
    return jumlah;
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. P terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        //tidak ada yang ditampilkan
    } else if (N <= 0) {
        //level tidak valid
    } else if (N == 1) {
        printf("%c ", info(P));
    } else {
        PrintLevel(left(P), N - 1);
        PrintLevel(right(P), N - 1);
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
    //kamus lokal
    infotype hasil;

    //algoritma
    if (P == NIL) {
        hasil = '#'; //pohon kosong
    } else if (IsDaun(P)) {
        hasil = info(P);
    } else if (left(P) != NIL) {
        //telusuri ke kiri terus
        hasil = GetDaunTerkiri(left(P));
    } else {
        //anak kiri kosong, ambil dari subpohon kanan
        hasil = GetDaunTerkiri(right(P));
    }
    return hasil;
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X) {
    //kamus lokal
    int jumlahElemen;
    int jumlahX;
    float rasio;

    //algoritma
    jumlahElemen = NbElm(P);
    if (jumlahElemen == 0) {
        rasio = 0.0f;
    } else {
        jumlahX = CountX(P, X);
        rasio = (float) jumlahX / jumlahElemen;
    }
    return rasio;
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P) {
    //kamus lokal
    char huruf;
    int jumlah;

    //algoritma
    if (P == NIL) {
        jumlah = 0;
    } else {
        huruf = info(P);
        if (huruf == 'A' || huruf == 'a' ||
            huruf == 'I' || huruf == 'i' ||
            huruf == 'U' || huruf == 'u' ||
            huruf == 'E' || huruf == 'e' ||
            huruf == 'O' || huruf == 'o') { //huruf vokal
            jumlah = 1 + CountVocal(left(P)) + CountVocal(right(P));
        } else {
            jumlah = CountVocal(left(P)) + CountVocal(right(P));
        }
    }
    return jumlah;
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P) {
    //kamus lokal
    char huruf;

    //algoritma
    if (P != NIL) {
        huruf = info(P);
        if (huruf == 'A' || huruf == 'a' ||
            huruf == 'I' || huruf == 'i' ||
            huruf == 'U' || huruf == 'u' ||
            huruf == 'E' || huruf == 'e' ||
            huruf == 'O' || huruf == 'o') { //huruf vokal
            printf("%c ", huruf);
        }
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree P}*/
int CountConsonant(bintree P) {
    //kamus lokal
    char huruf;
    int konsonan;
    int jumlah;

    //algoritma
    if (P == NIL) {
        jumlah = 0;
    } else {
        huruf = info(P);
        konsonan = 0;
        if ((huruf >= 'A' && huruf <= 'Z') || (huruf >= 'a' && huruf <= 'z')) { //huruf alfabet
            if (!(huruf == 'A' || huruf == 'a' ||
                  huruf == 'I' || huruf == 'i' ||
                  huruf == 'U' || huruf == 'u' ||
                  huruf == 'E' || huruf == 'e' ||
                  huruf == 'O' || huruf == 'o')) { //bukan vokal berarti konsonan
                konsonan = 1;
            }
        }
        jumlah = konsonan + CountConsonant(left(P)) + CountConsonant(right(P));
    }
    return jumlah;
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P) {
    //kamus lokal
    char huruf;
    boolean konsonan;

    //algoritma
    if (P != NIL) {
        huruf = info(P);
        konsonan = false;
        if ((huruf >= 'A' && huruf <= 'Z') || (huruf >= 'a' && huruf <= 'z')) { //huruf alfabet
            if (!(huruf == 'A' || huruf == 'a' ||
                  huruf == 'I' || huruf == 'i' ||
                  huruf == 'U' || huruf == 'u' ||
                  huruf == 'E' || huruf == 'e' ||
                  huruf == 'O' || huruf == 'o')) { //bukan vokal berarti konsonan
                konsonan = true;
            }
        }
        if (konsonan) {
            printf("%c ", huruf);
        }
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

/*procedure HitungFrekuensi(input P:bintree, input/output frekuensi: array of integer)
{ I.S.: P terdefinisi, frekuensi terdefinisi
  F.S.: frekuensi berisi banyaknya kemunculan tiap karakter di P }
{ Proses: menambah frekuensi tiap info node ke array frekuensi }*/
static void HitungFrekuensi(bintree P, int frekuensi[]) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        frekuensi[(unsigned char) info(P)]++;
        HitungFrekuensi(left(P), frekuensi);
        HitungFrekuensi(right(P), frekuensi);
    }
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree P}*/
char Modus(bintree P) {
    //kamus lokal
    int frekuensi[256];
    int frekuensiMaks;
    char hurufModus;
    int i;

    //algoritma
    if (P == NIL) {
        hurufModus = '#';
    } else {
        for (i = 0; i < 256; i++) {
            frekuensi[i] = 0;
        }
        HitungFrekuensi(P, frekuensi);
        frekuensiMaks = 0;
        hurufModus = '#';
        for (i = 0; i < 256; i++) {
            if (frekuensi[i] > frekuensiMaks) {
                frekuensiMaks = frekuensi[i];
                hurufModus = (char) i;
            }
        }
    }
    return hurufModus;
}
