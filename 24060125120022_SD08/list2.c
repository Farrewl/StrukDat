/* File : list2.c */
/* Deskripsi : realisasi body ADT list berkait sirkular representasi fisik pointer */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus */
/* Tanggal : 2 November 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = (address) malloc(sizeof(Elm));
    if (P != NIL) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi(address *P) {
    /* Kamus Lokal */

    /* Algoritma */
    if (P != NIL && *P != NIL) {
        free(*P);
        *P = NIL;
    }
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList(List2 *L) {
    /* Kamus Lokal */

    /* Algoritma */
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List2 L) {
    /* Kamus Lokal */

    /* Algoritma */
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm(List2 L) {
    /* Kamus Lokal */

    /* Algoritma */
    return (First(L) != NIL && next(First(L)) == First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            printf("%c ", info(P));
            P = next(P);
        } while (P != First(L));
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    /* Kamus Lokal */
    address P;
    int i;
    /* Algoritma */
    i = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            i++;
            P = next(P);
        } while (P != First(L));
    }
    return i;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V) {
    /* Kamus Lokal */
    address P, Akhir;
    /* Algoritma */
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        } 
        else {
            Akhir = First(*L);
            while (next(Akhir) != First(*L)) {
                Akhir = next(Akhir);
            }
            next(P) = First(*L);
            First(*L) = P;
            next(Akhir) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V) {
    /* Kamus Lokal */
    address P, Akhir;
    /* Algoritma */
    if (IsEmptyList(*L)) {
        InsertVFirst(L, V);
    } 
    else {
        P = Alokasi(V);
        if (P != NIL) {
            Akhir = First(*L);
            while (next(Akhir) != First(*L)) {
                Akhir = next(Akhir);
            }
            next(P) = First(*L);
            next(Akhir) = P;
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    /* Kamus Lokal */
    address P;
    boolean Ketemu;
    /* Algoritma */
    *A = NIL;
    if (!IsEmptyList(L)) {
        P = First(L);
        Ketemu = 0;
        do {
            if (info(P) == X && !Ketemu) {
                *A = P;
                Ketemu = 1;
            }
            P = next(P);
        } while (P != First(L) && !Ketemu);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    SearchX(*L, X, &P);
    if (P != NIL) {
        info(P) = Y;
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    /* Kamus Lokal */
    address Seb, P, NextP, Akhir;
    /* Algoritma */
    if (!IsEmptyList(*L) && !IsOneElm(*L)) {
        Akhir = First(*L);
        Seb = First(*L);
        P = next(First(*L));
        do {
            NextP = next(P);
            next(P) = Seb;
            Seb = P;
            P = NextP;
        } while (P != First(*L));
        next(Akhir) = Seb;
        First(*L) = Seb;
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    /* Kamus Lokal */
    address P, Akhir;
    /* Algoritma */
    if (IsEmptyList(*L)) {
        *V = '#';
    } 
    else if (IsOneElm(*L)) {
        P = First(*L);
        *V = info(P);
        First(*L) = NIL;
        Dealokasi(&P);
    } 
    else {
        P = First(*L);
        *V = info(P);
        Akhir = First(*L);
        while (next(Akhir) != First(*L)) {
            Akhir = next(Akhir);
        }
        First(*L) = next(P);
        next(Akhir) = First(*L);
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
    /* Kamus Lokal */
    address P, Seb;
    /* Algoritma */
    if (IsEmptyList(*L)) {
        *V = '#';
    } 
    else if (IsOneElm(*L)) {
        DeleteVFirst(L, V);
    } 
    else {
        Seb = NIL;
        P = First(*L);
        while (next(P) != First(*L)) {
            Seb = P;
            P = next(P);
        }
        *V = info(P);
        next(Seb) = First(*L);
        Dealokasi(&P);
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong, X terdefinisi }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    /* Kamus Lokal */
    address P, Seb, Akhir;
    boolean Ketemu;
    /* Algoritma */
    if (!IsEmptyList(*L)) {
        P = First(*L);
        Seb = NIL;
        Ketemu = 0;
        do {
            if (info(P) == X) {
                Ketemu = 1;
            } 
            else {
                Seb = P;
                P = next(P);
            }
        } while (P != First(*L) && !Ketemu);

        if (Ketemu) {
            if (IsOneElm(*L)) {
                First(*L) = NIL;
            } 
            else if (P == First(*L)) {
                Akhir = First(*L);
                while (next(Akhir) != First(*L)) {
                    Akhir = next(Akhir);
                }
                First(*L) = next(P);
                next(Akhir) = First(*L);
            } 
            else {
                next(Seb) = next(P);
            }
            Dealokasi(&P);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    /* Kamus Lokal */
    address P;
    int Hit;
    /* Algoritma */
    Hit = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                Hit++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return Hit;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
    /* Kamus Lokal */
    int Total;
    /* Algoritma */
    Total = NbElm(L);
    if (Total == 0) {
        return 0.0;
    }
    return (float) CountX(L, X) / Total;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    /* Kamus Lokal */
    address P;
    int Hit;
    char C;
    /* Algoritma */
    Hit = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            C = info(P);
            if (C=='A'||C=='I'||C=='U'||C=='E'||C=='O'||C=='a'||C=='i'||C=='u'||C=='e'||C=='o') {
                Hit++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return Hit;
}

/*function CountAU(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf A yang langsung diikuti huruf U dalam list L}*/
int CountAU(List2 L) {
    /* Kamus Lokal */
    address P;
    int Hit;
    /* Algoritma */
    Hit = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if ((info(P) == 'A' || info(P) == 'a') && (info(next(P)) == 'U' || info(next(P)) == 'u')) {
                Hit++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return Hit;
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    /* Kamus Lokal */
    address P;
    int Pos;
    boolean Ada;
    /* Algoritma */
    if (IsEmptyList(L)) {
        printf("0");
    } else {
        P = First(L);
        Pos = 1;
        Ada = 0;
        do {
            if (info(P) == X) {
                if (Ada) {
                    printf(",");
                }
                printf("%d", Pos);
                Ada = 1;
            }
            Pos++;
            P = next(P);
        } while (P != First(L));
        if (!Ada) {
            printf("0");
        }
    }
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    /* Kamus Lokal */
    address P, Pt;
    /* Algoritma */
    SearchX(*L, X, &Pt);
    if (Pt != NIL) {
        P = Alokasi(V);
        if (P != NIL) {
            next(P) = next(Pt);
            next(Pt) = P;
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    /* Kamus Lokal */
    address P, Pt, Seb;
    /* Algoritma */
    SearchX(*L, X, &Pt);
    if (Pt != NIL) {
        if (Pt == First(*L)) {
            InsertVFirst(L, V);
        } else {
            Seb = First(*L);
            while (next(Seb) != Pt) {
                Seb = next(Seb);
            }
            P = Alokasi(V);
            if (P != NIL) {
                next(P) = Pt;
                next(Seb) = P;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    /* Kamus Lokal */
    address Pt, Pdel;
    /* Algoritma */
    *V = '#';
    SearchX(*L, X, &Pt);
    if (Pt != NIL) {
        if (IsOneElm(*L)) {
            DeleteVFirst(L, V);
        } else {
            Pdel = next(Pt);
            *V = info(Pdel);
            if (Pdel == First(*L)) {
                First(*L) = next(Pdel);
            }
            next(Pt) = next(Pdel);
            Dealokasi(&Pdel);
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    /* Kamus Lokal */
    address Pt, Seb, Pdel;
    /* Algoritma */
    *V = '#';
    SearchX(*L, X, &Pt);
    if (Pt != NIL) {
        if (IsOneElm(*L)) {
            DeleteVFirst(L, V);
        } else {
            Seb = First(*L);
            while (next(next(Seb)) != Pt) {
                Seb = next(Seb);
            }
            Pdel = next(Seb);
            *V = info(Pdel);
            if (Pdel == First(*L)) {
                First(*L) = Pt;
            }
            next(Seb) = Pt;
            Dealokasi(&Pdel);
        }
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
    /* Kamus Lokal */
    address Pt;
    /* Algoritma */
    SearchX(*L, X, &Pt);
    while (Pt != NIL && !IsEmptyList(*L)) {
        DeleteX(L, X);
        SearchX(*L, X, &Pt);
    }
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
    /* Kamus Lokal */
    address P;
    char Mod;
    int Maks, Hit;
    /* Algoritma */
    Mod = '#';
    Maks = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            Hit = CountX(L, info(P));
            if (Hit > Maks) {
                Maks = Hit;
                Mod = info(P);
            }
            P = next(P);
        } while (P != First(L));
    }
    return Mod;
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
    /* Kamus Lokal */
    char Mod;
    /* Algoritma */
    if (IsEmptyList(L)) {
        return 0;
    }
    Mod = Modus(L);
    return CountX(L, Mod);
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    CreateList(L);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }
    if (!IsEmptyList(L2)) {
        P = First(L2);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
    /* Kamus Lokal */
    address P;
    int Total, Tengah, Hit;
    /* Algoritma */
    CreateList(L1);
    CreateList(L2);
    if (!IsEmptyList(L)) {
        Total = NbElm(L);
        Tengah = Total / 2;
        P = First(L);
        Hit = 1;
        do {
            if (Hit <= Tengah) {
                InsertVLast(L1, info(P));
            } else {
                InsertVLast(L2, info(P));
            }
            Hit++;
            P = next(P);
        } while (P != First(L));
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    CreateList(L2);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}
