/* Program   : mbrowser.c */
/* Deskripsi : file DRIVER simulasi browser dengan 2 stack */
#include <stdio.h>
#include "tstack.h"

int main() 
{	Tstack Undo, Redo;
	char E; 
	int N, kode;
	createStack(&Undo); 
	createStack(&Redo);
	for (;;) {
		printf("\n1:Push, 2:Back, 3:Forward, 4:Exit. Kode: ");
		scanf("%d", &kode);
		switch (kode) {
			case 1:
				printf("Jml: "); 
				scanf("%d", &N);
				for (int i = 0; i < N; i++) {
					scanf(" %c", &E); 
					push(&Undo, E);
				}
				viewStack(Undo);
				break;
			case 2:
				if (!isEmptyStack(Undo)) {
					char popped; 
					pop(&Undo, &popped); 
					push(&Redo, popped);
					viewStack(Undo);
				}
				break;
			case 3:
				if (!isEmptyStack(Redo)) {
					char popped; 
					pop(&Redo, &popped); 
					push(&Undo, popped);
					viewStack(Undo);
				}
				break;
			case 4: return 0;
		}
	}
}