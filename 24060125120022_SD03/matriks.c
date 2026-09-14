/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 7 September 2026 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"
#include "boolean.h"

/* KONSTRUKTOR */		
void initMatriks(Matriks *M) {
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 0; i <= 10; i++) {
        for (j = 0; j <= 10; j++) {
            M->cell[i][j] = -999;
        }
    }
    M->nbaris = 0;
    M->nkolom = 0;
}

/* SELEKTOR */
int getNBaris(Matriks M) {
    return M.nbaris;
}

int getNKolom(Matriks M) {
    return M.nkolom;
}

/* PREDIKAT */
boolean isEmptyMatriks(Matriks M) {
    return (M.nbaris == 0 && M.nkolom == 0);
}

boolean isFullMatriks(Matriks M) {
    return (M.nbaris == 10 && M.nkolom == 10);
}

/* MUTATOR */
void addX(Matriks *M, int X, int baris, int kolom) {
    if (baris >= 1 && baris <= 10 && kolom >= 1 && kolom <= 10) {
        M->cell[baris][kolom] = X;
        if (baris > M->nbaris) M->nbaris = baris;
        if (kolom > M->nkolom) M->nkolom = kolom;
    }
}

void delX(Matriks *M, int X) {
    
    // kamus lokal
    int i, j;
    boolean ketemu = false;

    // algoritma
    for (i = 1; i <= M->nbaris && !ketemu; i++) {
        for (j = 1; j <= M->nkolom && !ketemu; j++) {
            if (M->cell[i][j] == X) {
                M->cell[i][j] = -999;
                ketemu = true;
            }
        }
    }
}

void isiMatriksRandom(Matriks *M, int x, int y) {
    
    // kamus lokal
    int i, j;

    // algoritma
    if (x <= 10 && y <= 10) {
        M->nbaris = x;
        M->nkolom = y;
        srand(time(NULL));
        for (i = 1; i <= x; i++) {
            for (j = 1; j <= y; j++) {
                M->cell[i][j] = rand() % 256; // 0..255 for image processing commonality
            }
        }
    }
}

void isiMatriksIdentitas(Matriks *M, int n) {
    
    // kamus lokal
    int i, j;

    // algoritma
    if (n <= 10) {
        initMatriks(M);
        M->nbaris = n;
        M->nkolom = n;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) M->cell[i][j] = 1;
                else M->cell[i][j] = 0;
            }
        }
    }
}

/* OPERASI BACA/TULIS */
void populateMatriks(Matriks *M, int x, int y) {
    
    // kamus lokal
    int i, j;

    // algoritma
    if (x <= 10 && y <= 10) {
        M->nbaris = x;
        M->nkolom = y;
        for (i = 1; i <= x; i++) {
            for (j = 1; j <= y; j++) {
                scanf("%d", &M->cell[i][j]);
            }
        }
    }
}

void printMatriks(Matriks M) {
    
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

void viewMatriks(Matriks M) {
    
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            if (M.cell[i][j] != -999) {
                printf("%d ", M.cell[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
Matriks addMatriks(Matriks M1, Matriks M2) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    if (M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom) {
        Mkeluar.nbaris = M1.nbaris;
        Mkeluar.nkolom = M1.nkolom;
        for (i = 1; i <= Mkeluar.nbaris; i++) {
            for (j = 1; j <= Mkeluar.nkolom; j++) {
                Mkeluar.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
    }
    return Mkeluar;
}

Matriks subMatriks(Matriks M1, Matriks M2) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    if (M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom) {
        Mkeluar.nbaris = M1.nbaris;
        Mkeluar.nkolom = M1.nkolom;
        for (i = 1; i <= Mkeluar.nbaris; i++) {
            for (j = 1; j <= Mkeluar.nkolom; j++) {
                Mkeluar.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
    }
    return Mkeluar;
}

Matriks kaliMatriks(Matriks M1, Matriks M2) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j, k;

    // algoritma
    initMatriks(&Mkeluar);
    if (M1.nkolom == M2.nbaris) {
        Mkeluar.nbaris = M1.nbaris;
        Mkeluar.nkolom = M2.nkolom;
        for (i = 1; i <= Mkeluar.nbaris; i++) {
            for (j = 1; j <= Mkeluar.nkolom; j++) {
                Mkeluar.cell[i][j] = 0;
                for (k = 1; k <= M1.nkolom; k++) {
                    Mkeluar.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                }
            }
        }
    }
    return Mkeluar;
}

Matriks kaliSkalarMatriks(Matriks M, int x) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nbaris;
    Mkeluar.nkolom = M.nkolom;
    for (i = 1; i <= Mkeluar.nbaris; i++) {
        for (j = 1; j <= Mkeluar.nkolom; j++) {
            Mkeluar.cell[i][j] = M.cell[i][j] * x;
        }
    }
    return Mkeluar;
}

/* OPERASI LAINNYA */
void transposeMatriks(Matriks *M) {
    Matriks temp = getTransposeMatriks(*M);
    *M = temp;
}

Matriks getTransposeMatriks(Matriks M) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nkolom;
    Mkeluar.nkolom = M.nbaris;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            Mkeluar.cell[j][i] = M.cell[i][j];
        }
    }
    return Mkeluar;
}

/* IMAGE PROCESSING */
Matriks thresholding(Matriks M, int T) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nbaris;
    Mkeluar.nkolom = M.nkolom;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            Mkeluar.cell[i][j] = (M.cell[i][j] > T ? 255 : 0);
        }
    }
    return Mkeluar;
}

