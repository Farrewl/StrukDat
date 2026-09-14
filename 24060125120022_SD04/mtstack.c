/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 14 September 2026 */
/***********************************/ 

#include <stdio.h>
#include "tstack.h"

int main() 
{	/* kamus main */
	Tstack A; 
	char X;
	
	/* algoritma */
	createStack( &A );
	
	push(&A, 'A');
	push(&A, 'B');
	push(&A, 'C');
	
	viewStack(A);
	
	printStack(A);
	
	pop(&A, &X);
	
	viewStack(A);
	
	char kata[30] = "katak";
	if (isPalindrom(kata)) {
		printf("Kata '%s' adalah palindrom.\n", kata);
	} else {
		printf("Kata '%s' bukan palindrom.\n", kata);
	}
	
	return 0;
}
