/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athaillah Firdaus*/
/* Tanggal   : 24 Agustus 2026*/
/***********************************/

#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	Titik T1;
	Titik T2;
	Titik P;

	//algoritma
	makeTitik(&T1, 4, 5);
	makeTitik(&T2, -99, 40);
	printf("makeTitik T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	printf("makeTitik T2 = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

	makeTitik0(&P);
	printf("makeTitik0 P = (%d, %d)\n", getAbsis(P), getOrdinat(P));

	printf("getAbsis T1 = %d\n", getAbsis(T1));
	printf("getOrdinat T1 = %d\n", getOrdinat(T1));

	setAbsis(&T1, -7);
	printf("setAbsis T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	setOrdinat(&T1, 9);
	printf("setOrdinat T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

	printf("isOrigin P = %s\n", isOrigin(P) ? "true" : "false");
	printf("isOrigin T1 = %s\n", isOrigin(T1) ? "true" : "false");

	makeTitik(&P, 3, 0);
	printf("isOnSumbuX P(%d, %d) = %s\n", getAbsis(P), getOrdinat(P), isOnSumbuX(P) ? "true" : "false");
	makeTitik(&P, 0, 4);
	printf("isOnSumbuY P(%d, %d) = %s\n", getAbsis(P), getOrdinat(P), isOnSumbuY(P) ? "true" : "false");

	printf("isEqual T1 dengan T2 = %s\n", isEqual(T1, T2) ? "true" : "false");

	geser(&T2, 100, -38);
	printf("geser T2 = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

	refleksiX(&T2);
	printf("refleksiX T2 = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	refleksiY(&T2);
	printf("refleksiY T2 = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

	dilatasi(&T1, 2.0f);
	printf("dilatasi T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

	makeTitik(&P, 0, 4);
	dilatasiX(&T1, P, 0.5f);
	printf("dilatasiX T1 = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

	printf("kuadran T1 di kuadran %d\n", kuadran(T1));
	printf("kuadran T2 di kuadran %d\n", kuadran(T2));

	return 0;
}
