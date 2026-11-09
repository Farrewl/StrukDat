/* File : list3.c */
/* Deskripsi : realisasi body ADT list berkait ganda (double linked list) representasi fisik pointer */
/* NIM & Nama : 24060125120022 & Ibnu Farrel Athaillah Firdaus */
/* Tanggal : 9 November 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

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
        prev(P) = NIL;
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
    if (*P != NIL) {
        prev(*P) = NIL;
        next(*P) = NIL;
        free(*P);
        *P = NIL;
    }
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
    {I.S.: - ; F.S.: L list kosong} 
    {proses: membuat list kosong}*/
void CreateList(List3 *L) {
    /* Kamus Lokal */
    /* Algoritma */
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List3 L) {
    /* Kamus Lokal */
    /* Algoritma */
    return (First(L) == NIL);
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    if (!IsEmptyList(L)) {
        P = First(L);
        while (P != NIL) {
            printf("%c ", info(P));
            P = next(P);
        }
    }
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
    /* Kamus Lokal */
    address P;
    int cnt;
    /* Algoritma */
    cnt = 0;
    P = First(L);
    while (P != NIL) {
        cnt++;
        P = next(P);
    }
    return cnt;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
        } else {
            next(P) = First(*L);
            prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V) {
    /* Kamus Lokal */
    address P, Last;
    /* Algoritma */
    if (IsEmptyList(*L)) {
        InsertVFirst(L, V);
    } else {
        P = Alokasi(V);
        if (P != NIL) {
            Last = First(*L);
            while (next(Last) != NIL) {
                Last = next(Last);
            }
            next(Last) = P;
            prev(P) = Last;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    if (IsEmptyList(*L)) {
        *V = '#';
    } 
	else {
        P = First(*L);
        *V = info(P);
        First(*L) = next(P);
        if (First(*L) != NIL) {
            prev(First(*L)) = NIL;
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    if (IsEmptyList(*L)) {
        *V = '#';
    } else if (next(First(*L)) == NIL) {
        DeleteVFirst(L, V);
    } else {
        P = First(*L);
        while (next(P) != NIL) {
            P = next(P);
        }
        *V = info(P);
        next(prev(P)) = NIL;
        Dealokasi(&P);
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
    /* Kamus Lokal */
    address P;
    infotype dummy;
    /* Algoritma */
    SearchX(*L, X, &P);
    if (P != NIL) {
        if (P == First(*L)) {
            DeleteVFirst(L, &dummy);
        } else if (next(P) == NIL) {
            DeleteVLast(L, &dummy);
        } else {
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            Dealokasi(&P);
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
    /* Kamus Lokal */
    address P;
    boolean Ketemu;
    /* Algoritma */
    *A = NIL;
    if (!IsEmptyList(L)) {
        P = First(L);
        Ketemu = false;
        while (P != NIL && !Ketemu) {
            if (info(P) == X) {
                *A = P;
                Ketemu = true;
            } else {
                P = next(P);
            }
        }
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    SearchX(*L, X, &P);
    if (P != NIL) {
        info(P) = Y;
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
    /* Kamus Lokal */
    address P, Temp;
    /* Algoritma */
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (P != NIL) {
            Temp = next(P);
            next(P) = prev(P);
            prev(P) = Temp;
            First(*L) = P;
            P = Temp;
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
    /* Kamus Lokal */
    address P, Loc;
    /* Algoritma */
    SearchX(*L, X, &Loc);
    if (Loc != NIL) {
        if (next(Loc) == NIL) {
            InsertVLast(L, V);
        } else {
            P = Alokasi(V);
            if (P != NIL) {
                next(P) = next(Loc);
                prev(P) = Loc;
                prev(next(Loc)) = P;
                next(Loc) = P;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
    /* Kamus Lokal */
    address P, Loc;
    /* Algoritma */
    SearchX(*L, X, &Loc);
    if (Loc != NIL) {
        if (Loc == First(*L)) {
            InsertVFirst(L, V);
        } else {
            P = Alokasi(V);
            if (P != NIL) {
                next(P) = Loc;
                prev(P) = prev(Loc);
                next(prev(Loc)) = P;
                prev(Loc) = P;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
    /* Kamus Lokal */
    address Loc, P;
    /* Algoritma */
    SearchX(*L, X, &Loc);
    if (Loc != NIL && next(Loc) != NIL) {
        P = next(Loc);
        *V = info(P);
        next(Loc) = next(P);
        if (next(P) != NIL) {
            prev(next(P)) = Loc;
        }
        Dealokasi(&P);
    } else {
        *V = '#';
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
    /* Kamus Lokal */
    address Loc, P;
    /* Algoritma */
    SearchX(*L, X, &Loc);
    if (Loc != NIL && prev(Loc) != NIL) {
        P = prev(Loc);
        *V = info(P);
        if (P == First(*L)) {
            DeleteVFirst(L, V);
        } else {
            prev(Loc) = prev(P);
            next(prev(P)) = Loc;
            Dealokasi(&P);
        }
    } else {
        *V = '#';
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
    /* Kamus Lokal */
    address P;
    int i;
    /* Algoritma */
    i = 0;
    P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            i++;
        }
        P = next(P);
    }
    return i;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
    /* Kamus Lokal */
    int total, count;
    /* Algoritma */
    total = NbElm(L);
    if (total == 0) {
        return 0.0;
    }
    count = CountX(L, X);
    return (float) count / total;
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
    /* Kamus Lokal */
    address P;
    int max, c;
    /* Algoritma */
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        while (P != NIL) {
            c = CountX(L, info(P));
            if (c > max) {
                max = c;
            }
            P = next(P);
        }
    }
    return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
    /* Kamus Lokal */
    address P;
    int max, c;
    char modus;
    /* Algoritma */
    modus = '#';
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        while (P != NIL) {
            c = CountX(L, info(P));
            if (c > max) {
                max = c;
                modus = info(P);
            }
            P = next(P);
        }
    }
    return modus;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
    /* Kamus Lokal */
    address P;
    int i;
    char c;
    /* Algoritma */
    i = 0;
    P = First(L);
    while (P != NIL) {
        c = info(P);
        if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' ||
            c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            i++;
        }
        P = next(P);
    }
    return i;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
    /* Kamus Lokal */
    address P;
    int i;
    /* Algoritma */
    i = 0;
    P = First(L);
    while (P != NIL && next(P) != NIL) {
        if ((info(P) == 'N' || info(P) == 'n') && (info(next(P)) == 'G' || info(next(P)) == 'g')) {
            i++;
        }
        P = next(P);
    }
    return i;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
void SearchAllX(List3 L, infotype X) {
    /* Kamus Lokal */
    address P;
    int pos;
    boolean found;
    /* Algoritma */
    pos = 1;
    found = false;
    P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            if (found) {
                printf(",");
            }
            printf("%d", pos);
            found = true;
        }
        pos++;
        P = next(P);
    }
    if (!found) {
        printf("0");
    }
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (P != NIL) {
            if (info(P) == X) {
                DeleteX(L, X);
            }
            P = next(P);
        }
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    CreateList(L);
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
    P = First(L2);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
    /* Kamus Lokal */
    address P;
    int n, mid, i;
    /* Algoritma */
    CreateList(L1);
    CreateList(L2);
    n = NbElm(L);
    mid = n / 2;
    P = First(L);
    i = 1;
    while (P != NIL) {
        if (i <= mid) {
            InsertVLast(L1, info(P));
        } 
		else {
            InsertVLast(L2, info(P));
        }
        i++;
        P = next(P);
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
    /* Kamus Lokal */
    address P;
    /* Algoritma */
    CreateList(L2);
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}