Matriks citraNegatif(Matriks M) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nbaris;
    Mkeluar.nkolom = M.nkolom;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            Mkeluar.cell[i][j] = 255 - M.cell[i][j];
        }
    }
    return Mkeluar;
}

Matriks brightness(Matriks M, int b) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j, nilai;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nbaris;
    Mkeluar.nkolom = M.nkolom;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            nilai = M.cell[i][j] + b;
            if (nilai > 255) nilai = 255;
            if (nilai < 0) nilai = 0;
            Mkeluar.cell[i][j] = nilai;
        }
    }
    return Mkeluar;
}

Matriks grayscale(Matriks R, Matriks G, Matriks B) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = R.nbaris;
    Mkeluar.nkolom = R.nkolom;
    for (i = 1; i <= Mkeluar.nbaris; i++) {
        for (j = 1; j <= Mkeluar.nkolom; j++) {
            Mkeluar.cell[i][j] = (R.cell[i][j] + G.cell[i][j] + B.cell[i][j]) / 3;
        }
    }
    return Mkeluar;
}

Matriks translasi(Matriks M, int dx, int dy) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j, Ibaru, Jbaru;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nbaris;
    Mkeluar.nkolom = M.nkolom;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            Ibaru = i + dy;
            Jbaru = j + dx;
            if (Ibaru >= 1 && Ibaru <= 10 && Jbaru >= 1 && Jbaru <= 10) {
                Mkeluar.cell[Ibaru][Jbaru] = M.cell[i][j];
            }
        }
    }
    return Mkeluar;
}

Matriks flipHorizontal(Matriks M) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nbaris;
    Mkeluar.nkolom = M.nkolom;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            Mkeluar.cell[i][M.nkolom - j + 1] = M.cell[i][j];
        }
    }
    return Mkeluar;
}

Matriks flipVertical(Matriks M) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    Mkeluar.nbaris = M.nbaris;
    Mkeluar.nkolom = M.nkolom;
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            Mkeluar.cell[M.nbaris - i + 1][j] = M.cell[i][j];
        }
    }
    return Mkeluar;
}

Matriks Padding(Matriks M, int n) {
    
    // kamus lokal
    Matriks Mkeluar;
    int i, j;

    // algoritma
    initMatriks(&Mkeluar);
    if (M.nbaris + 2 * n <= 10 && M.nkolom + 2 * n <= 10) {
        Mkeluar.nbaris = M.nbaris + 2 * n;
        Mkeluar.nkolom = M.nkolom + 2 * n;
        for (i = 1; i <= Mkeluar.nbaris; i++) {
            for (j = 1; j <= Mkeluar.nkolom; j++) {
                Mkeluar.cell[i][j] = 0;
            }
        }
        for (i = 1; i <= M.nbaris; i++) {
            for (j = 1; j <= M.nkolom; j++) {
                Mkeluar.cell[i + n][j + n] = M.cell[i][j];
            }
        }
    }
    return Mkeluar;
}

Matriks maxPooling(Matriks M, int size) {
    
    // kamus lokal
    Matriks hasil;
    int i, j, x, y, max, baris_out, kolom_out;
    
    // algoritma
    initMatriks(&hasil);
    hasil.nbaris = M.nbaris / size;
    hasil.nkolom = M.nkolom / size;
    
    baris_out = 1;
    for (i = 1; i <= M.nbaris; i += size) {
        kolom_out = 1;
        for (j = 1; j <= M.nkolom; j += size) {
            max = -999;
            for (x = 0; x < size; x++) {
                for (y = 0; y < size; y++) {
                    if (i + x <= M.nbaris && j + y <= M.nkolom) {
                        if (M.cell[i + x][j + y] > max) {
                            max = M.cell[i + x][j + y];
                        }
                    }
                }
            }
            hasil.cell[baris_out][kolom_out] = max;
            kolom_out++;
        }
        baris_out++;
    }
    return hasil;
}

Matriks avgPooling(Matriks M, int size) {
    
    // kamus lokal
    Matriks hasil;
    int i, j, x, y, sum, baris_out, kolom_out;
    
    // algoritma
    initMatriks(&hasil);
    hasil.nbaris = M.nbaris / size;
    hasil.nkolom = M.nkolom / size;
    
    baris_out = 1;
    for (i = 1; i <= M.nbaris; i += size) {
        kolom_out = 1;
        for (j = 1; j <= M.nkolom; j += size) {
            sum = 0;
            for (x = 0; x < size; x++) {
                for (y = 0; y < size; y++) {
                    if (i + x <= M.nbaris && j + y <= M.nkolom) {
                        sum += M.cell[i + x][j + y];
                    }
                }
            }
            hasil.cell[baris_out][kolom_out] = sum / (size * size);
            kolom_out++;
        }
        baris_out++;
    }
    return hasil;
}

Matriks konvolusi(Matriks M, Matriks K) {
    
    // kamus lokal
    Matriks hasil;
    int i, j, x, y, sum;
    
    // algoritma
    initMatriks(&hasil);
    hasil.nbaris = M.nbaris - K.nbaris + 1;
    hasil.nkolom = M.nkolom - K.nkolom + 1;
    
    for (i = 1; i <= hasil.nbaris; i++) {
        for (j = 1; j <= hasil.nkolom; j++) {
            sum = 0;
            for (x = 1; x <= K.nbaris; x++) {
                for (y = 1; y <= K.nkolom; y++) {
                    sum += M.cell[i + x - 1][j + y - 1] * K.cell[x][y];
                }
            }
            hasil.cell[i][j] = sum;
        }
    }
    return hasil;
}
