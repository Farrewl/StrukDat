/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus*/
/* Tanggal : 28 Oktober 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	if ( P != NIL ) {
		next(P) = NIL;
		free(P); //memori elemen dikembalikan ke sistem
	}
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L) {
	//kamus lokal

	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L) {
	//kamus lokal

	//algoritma
	if (First(L) == NIL) {
		return true;
	} 
	else {
		return false;
	}
}

/*********** OPERATORS ***********/

/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List1 L) {
	//kamus lokal 
	address P;
	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != NIL );
	}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L) {
	//kamus lokal
	address P;
	int n;
	//algoritma
	n = 0;
	P = First(L);
	while (P != NIL) {
		n = n + 1;
		P = next(P);
	}
	return n;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ) {
	//kamus lokal
	address P;
	//algoritma
	P = Alokasi(V);
	if (P != NIL) {
		next(P) = First(*L);
		First(*L) = P;
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ) {
	//kamus lokal
	address P;
	address Last;
	//algoritma
	P = Alokasi(V);
	if (P != NIL) {
		if (First(*L) == NIL) { //list kosong
			First(*L) = P;
		} 
		else { //cari elemen terakhir
			Last = First(*L);
			while (next(Last) != NIL) {
				Last = next(Last);
			}
			next(Last) = P;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V) {
	//kamus lokal
	address P;
	//algoritma
	*V = '#';
	if (First(*L) != NIL) {
		P = First(*L);
		*V = info(P);
		First(*L) = next(P);
		Dealokasi(P);
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V) {
	//kamus lokal
	address P;
	address Q;
	//algoritma
	*V = '#';
	if (First(*L) != NIL) {
		if (next(First(*L)) == NIL) { //list hanya berisi 1 elemen
			P = First(*L);
			First(*L) = NIL;
		} 
		else { //list berisi lebih dari 1 elemen
			Q = First(*L);
			P = next(Q);
			while (next(P) != NIL) {
				Q = P;
				P = next(P);
			}
			next(Q) = NIL;
		}
		*V = info(P);
		Dealokasi(P);
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A) {
	//kamus lokal
	address P;
	//algoritma
	*A = NIL;
	P = First(L);
	while (P != NIL && info(P) != X) {
		P = next(P);
	}
	*A = P;
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y) {
	//kamus lokal
	address P;
	//algoritma
	P = First(*L);
	while (P != NIL && info(P) != X) {
		P = next(P);
	}
	if (P != NIL) { //X ditemukan
		info(P) = Y;
	}
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountKonsonan(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountKonsonan(List1 L, infotype X) {
	//kamus lokal
	address P;
	int n;
	//algoritma
	n = 0;
	P = First(L);
	while (P != NIL) {
		//hanya huruf yang dihitung
		if (((info(P) >= 'a') && (info(P) <= 'z')) ||
		    ((info(P) >= 'A') && (info(P) <= 'Z'))) {
			//huruf yang bukan vokal berarti konsonan
			if ((info(P) != 'a') && (info(P) != 'e') && (info(P) != 'i') &&
			    (info(P) != 'o') && (info(P) != 'u') &&
			    (info(P) != 'A') && (info(P) != 'E') && (info(P) != 'I') &&
			    (info(P) != 'O') && (info(P) != 'U')) {
				n = n + 1;
			}
		}
		P = next(P);
	}
	return n;
}

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X) {
	//kamus lokal
	address P;
	int n;
	//algoritma
	n = 0;
	P = First(L);
	while (P != NIL) {
		if (info(P) == X) {
			n = n + 1;
		}
		P = next(P);
	}
	return n;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X) {
	//kamus lokal
	int n;
	int banyak;
	//algoritma
	n = NbElm(L);
	banyak = CountX(L, X);
	if (n == 0) {
		return 0.0;
	} else {
		return (float) banyak / (float) n;
	}
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X) {
	//kamus lokal
	address P;
	int pos;
	//algoritma
	pos = 0;
	P = First(L);
	while (P != NIL) {
		pos = pos + 1;
		if (info(P) == X) {
			printf("\nElemen %c ada pada posisi ke-%d", X, pos);
		}
		P = next(P);
	}
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y) {
	//kamus lokal
	address P;
	//algoritma
	P = First(*L);
	while (P != NIL) {
		if (info(P) == X) {
			info(P) = Y;
		}
		P = next(P);
	}
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ) {
	//kamus lokal
	address P;
	address Q;
	//algoritma
	P = Alokasi(VA);
	if (P != NIL) {
		if (First(*L) == NIL) { //list kosong
			First(*L) = P;
		} else {
			Q = First(*L);
			while (Q != NIL && info(Q) != V) {
				Q = next(Q);
			}
			if (Q == NIL) { //V tidak ditemukan
				Dealokasi(P);
			} 
			else { //sisipkan setelah Q
				next(P) = next(Q);
				next(Q) = P;
			}
		}
	}
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','b','u'} menjadi {'u','b','i'} }*/
void Invers(List1 *L) {
	//kamus lokal
	address P;
	address Q;
	address R;
	//algoritma
	P = First(*L);
	Q = NIL;
	while (P != NIL) {
		R = next(P);   //simpan elemen setelahnya
		next(P) = Q;   //simpan elemen sebelumnya
		Q = P;
		P = R;
	}
	First(*L) = Q;
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L) {
	//kamus lokal
	address P;
	address Q;
	infotype M;
	int max;
	int c;
	//algoritma
	M = '#';
	max = 0;
	P = First(L);
	while (P != NIL) {
		//hitung kemunculan info(P)
		c = 0;
		Q = First(L);
		while (Q != NIL) {
			if (info(Q) == info(P)) {
				c = c + 1;
			}
			Q = next(Q);
		}
		if (c > max) {
			max = c;
			M = info(P);
		}
		P = next(P);
	}
	return M;
}

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L) {
	//kamus lokal
	address P;
	address Q;
	int max;
	int c;
	//algoritma
	max = 0;
	P = First(L);
	while (P != NIL) {
		//hitung kemunculan info(P)
		c = 0;
		Q = First(L);
		while (Q != NIL) {
			if (info(Q) == info(P)) {
				c = c + 1;
			}
			Q = next(Q);
		}
		if (c > max) {
			max = c;
		}
		P = next(P);
	}
	return max;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L) {
	//kamus lokal
	address P;
	//algoritma
	CreateList(L);
	//salin L1 ke L
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L, info(P));
		P = next(P);
	}
	//sambung isi L2
	P = First(L2);
	while (P != NIL) {
		InsertVLast(L, info(P));
		P = next(P);
	}
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L bagi dua, kelebihan 1 elemen ke L1}*/
void SplitList(List1 L, List1 *L1, List1 *L2) {
	//kamus lokal
	address P;
	int n;
	int i;
	int batas;
	//algoritma
	CreateList(L1);
	CreateList(L2);
	n = NbElm(L);
	batas = (n + 1) / 2; //kelebihan 1 elemen masuk ke L1
	i = 0;
	P = First(L);
	while (P != NIL) {
		i = i + 1;
		if (i <= batas) {
			InsertVLast(L1, info(P));
		} 
		else {
			InsertVLast(L2, info(P));
		}
		P = next(P);
	}
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1, dengan first berbeda alamat}*/
void CopyList(List1 L1, List1 *L2) {
	//kamus lokal
	address P;
	//algoritma
	CreateList(L2);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L2, info(P));
		P = next(P);
	}
}
