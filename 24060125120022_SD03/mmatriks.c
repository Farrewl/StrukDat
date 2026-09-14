/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 7 September 2026 */
/***********************************/

#include <stdio.h>
#include "matriks.h"

int main() {
    /*kamus*/
    Matriks M1, M2, M3;

    /*algoritma*/
    initMatriks(&M1);
    printf("isEmptyMatriks\n");
    printf("M1 kosong? %d\n", isEmptyMatriks(M1));
    viewMatriks(M1);

    printf("\nisiMatriksIdentitas 3x3\n");
    isiMatriksIdentitas(&M2, 3);
    viewMatriks(M2);

    printf("\nisiMatriksRandom 4x4\n");
    isiMatriksRandom(&M3, 4, 4);
    viewMatriks(M3);

    printf("\naddX (M3, 99, 1, 1)\n");
    addX(&M3, 99, 1, 1);
    viewMatriks(M3);

    printf("\ndelX (M3, 99)\n");
    delX(&M3, 99);
    viewMatriks(M3);

    printf("\naddMatriks (M3 + M3)\n");
    viewMatriks(addMatriks(M3, M3));

    printf("\nsubMatriks (M3 - M3)\n");
    viewMatriks(subMatriks(M3, M3));

    printf("\nkaliMatriks (M3 * M3)\n");
    viewMatriks(kaliMatriks(M3, M3));

    printf("\nkaliSkalarMatriks (M3 * 2)\n");
    viewMatriks(kaliSkalarMatriks(M3, 2));

    printf("\nTranspose\n");
    transposeMatriks(&M2);
    viewMatriks(M2);

    printf("\ngetTransposeMatriks\n");
    viewMatriks(getTransposeMatriks(M3));

    printf("\nThresholding T=100\n");
    viewMatriks(thresholding(M3, 100));

    printf("\ncitraNegatif\n");
    viewMatriks(citraNegatif(M3));

    printf("\nbrightness (+50)\n");
    viewMatriks(brightness(M3, 50));

    printf("\ngrayscale (M3, M3, M3)\n");
    viewMatriks(grayscale(M3, M3, M3));

    printf("\ntranslasi (dx=1, dy=1)\n");
    viewMatriks(translasi(M3, 1, 1));

    printf("\nflipHorizontal\n");
    viewMatriks(flipHorizontal(M3));

    printf("\nflipVertical\n");
    viewMatriks(flipVertical(M3));

    printf("\nPadding (n=1)\n");
    viewMatriks(Padding(M3, 1));

    printf("\nmaxPooling (size=2)\n");
    viewMatriks(maxPooling(M3, 2));

    printf("\navgPooling (size=2)\n");
    viewMatriks(avgPooling(M3, 2));

    printf("\nkonvolusi (M3 dengan M3)\n");
    viewMatriks(konvolusi(M3, M3));

    return 0;
}
